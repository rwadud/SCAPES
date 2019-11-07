#include "program.h"
#include "statement.h"
#include "statementfactory.h"
#include "statementcreator.h"
#include <QStringList>
#include <QDebug>
#include <QSet>

Program::Program(QString fileName)
{
    filename = fileName;

}

Program::~Program()
{
   // delete the contained objects
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

    for(int i = 0; i < srcList.length(); i++){
        QString line = srcList[i];
        line.replace(QRegExp("[^\\S\\r\\n]+"), " "); //replace multiple spaces and tabs with a single space

        //ignore empty lines
        if (!line.trimmed().isEmpty()) {

            qDebug("Line %d: %s", (i+1),qUtf8Printable(line)); // to be removed

            //don't process comments
            if(line.startsWith("#")){
                qDebug("Line %d: Skipping comment",(i+1));
                continue;
            }

            //split the line into tokens
            QStringList tokens = line.split(" ");
            QString instructionStr = "";

            //validate
            if(instructionValidator(tokens, instructionStr) == true){

                if(instructionStr == "DciStatement" || instructionStr == "DcaStatement"){
                    //programVariables.insert(tokens[1], new Variable())
                }
                
                // statement factory needs more work done
                Statement *stmt = StatementFactory::NewStatement(instructionStr, line);
                statements.push_back(stmt);

            } else {
                // some error
            }
        }

    }

    // create identifiers
    // create statements

    // compile statements
    // generate json(or xml) output
    return true;
}

//validate instructions
bool Program::instructionValidator(QStringList &tokens, QString &instructionStr){

    int numTokens = tokens.length();

    if(numTokens >= 1 && numTokens <= 4){

        instructionStr = tokens[0];

        if(instructionStr == "dci" && numTokens == 2){
            instructionStr = "DciStatement";
            return true;
        } else if(instructionStr == "dca" && numTokens == 3){
            instructionStr = "DcaStatement";
            return true;
        } else if(instructionStr == "rdi" && numTokens == 2){
            instructionStr = "RdiStatement";
            return true;
        } else if(instructionStr == "prt" && numTokens == 2){
            instructionStr = "PrtStatement";
            return true;
        } else if(instructionStr == "mov" && numTokens == 3){
            instructionStr = "MovStatement";
            return true;
        } else if(instructionStr == "add" && numTokens == 3){
            instructionStr = "AddStatement";
            return true;
        } else if(instructionStr == "cmp" && numTokens == 3){
            instructionStr = "CmpStatement";
            return true;
        } else if(instructionStr == "jls" && numTokens == 2){
            instructionStr = "JlsStatement";
            return true;
        } else if(instructionStr == "jmr" && numTokens == 2){
            instructionStr = "JmrStatement";
            return true;
        } else if(instructionStr == "jeq" && numTokens == 2){
            instructionStr = "JeqStatement";
            return true;
        } else if(instructionStr == "jmp" && numTokens == 2){
            instructionStr = "JmpStatement";
            return true;
        } else if(instructionStr == "end" && numTokens == 1){
            instructionStr = "EndStatement";
            return true;
        } else if(instructionStr.endsWith(":") && instructionStr.length() > 1 && numTokens >= 2){
            //some extra work required here;
            instructionStr = "label";
            return true;
        }

    } else {
        // generate error
    }

    return false;
}
