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
    QJsonObject jsonIdentifier1;

    json["statementType"] = "RdiStatement";

    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;

}

void RdiStatement::unserialize(const QJsonObject &json) const{

}


