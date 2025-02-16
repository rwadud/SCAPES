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

bool RunControl::run(QString *inJsonTxt, QTextBrowser *resultConsole, QString *errMsg)
{
    Statement *stmt = nullptr;
    QString result;

    //regenerate statement objects from json.
    regenerate(inJsonTxt);

    int i = 0;
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

        //check flags and execute jumps
        if(env->getCmpFlag()!=NONE && env->getJmpIndex() >= 0){
            i = env->getJmpIndex();
            env->clearCmpFlag();
            continue;
        }
        i++;
    }

    return true;
}

//create statement objects from a json document
void RunControl::regenerate(QString *inJsonTxt){
    StatementCreator stmtCreator;
    QJsonDocument jsonResponse = QJsonDocument::fromJson((*inJsonTxt).toUtf8());
    QJsonArray jsonArray = jsonResponse.array();

    for(int i=0; i<jsonArray.size();i++){
        QJsonObject obj = jsonArray.at(i).toObject();
        QString instr = obj["statement"].toString();
        Statement *stmt = stmtCreator.Create(instr);
        stmt->setEnviroment(env);
        env->setJmpIndex(i);
        stmt->unserialize(obj); //needs to be implemented for each statement
        slist->add(stmt);
    }
}
