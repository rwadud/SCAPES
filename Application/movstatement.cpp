#include "movstatement.h"

//constructor
MovStatement::MovStatement(){}

//destructor
MovStatement::~MovStatement(){

}

//compile function for mov statement
void MovStatement::compile(Token *tokens){
    // check if label exist and updates references
    updateLabel(tokens);

    // validate argument/label names
    validate(numArgs, tokens);

    //update operand references
    updateOperands(numArgs, tokens);

    if( !(op1->getIdentifier()->isArray() || op1->getIdentifier()->isVariable() || op1->getIdentifier()->isIntegerLiteral()  || op1->getIdentifier()->isArrayElementIndex()) ){
        error = "invalid operand 1 type: " + op1->getIdentifier()->getName();
        throw std::logic_error(error.toUtf8());
    }
    if( !(op2->getIdentifier()->isArray() || op2->getIdentifier()->isVariable() || op2->getIdentifier()->isArrayElementIndex()) ){
        error = "invalid operand 2 type: " + op2->getIdentifier()->getName();
        throw std::logic_error(error.toUtf8());
    }

}

//runs the instruction
void MovStatement::run(QString &result){
    Identifier *id1 = op1->getIdentifier();
    Identifier *id2 = op2->getIdentifier();

    if(id1->isArrayElementIndex() && id2->isArrayElementIndex()) {
        ArrayVariable *arr1 = dynamic_cast<ArrayVariable*>(env->get(id1->getName().split("+")[0].remove("$")));
        ArrayVariable *arr2 = dynamic_cast<ArrayVariable*>(env->get(id2->getName().split("+")[0].remove("$")));
        ArrayElementIndex *ele1 = dynamic_cast<ArrayElementIndex*>(id1);
        ArrayElementIndex *ele2 = dynamic_cast<ArrayElementIndex*>(id2);
        if(ele1->isVariableIndex())
            ele1->updateVariableIndex();
        if(ele2->isVariableIndex())
            ele2->updateVariableIndex();
        arr2->set(id2->getValue(), arr1->get(id1->getValue()));
    } else if (id1->isArrayElementIndex() && !id2->isArrayElementIndex()) {
        ArrayVariable *arr = dynamic_cast<ArrayVariable*>(env->get(id1->getName().split("+")[0].remove("$")));
        ArrayElementIndex *ele1 = dynamic_cast<ArrayElementIndex*>(id1);
        if(ele1->isVariableIndex())
            ele1->updateVariableIndex();
        id2->setValue( arr->get(id1->getValue()) );
    } else if (!id1->isArrayElementIndex() && id2->isArrayElementIndex()) {
        ArrayVariable *arr = dynamic_cast<ArrayVariable*>(env->get(id2->getName().split("+")[0].remove("$")));
        ArrayElementIndex *ele2 = dynamic_cast<ArrayElementIndex*>(id2);
        if(ele2->isVariableIndex())
            ele2->updateVariableIndex();
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
void MovStatement::unserialize(const QJsonObject &json) {
    Token *tokens = Statement::tokenize(json);
    updateLabel(tokens);
    updateOperands(numArgs, tokens);
    delete tokens;
}
