#include "runcontrol.h"
#include "statementcreator.h"
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>


RunControl::RunControl()
{
    env = new ProgramEnviroment;
    slist = new StatementList;
}

RunControl::~RunControl()
{
    delete env;
    delete slist;
}

bool RunControl::run(QString *inJsonTxt, QString *errMsg)
{
    Statement *stmt = nullptr;

    regenerate(inJsonTxt);

    for (int i=0;i<slist->size();i++) {
        stmt = slist->get(i);
        if(!stmt->run()){
            //handle error
            return false;
        }
    }

    return true;
}

void RunControl::regenerate(QString *inJsonTxt){
    qDebug() << *inJsonTxt;
    StatementCreator stmtCreator;
    QJsonDocument jsonResponse = QJsonDocument::fromJson((*inJsonTxt).toUtf8());
    QJsonArray jsonArray = jsonResponse.array();

    for(int i=0; i<jsonArray.size();i++){
        QJsonObject obj = jsonArray.at(i).toObject();
        QString instr = obj["statement"].toString();
        qDebug() << "unserializing "+instr;

        Statement *stmt = stmtCreator.Create(instr);
        stmt->setEnviroment(env);
        stmt->unserialize(obj); //needs to be implemented for each statement
        slist->add(stmt);
    }
}
