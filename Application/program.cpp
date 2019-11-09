#include "program.h"
#include "statement.h"
#include "statementcreator.h"
#include "variable.h"
#include <QStringList>
#include <QDebug>

Program::Program(QString fileName)
{
    filename = fileName;
    prgmVars = new VHash();
}

Program::~Program()
{
   // delete the contained objects
   //delete prgmVars;
}


QString Program:: getFileName()
{
    return filename;
}


bool Program::compile(QString *inSrcTxt, QString *outCmplTxt, QString *errTxt)
{
    *outCmplTxt = "";
    *errTxt = "";

    qDebug()  << "file: " + filename; // To Be Removed
    qDebug()  << "inSrcTxt: " + *inSrcTxt; // To Be Removed

    //parse;
    QStringList srcList = (*inSrcTxt).split(QRegExp("\n|\r\n|\r")); //split the source text into an array of lines

    StatementCreator stmtCreator;

    for(int i = 0; i < srcList.length(); i++){
        QString line = srcList[i];
        line.replace(QRegExp("[^\\S\\r\\n]+"), " "); //replace multiple spaces and tabs with a single space

        //ignore empty lines and comments
        if (!line.trimmed().isEmpty() && !line.startsWith("#")) {

            qDebug("Line %d: %s", (i+1),qUtf8Printable(line)); // to be removed

            QString instructionType = "";

            //parse line to get instruction type
            parseInstructions(line, instructionType);

            if(instructionType != "error"){

                // create statements
                Statement *stmt = stmtCreator.Create(instructionType);

                //inject program variable enviroment
                stmt->setEnviroment(prgmVars);

                // compile statements
                stmt->compile(&line);

                //list of statements
                statements.push_back(stmt);

            } else {
                qDebug() << "error at " << line;
                // some error
            }
        }

    }

    // generate json(or xml) output
    return true;
}

//parse lines for instructions
void Program::parseInstructions(QString &line, QString &instructionStr){

    //too many : ?
    if(line.count(":") > 1){
        // throw error
    }

    //ignore spaces before :
    if(line.contains(" :")){
        line.replace(" :",":");
    }

    //check for label and extract the instruction
    if(line.contains(":")) {
        instructionStr = line.split(":")[1].trimmed().split(" ")[0];
    }else {
        instructionStr = line.split(" ")[0];
    }

    if(instructionStr == "dci"){
        instructionStr = "DciStatement";
    } else if(instructionStr == "dca"){
        instructionStr = "DcaStatement";
    } else if(instructionStr == "rdi"){
        instructionStr = "RdiStatement";
    } else if(instructionStr == "prt"){
        instructionStr = "PrtStatement";
    } else if(instructionStr == "mov"){
        instructionStr = "MovStatement";
    } else if(instructionStr == "add"){
        instructionStr = "AddStatement";
    } else if(instructionStr == "cmp"){
        instructionStr = "CmpStatement";
    } else if(instructionStr == "jls"){
        instructionStr = "JlsStatement";
    } else if(instructionStr == "jmr"){
        instructionStr = "JmrStatement";
    } else if(instructionStr == "jeq"){
        instructionStr = "JeqStatement";
    } else if(instructionStr == "jmp"){
        instructionStr = "JmpStatement";
    } else if(instructionStr == "end"){
        instructionStr = "EndStatement";
    } else {
        instructionStr = "error";
        // error
    }

}
