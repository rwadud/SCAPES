#include "movstatement.h"

MovStatement::MovStatement(){}

MovStatement::~MovStatement(){

}

bool MovStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

bool MovStatement::run(){
    return true;
}

void MovStatement::serialize(QJsonObject &json){

}

void MovStatement::unserialize(const QJsonObject &json) const{

}
