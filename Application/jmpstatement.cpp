#include "jmpstatement.h"
#include <stdexcept>

//constructor
JmpStatement::JmpStatement(){}

//destructor
JmpStatement::~JmpStatement(){

}

//compile function for jmp statement
void JmpStatement::compile(Token *tokens){
    // check if label exist and updates references
    updateLabel(tokens);

    // validate argument/label names
    validate(numArgs, tokens);

    //update operand references
    updateOperands(numArgs, tokens);

    //check if operand type is correct
    if( !op1->getIdentifier()->isLabel() ){
        error = "invalid operand type: " + op2->getIdentifier()->getName();
        throw std::logic_error(error.toUtf8());
    }

}

//runs the instruction
void JmpStatement::run(QString &result){
    Identifier *label = op1->getIdentifier();
    if(!label->isInitialized()){
        throw std::runtime_error("Label not initialized: " + label->getName().toUtf8());
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
void JmpStatement::unserialize(const QJsonObject &json){
    Token *tokens = Statement::tokenize(json);
    updateLabel(tokens);
    updateOperands(numArgs, tokens);
}
