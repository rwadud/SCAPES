#include "Program.h"
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

            //qDebug("Line %d: %s", (i+1),qUtf8Printable(line)); // to be removed

            //don't process comments
            if(line.startsWith("#")){
                qDebug("Line %d: Skipping comment",(i+1));
                continue;
            }

            //split the line into tokens
            QStringList tokens = line.split(" ");
            int numTokens = tokens.length();

            //validate
            if(numTokens >= 1 && numTokens <= 4){
                qDebug("Line %d: %s has %d tokens", (i+1),qUtf8Printable(line), tokens.length()); // to be removed

                QString instructionStr = tokens[0];

                if(instructionStr == "dci" && numTokens == 2){
                    // do some work

                } else if(instructionStr == "dca" && numTokens == 3){


                } else if(instructionStr == "rdi" && numTokens == 2){


                } else if(instructionStr == "prt" && numTokens == 2){


                } else if(instructionStr == "mov" && numTokens == 3){


                } else if(instructionStr == "add" && numTokens == 3){


                } else if(instructionStr == "cmp" && numTokens == 3){


                } else if(instructionStr == "jls" && numTokens == 2){


                } else if(instructionStr == "jmr" && numTokens == 2){


                } else if(instructionStr == "jeq" && numTokens == 2){


                } else if(instructionStr == "jmp" && numTokens == 2){


                } else if(instructionStr == "end" && numTokens == 1){


                } else if(instructionStr.endsWith(":") && instructionStr.length() > 1 && numTokens >= 2){ // label


                } else {

                    // some error
                }

            } else {

                // generate error
            }

        }

    }

    // create identifiers
    // create statements

    // compile statements
    // generate json(or xml) output
    return true;
}

/*
bool Program::instructionValidator(QString instructionStr, int numTokens){
    if(instructionStr == "dci" && numTokens == 2){
        return true;
    } else if(instructionStr == "dca" && numTokens == 3){
        return true;
    } else if(instructionStr == "rdi" && numTokens == 2){
        return true;
    } else if(instructionStr == "prt" && numTokens == 2){
        return true;
    } else if(instructionStr == "mov" && numTokens == 3){
        return true;
    } else if(instructionStr == "add" && numTokens == 3){
        return true;
    } else if(instructionStr == "cmp" && numTokens == 3){
        return true;
    } else if(instructionStr == "jls" && numTokens == 2){
        return true;
    } else if(instructionStr == "jmr" && numTokens == 2){
        return true;
    } else if(instructionStr == "jeq" && numTokens == 2){
        return true;
    } else if(instructionStr == "jmp" && numTokens == 2){
        return true;
    } else if(instructionStr == "end" && numTokens == 1){
        return true;
    } else if(instructionStr.endsWith(":") && instructionStr.length() > 1 && numTokens >= 2){
        return true;
    } else {
        return false;
    }
}
*/
