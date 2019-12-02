#include "runcontrol.h"
#include "statementcreator.h"
//#include "cmpflag.h"
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

bool RunControl::run(QString *inJsonTxt, QString *errMsg, StatementList *stmtList, ProgramEnviroment *env)
{
    Statement *stmt = nullptr;

    //regenerate(inJsonTxt);

    int i = 0;
    while (i<stmtList->size()) {
        stmt = stmtList->get(i);
        if(!stmt->run()){
            //handle error
            return false;
        }
        //qDebug () << "flag state is " << env->getCmpFlag() << " at index " << i;
        if(env->getCmpFlag()!=NONE && env->getJmpIndex() >= 0){
            i = env->getJmpIndex();
            qDebug() << "jumping to index" << i;
            env->clearCmpFlag();
            //qDebug() << "clearning flag... flag state is " << env->getCmpFlag();
            continue;
        }
        i++;
    }
    return true;
}

//create statement objects from a json document
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
