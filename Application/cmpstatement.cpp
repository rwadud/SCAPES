#include "cmpstatement.h"

CmpStatement::CmpStatement(){}

CmpStatement::~CmpStatement(){

}

bool CmpStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete
}

bool CmpStatement::run(){
    return true;
}

void CmpStatement::serialize(QJsonObject &json){

}

void CmpStatement::unserialize(const QJsonObject &json) const{

}
