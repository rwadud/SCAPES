#include "compilecontrol.h"
#include "statement.h"
#include "statementcreator.h"
#include "variable.h"
#include "token.h"
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

        Token *tokens = new Token(line);
        QString instr = tokens->getInstr();

        // create statements
        Statement *stmt = stmtCreator.Create(instr);

        if(stmt != nullptr){

            //inject program variable enviroment
            stmt->setEnviroment(prgmVars);

            // check if label exist and updates references
            stmt->updateLabel(stmtIndex, tokens);

            // compile statements
            if(stmt->compile(tokens, errMsg) == false)
                return false;

            //list of statements
            stmtList->add(stmt);
            stmtIndex++;
        } else {
            *errMsg = "invalid statement detected";
            qDebug() << "error at " << line;
            // some error
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
        QJsonObject jsonStmtObj;
        stmtList->get(i)->serialize(jsonStmtObj);
        QJsonDocument doc(jsonStmtObj);
        QString jsonString = doc.toJson(QJsonDocument::Indented);
        *jsonOut += jsonString + ",";
    }
    *jsonOut = jsonOut->left((*jsonOut).lastIndexOf(QChar(','))); //remove trailing comma
    *jsonOut += "]";
}
