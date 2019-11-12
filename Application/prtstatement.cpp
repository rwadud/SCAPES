#include "prtstatement.h"

PrtStatement::PrtStatement(){}

PrtStatement::~PrtStatement(){

}

bool PrtStatement::compile(Token *tokens, QString *errMsg){
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

    json["statementType"] = "PrtStatement";

    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    json["op1"] = op1->serialize();
}

void PrtStatement::unserialize(const QJsonObject &json) const{

}
