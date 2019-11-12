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
    QJsonObject jsonIdentifier1;

    json["statementType"] = "JmpStatement";

    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;

}

void JmpStatement::unserialize(const QJsonObject &json) const{

}
