#include "endstatement.h"

//constructor
EndStatement::EndStatement(){}

//destructor
EndStatement::~EndStatement(){

}

//compile function for end statement
bool EndStatement::compile(Token *tokens, QString *errMsg){
    //store statement type in json
    return validate(numArgs, tokens, errMsg);
}

//run the instruction
bool EndStatement::run(){
    qDebug() << "End of Program";
    return false;
}

//serializes instruction for compilation as a json
void EndStatement::serialize(QJsonObject &json){
    //store statement type in json
    json["statement"] = "end";
    if(hasLabel()){
        json["label"] = label->getName();
    }
}

//unserialization to run instructions
void EndStatement::unserialize(const QJsonObject &json) const{

}
