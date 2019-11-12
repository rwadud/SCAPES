#include "prtstatement.h"

//constructor
PrtStatement::PrtStatement(){}

//destructor
PrtStatement::~PrtStatement(){

}

//compile function for prt statement
bool PrtStatement::compile(Token *tokens, QString *errMsg){
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
bool PrtStatement::run(){
    return true;
}

//serializes instruction for compilation as a json
void PrtStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    //store statement type in json
    json["statementType"] = "PrtStatement";

    //if statement has a label, store in json
    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;
}

//unserialization to run instructions
void PrtStatement::unserialize(const QJsonObject &json) const{

}
