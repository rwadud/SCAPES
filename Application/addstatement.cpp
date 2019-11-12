#include "addstatement.h"
//constructor
AddStatement::AddStatement(){}

//destructor
AddStatement::~AddStatement(){

}

//compile function for add statement
bool AddStatement::compile(Token *tokens, QString *errMsg){
    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

//runs the instruction
bool AddStatement::run(){
    return true;
}

//serializes instruction for compilation as a json
void AddStatement::serialize(QJsonObject &json){
    //store statement type in json
    json["statementType"] = "AddStatement";

    //if statement has a label, store in json
    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    //store operands in json
    json["op1"] = op1->serialize();
    json["op2"] = op2->serialize();
}

//unserialization to run instructions
void AddStatement::unserialize(const QJsonObject &json) const{

}
