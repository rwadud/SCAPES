#include "statement.h"
#include "arrayvariable.h"
#include "integerliteral.h"
#include "stringliteral.h"

Statement::Statement(){}

Statement::~Statement()
{
}

void Statement::setLabel(Identifier *label)
{
    this->label = label;
}

bool Statement::maybeSetLabel(Token *tokens, QString *errMsg){
    return true;
}

//do some additional validation on arguments & label names
bool Statement::validate(int numArgs, Token *tokens, QString *errMsg){

    if(tokens->length() > numArgs+1){
        *errMsg = "too many arguments";
        return false;
    }

    QString arg1 = tokens->getArg1();
    QString arg2 = tokens->getArg1();
    // Check the label for invalid characters
    if(numArgs >= 1 && !Token::isValidIdentifierName(arg1)){ // Check the label for invalid characters
        *errMsg = "invalid characters detected";
        return false;
    }

    if(numArgs == 2 && !Token::isValidIdentifierName(arg2)){
        *errMsg = "invalid characters detected";
        return false;
    }

    //set label, if statement has an associated label
    if(tokens->hasLabel()){
        QString labelName = tokens->getLabel();
        if( !(label = prgmVars->get(labelName)) ){
            *errMsg = "undefined reference to identifier: " +labelName;
            return false;
        }
    }

    return true;
}

//update operand references
bool Statement::updateOperands(int numArgs, Token *tokens, QString *errMsg){
    int literalsDetected = 0;
    for(int i = 1; i <= numArgs; i++){
        QString arg = tokens->getArg(i);
        int arrayIndex = 0;
        bool arrayDetected = false;
        if(Token::isArrayElement(arg)){
            arrayDetected = true;
            QString str = arg.split("+")[0].remove("$");
            QString tmp = arg.split("+")[1];
            arrayIndex = tmp.toInt();
            arg = str;
        }
        if(prgmVars->contains(arg)){  // Check if the label is real or not
            Identifier *var = prgmVars->get(arg);
            if(i==1)
                op1 = new Operand(var);
            if(i=2)
                op2 = new Operand(var);
            if(arrayDetected){
                ArrayVariable *arr = dynamic_cast<ArrayVariable*>(var);
                arr->setIndex(arrayIndex);
            }
        }
        else{
            QString literalType;
            if(Token::isLiteral(arg, literalType)){
                Identifier *literal = Identifier::createLiteral(literalType, arg);
                prgmVars->insert(arg, literal);
                if(i==1)
                    op1 = new Operand(literal);
                if(i=2)
                    op2 = new Operand(literal);
                literalsDetected++;
            } else{
                *errMsg = "undefined reference to identifier: " + arg;
                return false;
            }
        }
    }
    if(literalsDetected > 1){
        *errMsg = "too many literals detected";
        return false;
    }
    return true;
}

void Statement::setEnviroment(VHash *env){
    prgmVars = env;
}

