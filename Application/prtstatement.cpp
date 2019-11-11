#include "prtstatement.h"

PrtStatement::PrtStatement(){}

PrtStatement::~PrtStatement(){

}

bool PrtStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete
}

bool PrtStatement::run(){
    return true;
}

void PrtStatement::serialize(QJsonObject &json){

}

void PrtStatement::unserialize(const QJsonObject &json) const{

}
