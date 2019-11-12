#include "jeqstatement.h"

//constructor
JeqStatement::JeqStatement(){}

//destructor
JeqStatement::~JeqStatement(){

}

//compile function for add statement
bool JeqStatement::compile(Token *tokens, QString *errMsg){
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
bool JeqStatement::run(){
    return true;
}

//serializes instruction for compilation as a json
void JeqStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    //store statement type in json
    json["statementType"] = "JeqStatement";

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
