#include "dcistatement.h"
#include "variable.h"

//constructor
DciStatement::DciStatement(){}

//destructor
DciStatement::~DciStatement(){

}

//compile function for dci statement
void DciStatement::compile(Token *tokens){
    // check if label exist and updates references
    updateLabel(tokens);

    // validate argument/label names
    validate(numArgs, tokens);

    QString arg = tokens->getArg1();
    //create variables or check if they exist in prgmVars
    if(env->contains(arg)){
        error = arg+ " already defined";
        throw std::logic_error(error.toUtf8());
    } else {
         Identifier *var = new Variable(arg);
         env->insert(arg,var);
         op1 = new Operand(var);
    }

}

//runs the instruction
void DciStatement::run(QString &result){
}

//serializes instruction for compilation as a json
void DciStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    //store statement type in json
    json["statement"] = "dci";

    //if statement has a label, store in json
    if(hasLabel() == true){
        json["label"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;
}

//unserialization to run instructionss
void DciStatement::unserialize(const QJsonObject &json) {
    Token *tokens = Statement::tokenize(json);
    updateLabel(tokens);
    QString arg = tokens->getArg1();
    Identifier *id = new Variable(arg);
    env->insert(arg, id);
    op1 = new Operand(id);
    delete tokens;
}
