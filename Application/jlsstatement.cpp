#include "jlsstatement.h"

//constructor
JlsStatement::JlsStatement(){}

//destructor
JlsStatement::~JlsStatement(){

}
//compile function for jls statement
void JlsStatement::compile(Token *tokens){
    // check if label exist and updates references
    updateLabel(tokens);

    // validate argument/label names
    validate(numArgs, tokens);

    //update operand references
    updateOperands(numArgs, tokens);

    //check if operand type is correct
    if( !op1->getIdentifier()->isLabel() ){
        error = "invalid operand type: " + op2->getIdentifier()->getName();
        throw std::logic_error(error.toUtf8());
    }
}

//runs the instruction
void JlsStatement::run(QString &result){
    Identifier *label = op1->getIdentifier();
    if(!label->isInitialized()){
        throw std::runtime_error("Label not initialized: " + label->getName().toUtf8());
    }
    if(env->getCmpFlag()==LESS){
        result = "Jumping to label " + label->getName() + " at index " + QString::number(label->getValue());
        env->setJmpIndex(label->getValue());
    }
}

//serializes instruction for compilation as a json
void JlsStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    //store statement type in json
    json["statement"] = "jls";

    if(hasLabel()){
        json["label"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;
}

//unserialization to run instructions
void JlsStatement::unserialize(const QJsonObject &json) {
    Token *tokens = Statement::tokenize(json);
    updateLabel(tokens);
    updateOperands(numArgs, tokens);
}
