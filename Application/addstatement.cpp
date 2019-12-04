#include "addstatement.h"
#include "variable.h"
#include "arrayvariable.h"
#include "integerliteral.h"

//constructor
AddStatement::AddStatement(){}

//destructor
AddStatement::~AddStatement(){

}

//compile function for add statement
bool AddStatement::compile(Token *tokens, QString *errMsg){
    // validate argument/label names
    if(!validate(numArgs, tokens, errMsg))
        return false;

    //update operand references
    if(!updateOperands(numArgs, tokens, errMsg))
        return false;

    if( !(op1->getIdentifier()->isArray() || op1->getIdentifier()->isVariable() || op1->getIdentifier()->isIntegerLiteral()) ){
        *errMsg = "invalid operand 1 type: " + op1->getIdentifier()->getName();
        return false;
    }
    if( !(op2->getIdentifier()->isArray() || op2->getIdentifier()->isVariable()) ){
        *errMsg = "invalid operand 2 type: " + op2->getIdentifier()->getName();
        return false;
    }
    return true;
}

//runs the instruction
void AddStatement::run(QString &result){

    Identifier *id1 = op1->getIdentifier();
    Identifier *id2 = op2->getIdentifier();

    id2->setValue( id1->getValue() + id2->getValue() );

}

//serializes instruction for compilation as a json
void AddStatement::serialize(QJsonObject &json){
    QJsonObject jsonIdentifier1;
    QJsonObject jsonIdentifier2;

    //store statement type in json
    json["statement"] = "add";

    //if statement has a label, store in json
    if(hasLabel()){
        json["label"] = label->getName();
    }

    op1->getIdentifier()->serialize(jsonIdentifier1);
    op2->getIdentifier()->serialize(jsonIdentifier2);
    //store operands in json
    json["op1"] = jsonIdentifier1;
    json["op2"] = jsonIdentifier2;
}
//unserialization to run instructions
void AddStatement::unserialize(const QJsonObject &json) const{

}
