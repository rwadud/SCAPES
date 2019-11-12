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
         var->setTypeName("variable");
         prgmVars->insert(arg1,var);
         op1 = new Operand(var);
    }

    return true;
}

bool DciStatement::run(){
    return true;
}

void DciStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;

    json["statementType"] = "DciStatement";

    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;
}

void DciStatement::unserialize(const QJsonObject &json) const{

}
