#include "rdistatement.h"
#include "inputhelper.h"

//constructor
RdiStatement::RdiStatement(){}

//destructor
RdiStatement::~RdiStatement(){

}

//compile function for jeq statement
bool RdiStatement::compile(Token *tokens, QString *errMsg){
    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

//runs the instruction
bool RdiStatement::run(){
    Identifier *id = op1->getIdentifier();
    int number = InputHelper::readInteger(id->getName());

    if(number<0){
        //handle error
        qDebug() << "SCAPL language only supports positive integers";
        return false;
    }

    id->setValue(number);
    return true;
}

//serializes instruction for compilation as a json
void RdiStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    //store statement type in json
    json["statement"] = "rdi";

    //if statement has a label, store in json
    if(hasLabel()){
        json["label"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;

}

//unserialization to run instructions
void RdiStatement::unserialize(const QJsonObject &json) const{

}


