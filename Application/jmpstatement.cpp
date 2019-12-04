#include "jmpstatement.h"
#include <stdexcept>

//constructor
JmpStatement::JmpStatement(){}

//destructor
JmpStatement::~JmpStatement(){

}

//compile function for jmp statement
bool JmpStatement::compile(Token *tokens, QString *errMsg){

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    if(!op1->getIdentifier()->isLabel()){
        *errMsg = "not a label";
        return false;
    }
    //check if operand type is correct
    if( !op1->getIdentifier()->isLabel() ){
        *errMsg = "invalid operand type: " + op2->getIdentifier()->getName();
        return false;
    }
    return true;
}

//runs the instruction
void JmpStatement::run(QString &result){
    Identifier *label = op1->getIdentifier();
    if(!label->isInitialized()){
        throw std::runtime_error("Label not initialized");
    }
    result = "Jumping to label " + label->getName() + " at index " + QString::number(label->getValue());
    env->setCmpFlag(UNCONDITIONAL);
    env->setJmpIndex(label->getValue());
}

//serializes instruction for compilation as a json
void JmpStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    //store statement type in json
    json["statement"] = "jmp";

    //if statement has a label, store in json
    if(hasLabel()){
        json["label"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;
}

//unserialization to run instructions
void JmpStatement::unserialize(const QJsonObject &json) const{

}
