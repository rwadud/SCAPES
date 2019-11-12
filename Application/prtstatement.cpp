#include "prtstatement.h"

PrtStatement::PrtStatement(){}

PrtStatement::~PrtStatement(){

}

bool PrtStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete
    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

bool PrtStatement::run(){
    return true;
}

void PrtStatement::serialize(QJsonObject &json){
    qDebug() << "test";
}

void PrtStatement::unserialize(const QJsonObject &json) const{

}
