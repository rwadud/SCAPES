#include "rdistatement.h"
#include "inputhelper.h"
#include "arrayvariable.h"

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

//unserialization to run instructions
void RdiStatement::unserialize(const QJsonObject &json) const{

}


