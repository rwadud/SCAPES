#include "runcontrol.h"
#include "statementcreator.h"
#include "maincontroller.h"
//#include "cmpflag.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>


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

bool RunControl::run(QString *inJsonTxt, QTextBrowser *resultConsole, QString *errMsg, StatementList *stmtList, ProgramEnviroment *envi)
{
    Statement *stmt = nullptr;

    regenerate(inJsonTxt);

    int i = 0;
    QString result;
    env->reset();
    while (i<slist->size()) {
        if(env->isTerminated())
            break;
        result = "";
        stmt = slist->get(i);
        try {
            stmt->run(result);
            if(!result.isEmpty()){
                resultConsole->append(result);
            }
        } catch (const std::exception & e) {
            *errMsg = e.what();
            return false;
        }

        //qDebug () << "flag state is " << env->getCmpFlag() << " at index " << i;
        if(env->getCmpFlag()!=NONE && env->getJmpIndex() >= 0){
            i = env->getJmpIndex();
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
    //qDebug() << *inJsonTxt;
    StatementCreator stmtCreator;
    QJsonDocument jsonResponse = QJsonDocument::fromJson((*inJsonTxt).toUtf8());
    QJsonArray jsonArray = jsonResponse.array();

    for(int i=0; i<jsonArray.size();i++){
        QJsonObject obj = jsonArray.at(i).toObject();
        QString instr = obj["statement"].toString();
        qDebug() << "unserializing "+instr;
        Statement *stmt = stmtCreator.Create(instr);
        stmt->setEnviroment(env);
        env->setJmpIndex(i);
        stmt->unserialize(obj); //needs to be implemented for each statement
        slist->add(stmt);
    }
}
