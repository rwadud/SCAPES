#include "movstatement.h"

//constructor
MovStatement::MovStatement(){}

//destructor
MovStatement::~MovStatement(){

}

//compile function for mov statement
bool MovStatement::compile(Token *tokens, QString *errMsg){

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

//runs the instruction
bool MovStatement::run(){
    return true;
}

//serializes instruction for compilation as a json
void MovStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;
    QJsonObject jsonIdentifier2;

    //store statement type in json
    json["statementType"] = "MovStatement";

    //if statement has a label, store in json
    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    op2->getIdentifier()->serialize(jsonIdentifier2);
    //store operands in json
    json["op1"] = jsonIdentifier1;
    json["op2"] = jsonIdentifier2;
}

//unserialization to run instructions
void MovStatement::unserialize(const QJsonObject &json) const{

}
