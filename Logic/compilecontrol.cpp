#include "compilecontrol.h"
#include "statement.h"
#include "statementcreator.h"
#include "variable.h"
#include "token.h"
#include <QString>

CompileControl::CompileControl()
{

}

CompileControl::~CompileControl()
{

}

bool CompileControl::compile(QString *inSrcTxt, QString *outCmplTxt, QString *errMsg, StatementList *stmtList, VHash *prgmVars){

    StatementCreator stmtCreator;
    int stmtIndex = 0; //statement index

    //parse;
    QStringList srcList = (*inSrcTxt).split(QRegExp("\n|\r\n|\r")); //split the source text into an array of lines

    for(int i = 0; i < srcList.length(); i++){
        QString line = srcList[i];
        if(line.count(":") > 1){
            // throw error
        }
        line.replace(QRegExp("[^\\S\\r\\n]+"), " "); //replace multiple spaces and tabs with a single space
        line.replace(" :",":");

        //ignore empty lines and comments
        if(line.trimmed().isEmpty() || line.startsWith("#"))
            continue;

        Token *tokens = new Token(line.split(" "));
        QString instr = tokens->getInstr();
        QString labelName = tokens->getLabel();

        if(tokens->length() > 3){
            //too many tokens
            *errMsg = "too many arguments";
            return false;
        }

        // create statements
        Statement *stmt = stmtCreator.Create(instr);

        if(stmt != nullptr){

            //inject program variable enviroment
            stmt->setEnviroment(prgmVars);

            //create labels if a statement has one
            if(Token::isValidIdentifierName(labelName)){
                if(prgmVars->contains(labelName)){
                    stmt->setLabel(prgmVars->get(labelName));
                    //*errMsg = "Label "+labelName+" already defined";
                } else {
                    Identifier *label = new Label(labelName,stmtIndex);
                    prgmVars->insert(labelName, label);
                }
            } else {
                *errMsg = "invalid characters detected";
            }

            // compile statements
            if(!stmt->compile(tokens, errMsg)){
                return false;
            }

            //list of statements
            stmtList->add(stmt);
            stmtIndex++;
        } else {
            qDebug() << "error at " << line;
            // some error
            return false;
        }

    }

    return true;
}

