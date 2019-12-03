#include "jeqstatement.h"

//constructor
JeqStatement::JeqStatement(){}

//destructor
JeqStatement::~JeqStatement(){

}

//compile function for jeq statement
bool JeqStatement::compile(Token *tokens, QString *errMsg){
    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    //check if operand type is correct
    if( !op1->getIdentifier()->isLabel() ){
        *errMsg = "invalid operand type: " + op2->getIdentifier()->getName();
        return false;
    }

    return true;
}

//runs the instruction
bool JeqStatement::run(QString &result){
    Identifier *label = op1->getIdentifier();
    if(env->getCmpFlag()==EQUAL){
        result = "Jumping to label " + label->getName() + " at index " + QString::number(label->getValue());
        env->setJmpIndex(label->getValue());
    }
    return true;
}

//serializes instruction for compilation as a json
void JeqStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    //store statement type in json
    json["statement"] = "jeq";

    //if statement has a label, store in json
    if(hasLabel()){
        json["label"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;
}

//unserialization to run instructions
void JeqStatement::unserialize(const QJsonObject &json) const{

}
