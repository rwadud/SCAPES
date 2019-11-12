#include "jlsstatement.h"

JlsStatement::JlsStatement(){}

JlsStatement::~JlsStatement(){

}

bool JlsStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    return true;
}

bool JlsStatement::run(){
    return true;
}

void JlsStatement::serialize(QJsonObject &json){
    json["statementType"] = "JlsStatement";

    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    json["op1"] = op1->serialize();
}

void JlsStatement::unserialize(const QJsonObject &json) const{

}
