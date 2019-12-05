#include "compilecontrol.h"
#include "statement.h"
#include "statementcreator.h"
#include "variable.h"
#include "token.h"
#include "maincontroller.h"
#include <QString>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

CompileControl::CompileControl()
{

}

CompileControl::~CompileControl()
{

}

bool CompileControl::compile(QString *inSrcTxt, QString *outCmplTxt, QString *errMsg, StatementList *stmtList, ProgramEnviroment *env){

    StatementCreator stmtCreator;
    int stmtIndex = 0; //statement index

    //parse;
    QStringList srcList = (*inSrcTxt).split(QRegExp("\n|\r\n|\r")); //split the source text into an array of lines


    for(int i = 0; i < srcList.length(); i++){
        QString line = srcList[i].trimmed();
        if(line.count(":") > 1){
            *errMsg = "too many Labels";
            MainController::addLineNumToErrText(i+1, errMsg);
            return false;
        }
        line.replace(QRegExp("[^\\S\\r\\n]+"), " "); //replace multiple spaces and tabs with a single space
        line.replace(" :",":");

        if(line.contains(":")){
            if(line[line.length()-1]==":"){
                *errMsg = "Label is empty";
                MainController::addLineNumToErrText(i+1, errMsg);
                return false;
            }
        }

        //ignore empty lines and comments
        if(line.trimmed().isEmpty() || line.startsWith("#"))
            continue;

        Token *tokens = new Token(line);
        QString instr = tokens->getInstr();

        // create statements
        Statement *stmt = stmtCreator.Create(instr);

        if(stmt != nullptr){

            //inject program variable enviroment
            stmt->setEnviroment(env);
            env->setJmpIndex(stmtIndex);

            // compile statements
            try {
                stmt->compile(tokens);
            } catch (const std::exception & e) {
                *errMsg = e.what();
                MainController::addLineNumToErrText(i+1, errMsg);
                return false;
            }

            //list of statements
            stmtList->add(stmt);
            stmtIndex++;
        } else {
            *errMsg = "invalid statement detected "+ tokens->getInstr();
            MainController::addLineNumToErrText(i+1, errMsg);
            return false;
        }
        delete tokens;
    }

    generateJson(stmtList, outCmplTxt);

    return true;
}

//json serialization
void CompileControl::generateJson(StatementList* stmtList, QString* jsonOut){
    *jsonOut = "[";
    for (int i = 0;i<stmtList->size();i++) {
        Statement *stmt = stmtList->get(i);
        QJsonObject jsonStmtObj;
        stmt->serialize(jsonStmtObj);
        QJsonDocument doc(jsonStmtObj);
        QString jsonString = doc.toJson(QJsonDocument::Indented);
        *jsonOut += jsonString + ",";
    }
    *jsonOut = jsonOut->left((*jsonOut).lastIndexOf(QChar(','))); //remove trailing comma
    *jsonOut += "]";
}
