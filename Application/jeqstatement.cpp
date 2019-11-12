#include "jeqstatement.h"

//constructor
JeqStatement::JeqStatement(){}

//destructor
JeqStatement::~JeqStatement(){

}

//compile function for jeq statement
bool JeqStatement::compile(Token *tokens, QString *errMsg){
    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

//runs the instruction
bool JeqStatement::run(){
    return true;
}

//serializes instruction for compilation as a json
void JeqStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    //store statement type in json
    json["statementType"] = "JeqStatement";

    //if statement has a label, store in json
    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;
}

//unserialization to run instructions
void JeqStatement::unserialize(const QJsonObject &json) const{

}
