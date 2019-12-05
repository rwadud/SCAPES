#include "dcastatement.h"
#include "arrayvariable.h"
#include "integerliteral.h"

//constructor
DcaStatement::DcaStatement(){}

//destructor
DcaStatement::~DcaStatement(){

}

//compile function for dca statement
void DcaStatement::compile(Token *tokens){
    // check if label exist and updates references
    updateLabel(tokens);

    // validate argument/label names
    validate(numArgs, tokens);

    QString arg1 = tokens->getArg1();
    QString arg2 = tokens->getArg2();
    //create variables or check if they exist in prgmVars
    if(env->contains(arg1)){
        error = arg1+ " already defined";
        throw std::logic_error(error.toUtf8());
    } else {
        Identifier *arr;
        if(env->contains(arg2)){
            Identifier *var = env->get(arg2);
            arr = new ArrayVariable(arg1, var->getValue());
            op2 = new Operand(var);
        } else {
            arr = new ArrayVariable(arg1, arg2.toInt());
            op2 = new Operand(new IntegerLiteral(arg2));
        }
         op1 = new Operand(arr);
         env->insert(arg1,arr);
    }
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
    updateLabel(tokens);

    QString arg1 = tokens->getArg1();
    QString arg2 = tokens->getArg2();
    
    Identifier *arr;
    if(env->contains(arg2)){
        Identifier *var = env->get(arg2);
        arr = new ArrayVariable(arg1, var->getValue());
        op2 = new Operand(var);
    } else {
        arr = new ArrayVariable(arg1, arg2.toInt());
        op2 = new Operand(new IntegerLiteral(arg2));
    }

    op1 = new Operand(arr);
    env->insert(arg1,arr);
}
