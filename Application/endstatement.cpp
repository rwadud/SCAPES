#include "endstatement.h"

//constructor
EndStatement::EndStatement(){}

//destructor
EndStatement::~EndStatement(){

}

//compile function for end statement
void EndStatement::compile(Token *tokens){
    // check if label exist and updates references
    updateLabel(tokens);

    // validate argument/label names
    validate(numArgs, tokens);

    //update operand references
    updateOperands(numArgs, tokens);
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
    updateLabel(tokens);
    updateOperands(numArgs, tokens);
}
