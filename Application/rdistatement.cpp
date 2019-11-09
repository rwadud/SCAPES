#include "rdistatement.h"

RdiStatement::RdiStatement(){}

RdiStatement::~RdiStatement(){

}

void RdiStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete

    //split the instr into tokens/arguments
    QStringList tokens = (*instr).split(" ");
    QString arg1_name = tokens[1];

    //do some additional validation on arguments

    if(tokens.length() > 2){
        // too many argumets error
    }

    if(arg1_name.contains(QRegExp("[^a-zA-Z0-9-_]"))){
        // invalid characters
    }

    //create variables or check if they exist in prgmVars
    if(prgmVars->contains(arg1_name)){
        Identifier *variable = prgmVars->find(arg1_name);
        op1 = new Operand(variable);
    } else {
        //variable not declared yet
    }
}

void RdiStatement::run(){

}
