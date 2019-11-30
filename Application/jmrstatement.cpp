#include "jmrstatement.h"

//constructor
JmrStatement::JmrStatement(){}

//destructor
JmrStatement::~JmrStatement(){

}

//compile function for jmr statement
bool JmrStatement::compile(Token *tokens, QString *errMsg){

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg)){
        return false;
    }


    return true;
}

//runs the instruction
bool JmrStatement::run(){
    return true;
}

//serializes instruction for compilation as a json
void JmrStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    //store statement type in json
    json["statement"] = "jmr";

    //if statement has a label, store in json
    if(hasLabel()){
        json["label"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;
}

//unserialization to run instructions
void JmrStatement::unserialize(const QJsonObject &json) const{

}
