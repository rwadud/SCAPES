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

void ProgramEnviroment::setJmpIndex(int i){
    jmpIndex = i;
}

void ProgramEnviroment::clearCmpFlag(){
    jmpIndex = -1;
    flag = NONE;
}

CmpFlag ProgramEnviroment::getCmpFlag(){
    return flag;
}

int ProgramEnviroment::getJmpIndex(){
    return jmpIndex;
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
