#include "programenviroment.h"

ProgramEnviroment::ProgramEnviroment(){}
ProgramEnviroment::~ProgramEnviroment(){
    QHashIterator<QString, Identifier*> i(hash);
    while (i.hasNext()) {
        i.next();
        delete i.value();
    }
}

void  ProgramEnviroment::setCmpFlag(CmpFlag flag){
    this->flag = flag;
}

void ProgramEnviroment::setCurrStmtIndex(int i){
    currStmtIndex = i;
}

void ProgramEnviroment::clearCmpFlag(){
    flag = NONE;
}

CmpFlag ProgramEnviroment::getCmpFlag(){
    return flag;
}

int ProgramEnviroment::getCurrStmtIndex(){
    return currStmtIndex;
}

void ProgramEnviroment::insert(QString &key, Identifier *id){
    hash.insert(key, id);
}

void ProgramEnviroment::add(QString &key, Identifier *id){
    hash.insert(key, id);
}

bool ProgramEnviroment::contains(QString &key){
    return hash.contains(key);
}

Identifier* ProgramEnviroment::get(QString &key){
    return hash.value(key, nullptr);
}

Identifier* ProgramEnviroment::find(QString &key){
    return get(key);
}
