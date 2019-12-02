#include "jlsstatement.h"

//constructor
JlsStatement::JlsStatement(){}

//destructor
JlsStatement::~JlsStatement(){

}
//compile function for jls statement
bool JlsStatement::compile(Token *tokens, QString *errMsg){
    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    //check if operand type is correct
    if( !op1->getIdentifier()->isLabel() ){
        *errMsg = "invalid operand type: " + op2->getIdentifier()->getName();
        return false;
    }
    return true;
}

//runs the instruction
bool JlsStatement::run(){
    Identifier *label = op1->getIdentifier();
    if(env->getCmpFlag()==LESS){
        qDebug() << "ready to jump to label " << label->getName() << " at index " << label->getValue();
        env->setJmpIndex(label->getValue());
    }
    return true;
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
void JlsStatement::unserialize(const QJsonObject &json) const{

}
