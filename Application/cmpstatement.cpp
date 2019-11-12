#include "cmpstatement.h"

CmpStatement::CmpStatement(){}

CmpStatement::~CmpStatement(){

}

bool CmpStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

bool CmpStatement::run(){
    return true;
}

void CmpStatement::serialize(QJsonObject &json){

}

void CmpStatement::unserialize(const QJsonObject &json) const{

}
