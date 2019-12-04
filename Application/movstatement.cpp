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

    if( !(op1->getIdentifier()->isArray() || op1->getIdentifier()->isVariable() || op1->getIdentifier()->isIntegerLiteral()  || op1->getIdentifier()->isArrayElementIndex()) ){
        *errMsg = "invalid operand 1 type: " + op1->getIdentifier()->getName();
        return false;
    }
    if( !(op2->getIdentifier()->isArray() || op2->getIdentifier()->isVariable() || op2->getIdentifier()->isArrayElementIndex()) ){
        *errMsg = "invalid operand 2 type: " + op2->getIdentifier()->getName();
        return false;
    }

    return true;
}

//runs the instruction
void MovStatement::run(QString &result){
    Identifier *id1 = op1->getIdentifier();
    Identifier *id2 = op2->getIdentifier();

    if(id1->isArrayElementIndex() && id2->isArrayElementIndex()) {
        ArrayVariable *arr1 = dynamic_cast<ArrayVariable*>(env->get(id1->getName().split("+")[0].remove("$")));
        ArrayVariable *arr2 = dynamic_cast<ArrayVariable*>(env->get(id2->getName().split("+")[0].remove("$")));
        arr2->set(id2->getValue(), arr1->get(id1->getValue()));
    } else if (id1->isArrayElementIndex() && !id2->isArrayElementIndex()) {
        ArrayVariable *arr = dynamic_cast<ArrayVariable*>(env->get(id1->getName().split("+")[0].remove("$")));
        id2->setValue( arr->get(id1->getValue()) );
    } else if (!id1->isArrayElementIndex() && id2->isArrayElementIndex()) {
        ArrayVariable *arr = dynamic_cast<ArrayVariable*>(env->get(id2->getName().split("+")[0].remove("$")));
        arr->set(id2->getValue(), id1->getValue());
    } else {
        id2->setValue(id1->getValue());
    }

}

//serializes instruction for compilation as a json
void MovStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;
    QJsonObject jsonIdentifier2;

    //store statement type in json
    json["statement"] = "mov";

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
void MovStatement::unserialize(const QJsonObject &json) const{

}
