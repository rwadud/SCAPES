#include "dcistatement.h"
#include "variable.h"

DciStatement::DciStatement(){}

DciStatement::~DciStatement(){

}

void DciStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
    qDebug() << test;

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
        // variable alreday declared
    } else {
         Identifier *variable = new Variable(arg1_name);
         prgmVars->insert(arg1_name,variable);
         op1 = new Operand(variable);
    }

}

void DciStatement::run(){

}
