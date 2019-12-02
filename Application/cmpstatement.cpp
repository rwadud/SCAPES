#include "cmpstatement.h"

//constructor
CmpStatement::CmpStatement(){}

//destructor
CmpStatement::~CmpStatement(){

}

//compile function for cmp statement
bool CmpStatement::compile(Token *tokens, QString *errMsg){
    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    if( !(op1->getIdentifier()->isArray() || op1->getIdentifier()->isVariable() || op1->getIdentifier()->isIntegerLiteral()) ){
        *errMsg = "invalid operand 1 type: " + op1->getIdentifier()->getName();
        return false;
    }
    if( !(op2->getIdentifier()->isArray() || op2->getIdentifier()->isVariable() || op2->getIdentifier()->isIntegerLiteral()) ){
        *errMsg = "invalid operand 2 type: " + op2->getIdentifier()->getName();
        return false;
    }

    return true;
}

//runs the instruction
bool CmpStatement::run(){

    Identifier *x, *y;

    x = op1->getIdentifier();
    y = op2->getIdentifier();

    env->clearCmpFlag();
    if(x->getValue() > y->getValue()){
        env->setCmpFlag(MORE);
    }else if(x->getValue() < y->getValue()) {
        env->setCmpFlag(LESS);
    } else {
        env->setCmpFlag(EQUAL);
    }

    return true;
}

//serializes instruction for compilation as a json
void CmpStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;
    QJsonObject jsonIdentifier2;

    //store statement type in json
    json["statement"] = "cmp";

    //if statement has a label, store in json
    if(hasLabel()){
        json["label"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    op2->getIdentifier()->serialize(jsonIdentifier2);
    //store operands in json
    json["op1"] = jsonIdentifier1;
    json["op2"] = jsonIdentifier2;

}

//unserialization to run instructions
void CmpStatement::unserialize(const QJsonObject &json) const{

}
