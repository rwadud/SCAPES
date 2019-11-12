#include "dcistatement.h"
#include "variable.h"

//constructor
DciStatement::DciStatement(){}

//destructor
DciStatement::~DciStatement(){

}

//compile function for dci statement
bool DciStatement::compile(Token *tokens, QString *errMsg){

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    QString arg1 = tokens->getArg1();
    //create variables or check if they exist in prgmVars
    if(prgmVars->contains(arg1)){
        *errMsg = arg1+ " already defined";
        return false;
    } else {
         Identifier *var = new Variable(arg1);
         prgmVars->insert(arg1,var);
         op1 = new Operand(var);
    }

    return true;
}

//runs the instruction
bool DciStatement::run(){
    return true;
}

//serializes instruction for compilation as a json
void DciStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    //store statement type in json
    json["statementType"] = "DciStatement";

    //if statement has a label, store in json
    if(hasLabel() == true){
        json["labelName"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;
}

//unserialization to run instructionss
void DciStatement::unserialize(const QJsonObject &json) const{

}
