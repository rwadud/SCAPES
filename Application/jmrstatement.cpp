#include "jmrstatement.h"

JmrStatement::JmrStatement(){}

JmrStatement::~JmrStatement(){

}

bool JmrStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

bool JmrStatement::run(){
    return true;
}

void JmrStatement::serialize(QJsonObject &json){

    json["statementType"] = "JmrStatement";

    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    json["op1"] = op1->serialize();

}

void JmrStatement::unserialize(const QJsonObject &json) const{

}
