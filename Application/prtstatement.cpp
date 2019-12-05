#include "prtstatement.h"
#include "stringliteral.h"

//constructor
PrtStatement::PrtStatement(){}

//destructor
PrtStatement::~PrtStatement(){

}

//compile function for prt statement
void PrtStatement::compile(Token *tokens){
    // check if label exist and updates references
    updateLabel(tokens);

    // validate argument/label names
    validate(numArgs, tokens);

    //update operand references
    updateOperands(numArgs, tokens);

    if( op1->getIdentifier()->isArray() ){
        error = "invalid operand type: " + op1->getIdentifier()->getName();
        throw std::logic_error(error.toUtf8());
    }

}

//runs the instruction
void PrtStatement::run(QString &result){

    Identifier *id = op1->getIdentifier();

    if(id->isStringLiteral()){
        StringLiteral *str = dynamic_cast<StringLiteral*>(id);
        result = "Print: " + str->getStrValue();
    } else if(id->isArrayElementIndex()) {
        ArrayVariable *arr = dynamic_cast<ArrayVariable*>(env->get(id->getName().split("+")[0].remove("$")));
        ArrayElementIndex *ele = dynamic_cast<ArrayElementIndex*>(id);
        if(ele->isVariableIndex())
            ele->updateVariableIndex();
        result = "Print: " + QString::number(arr->get(ele->getValue()));
    } else {
        result = "Print: " + QString::number(id->getValue());
    }

}

//serializes instruction for compilation as a json
void PrtStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    //store statement type in json
    json["statement"] = "prt";

    //if statement has a label, store in json
    if(hasLabel()){
        json["label"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;
}

//unserialization to run instructions
void PrtStatement::unserialize(const QJsonObject &json) {
    Token *tokens = Statement::tokenize(json);
    updateLabel(tokens);
    updateOperands(numArgs, tokens);
}
