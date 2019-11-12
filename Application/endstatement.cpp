#include "endstatement.h"

//constructor
EndStatement::EndStatement(){}

//destructor
EndStatement::~EndStatement(){

}

//compile function for end statement
bool EndStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete
    //store statement type in json
    return validate(numArgs, tokens, errMsg);
}

//run the instruction
bool EndStatement::run(){
    return true;
}

//serializes instruction for compilation as a json
void EndStatement::serialize(QJsonObject &json){
    //store statement type in json
    json["statementType"] = "EndStatement";
}

//unserialization to run instructions
void EndStatement::unserialize(const QJsonObject &json) const{

}
