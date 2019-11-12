#include "rdistatement.h"

RdiStatement::RdiStatement(){}

RdiStatement::~RdiStatement(){

}

bool RdiStatement::compile(Token *tokens, QString *errMsg){

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

bool RdiStatement::run(){
    return true;
}

void RdiStatement::serialize(QJsonObject &json){
    json["statementType"] = "RdiStatement";

    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    json["op1"] = op1->serialize();

}

void RdiStatement::unserialize(const QJsonObject &json) const{

}


