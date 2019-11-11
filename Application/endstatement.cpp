#include "endstatement.h"

EndStatement::EndStatement(){}

EndStatement::~EndStatement(){

}

bool EndStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete
    return validate(numArgs, tokens, errMsg);
}

bool EndStatement::run(){
    return true;
}

void EndStatement::serialize(QJsonObject &json){

}

void EndStatement::unserialize(const QJsonObject &json) const{

}
