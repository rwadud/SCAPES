#include "dcastatement.h"
#include "arrayvariable.h"
#include "integerliteral.h"

//constructor
DcaStatement::DcaStatement(){}

//destructor
DcaStatement::~DcaStatement(){

}

//compile function for dca statement
bool DcaStatement::compile(Token *tokens, QString *errMsg){
    // check if label exist and updates references
    if(!updateLabel(tokens, errMsg)) {
        return false;
    }
    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    QString arg1 = tokens->getArg1();
    QString arg2 = tokens->getArg2();
    //create variables or check if they exist in prgmVars
    if(env->contains(arg1)){
        *errMsg = arg1+ " already defined";
        return false;
    } else {
         Identifier *arr = new ArrayVariable(arg1, arg2.toInt());
         env->insert(arg1,arr);
         op1 = new Operand(arr);
         op2 = new Operand(new IntegerLiteral(arg2));
    }
    return true;
}

//runs the instruction
void DcaStatement::run(QString &result){
}

//serializes instruction for compilation as a json
void DcaStatement::serialize(QJsonObject &json){
    QJsonObject jid1;
    QJsonObject jid2;
    //store statement type in json
    json["statement"] = "dca";

    //if statement has a label, store in json
    if(hasLabel()){
        json["label"] = label->getName();
    }

    op1->getIdentifier()->serialize(jid1);
    op2->getIdentifier()->serialize(jid2);
    //store operands in json
    json["op1"] = jid1;
    json["op2"] = jid2;
}

//unserialization to run instructions
void DcaStatement::unserialize(const QJsonObject &json){
    Token *tokens = Statement::tokenize(json);
    updateLabel(tokens, nullptr);
    QString label = json["label"].toString();
    QString arg1 = json["op1"]["name"].toString();
    QString arg2 = json["op2"]["name"].toString();
    Identifier *id = new ArrayVariable(arg1, arg2.toInt());
    env->insert(arg1, id);
    op1 = new Operand(id);
    op2 = new Operand(new IntegerLiteral(arg2));
}
