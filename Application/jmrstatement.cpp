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
    QJsonObject jsonIdentifier1;

    json["statementType"] = "JmrStatement";

    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;

}

void JmrStatement::unserialize(const QJsonObject &json) const{

}
