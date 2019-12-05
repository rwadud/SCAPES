#include "cmpstatement.h"

//constructor
CmpStatement::CmpStatement(){}

//destructor
CmpStatement::~CmpStatement(){

}

//compile function for cmp statement
void CmpStatement::compile(Token *tokens){
    // check if label exist and updates references
    updateLabel(tokens);

    // validate argument/label names
    validate(numArgs, tokens);

    //update operand references
    updateOperands(numArgs, tokens);

    if( !(op1->getIdentifier()->isArray() || op1->getIdentifier()->isVariable() || op1->getIdentifier()->isIntegerLiteral()) ){
        error = "invalid operand 1 type: " + op1->getIdentifier()->getName();
        throw std::logic_error(error.toUtf8());
    }
    if( !(op2->getIdentifier()->isArray() || op2->getIdentifier()->isVariable() || op2->getIdentifier()->isIntegerLiteral()) ){
        error = "invalid operand 2 type: " + op2->getIdentifier()->getName();
        throw std::logic_error(error.toUtf8());
    }

}

//runs the instruction
void CmpStatement::run(QString &result){

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
void CmpStatement::unserialize(const QJsonObject &json){
    Token *tokens = Statement::tokenize(json);
    updateLabel(tokens);
    updateOperands(numArgs, tokens);
}
