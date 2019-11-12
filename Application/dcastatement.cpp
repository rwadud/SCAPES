#include "dcastatement.h"
#include "arrayvariable.h"

DcaStatement::DcaStatement(){}

DcaStatement::~DcaStatement(){

}

bool DcaStatement::compile(Token *tokens, QString *errMsg){
    qDebug() << "Compiling statement: " << tokens->getInstr(); //delete

    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    QString arg1 = tokens->getArg1();
    QString arg2 = tokens->getArg2();
    //create variables or check if they exist in prgmVars
    if(prgmVars->contains(arg1)){
        *errMsg = arg1+ " already defined";
        return false;
    } else {
         Identifier *arr = new ArrayVariable(arg1, arg2.toInt());
         arr->setTypeName("array");
         prgmVars->insert(arg1,arr);
         op1 = new Operand(arr);
    }
    return true;
}

bool DcaStatement::run(){
    return true;
}

void DcaStatement::serialize(QJsonObject &json){

}

void DcaStatement::unserialize(const QJsonObject &json) const{

}
