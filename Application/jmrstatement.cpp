#include "jmrstatement.h"

JmrStatement::JmrStatement(){}

JmrStatement::~JmrStatement(){

}

void JmrStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
    //parse the instr so we can access JUST the label
    qDebug() << test;

    //split/ the instr into tokens/arguments
    QStringList tokens = (*instr).split(" ");   //split the entire line into an array
    QString arg1_name = tokens[1];

    //do some additional validation on arguments

    if(tokens.length() > 2){    //check length of the statement
        // too many argumets error
    }

    if(arg1_name.contains(QRegExp("[^a-zA-Z0-9-_]"))){  // Check the label for invalid characters
        // Invalid characters
    }
    if(prgmVars->contains(arg1_name)){  // Check if the label is real or not
        op1 = new Operand(prgmVars->find(arg1_name));
    }
    else{
        //ERROR: the label does not exist
    }
}

void JmrStatement::run(){

}
