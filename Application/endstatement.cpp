#include "endstatement.h"

//constructor
EndStatement::EndStatement(){}

//destructor
EndStatement::~EndStatement(){

}

//compile function for end statement
bool EndStatement::compile(Token *tokens, QString *errMsg){
    // check if label exist and updates references
    if(!updateLabel(tokens, errMsg)) {
        return false;
    }

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

//run the instruction
void EndStatement::run(QString &result){
    result = "End of Program";
    env->terminate();
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
void EndStatement::unserialize(const QJsonObject &json){
    Token *tokens = Statement::tokenize(json);
    updateLabel(tokens, nullptr);
    updateOperands(numArgs, tokens, nullptr);
}
