#include "programenviroment.h"
#include <QHashIterator>
#include <QDebug>

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

bool ProgramEnviroment::isTerminated(){
    return terminated;
}

void ProgramEnviroment::terminate(){
    terminated = true;
}
void ProgramEnviroment::reset(){
    terminated = false;
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

void ProgramEnviroment::print(){
    QHashIterator<QString, Identifier *> i(hash);
    qDebug() << "Env Vars";
    while (i.hasNext()) {
        i.next();
        qDebug() << i.key() << ": " << i.value()->getValue();
    }
}
