#include "movstatement.h"

MovStatement::MovStatement(){}

MovStatement::~MovStatement(){

}

bool MovStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

bool MovStatement::run(){
    return true;
}

void MovStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;
    QJsonObject jsonIdentifier2;

    json["statementType"] = "MovStatement";

    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    op2->getIdentifier()->serialize(jsonIdentifier2);
    //store operands in json
    json["op1"] = jsonIdentifier1;
    json["op2"] = jsonIdentifier2;
}

void MovStatement::unserialize(const QJsonObject &json) const{

}
