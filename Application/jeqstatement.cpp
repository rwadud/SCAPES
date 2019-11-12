#include "jeqstatement.h"

JeqStatement::JeqStatement(){}

JeqStatement::~JeqStatement(){

}

bool JeqStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete
    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

bool JeqStatement::run(){
    return true;
}

void JeqStatement::serialize(QJsonObject &json){
    json["statementType"] = "JeqStatement";

    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    json["op1"] = op1->serialize();
}

void JeqStatement::unserialize(const QJsonObject &json) const{

}
