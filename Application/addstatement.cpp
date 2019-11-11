#include "addstatement.h"

AddStatement::AddStatement(){}

AddStatement::~AddStatement(){

}

bool AddStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

bool AddStatement::run(){
    return true;
}

void AddStatement::serialize(QJsonObject &json){

}

void AddStatement::unserialize(const QJsonObject &json) const{

}
