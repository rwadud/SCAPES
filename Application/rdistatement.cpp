#include "rdistatement.h"
#include "inputhelper.h"
#include "arrayvariable.h"

//constructor
RdiStatement::RdiStatement(){}

//destructor
RdiStatement::~RdiStatement(){

}

//compile function for jeq statement
void RdiStatement::compile(Token *tokens){
    // check if label exist and updates references
    updateLabel(tokens);

    // validate argument/label names
    validate(numArgs, tokens);

    //update operand references
    updateOperands(numArgs, tokens);

    if( !(op1->getIdentifier()->isVariable() || op1->getIdentifier()->isArrayElementIndex()) ){
        error = "invalid operand type: " + op1->getIdentifier()->getName();
        throw std::logic_error(error.toUtf8());
    }
}

//runs the instruction
void RdiStatement::run(QString &result){
    Identifier *id = op1->getIdentifier();
    int number = InputHelper::readInteger(id->getName());

    if(number<0){
        throw std::runtime_error("SCAPL language only supports positive integers");
    }

    if(id->isArrayElementIndex()){
        ArrayVariable *arr = dynamic_cast<ArrayVariable*>(env->get(id->getName().split("+")[0].remove("$")));
        ArrayElementIndex *ele = dynamic_cast<ArrayElementIndex*>(id);
        if(ele->isVariableIndex())
            ele->updateVariableIndex();
        arr->set(ele->getValue(), number);
    } else {
        id->setValue(number);
    }

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

//unserialize and update label/operand references
void RdiStatement::unserialize(const QJsonObject &json) {
    Token *tokens = Statement::tokenize(json);
    updateLabel(tokens);
    updateOperands(numArgs, tokens);
}


