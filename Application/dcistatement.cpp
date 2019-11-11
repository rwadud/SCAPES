#include "dcistatement.h"
#include "variable.h"

DciStatement::DciStatement(){}

DciStatement::~DciStatement(){

}

bool DciStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    QString arg1 = tokens->getArg1();
    //create variables or check if they exist in prgmVars
    if(prgmVars->contains(arg1)){
        *errMsg = arg1+ " already defined";
        return false;
    } else {
         Identifier *var = new Variable(arg1);
         prgmVars->insert(arg1,var);
         op1 = new Operand(var);
    }

    return true;
}

bool DciStatement::run(){
    return true;
}

void DciStatement::serialize(QJsonObject &json){

}

void DciStatement::unserialize(const QJsonObject &json) const{

}
