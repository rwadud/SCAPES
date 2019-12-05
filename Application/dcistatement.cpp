#include "dcistatement.h"
#include "variable.h"

//constructor
DciStatement::DciStatement(){}

//destructor
DciStatement::~DciStatement(){

}

//compile function for dci statement
bool DciStatement::compile(Token *tokens, QString *errMsg){
    // check if label exist and updates references
    if(!updateLabel(tokens, errMsg)) {
        return false;
    }
    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    QString arg = tokens->getArg1();
    //create variables or check if they exist in prgmVars
    if(env->contains(arg)){
        *errMsg = arg+ " already defined";
        return false;
    } else {
         Identifier *var = new Variable(arg);
         env->insert(arg,var);
         op1 = new Operand(var);
    }

    return true;
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
    updateLabel(tokens, nullptr);
    QString label = json["label"].toString();
    QString arg = json["op1"]["name"].toString();
    Identifier *id = new Variable(arg);
    env->insert(arg, id);
    op1 = new Operand(id);
}
