#include "jmpstatement.h"

JmpStatement::JmpStatement(){}

JmpStatement::~JmpStatement(){

}

bool JmpStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

bool JmpStatement::run(){
    return true;
}

void JmpStatement::serialize(QJsonObject &json){
    json["statementType"] = "JmpStatement";

    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    json["op1"] = op1->serialize();

}

void JmpStatement::unserialize(const QJsonObject &json) const{

}
