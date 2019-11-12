#include "cmpstatement.h"

//constructor
CmpStatement::CmpStatement(){}

//destructor
CmpStatement::~CmpStatement(){

}

//compile function for cmp statement
bool CmpStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

//runs the instruction
bool CmpStatement::run(){
    return true;
}

//serializes instruction for compilation as a json
void CmpStatement::serialize(QJsonObject &json){
    //store statement type in json
    json["statementType"] = "CmpStatement";

    //if statement has a label, store in json
    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    //store operands in json
    json["op1"] = op1->serialize();
    json["op2"] = op2->serialize();

}

//unserialization to run instructions
void CmpStatement::unserialize(const QJsonObject &json) const{

}
