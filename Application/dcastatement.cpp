#include "dcastatement.h"
#include "arrayvariable.h"

//constructor
DcaStatement::DcaStatement(){}

//destructor
DcaStatement::~DcaStatement(){

}

//compile function for dca statement
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

//runs the instruction
bool DcaStatement::run(){
    return true;
}

//serializes instruction for compilation as a json
void DcaStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;
    //store statement type in json
    json["statementType"] = "DcaStatement";

    //if statement has a label, store in json
    if(hasLabel()){
        json["labelName"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    //store operands in json
    json["op1"] = jsonIdentifier1;
}

//unserialization to run instructions
void DcaStatement::unserialize(const QJsonObject &json) const{

}
