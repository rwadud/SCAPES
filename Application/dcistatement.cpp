#include "dcistatement.h"

DciStatement::DciStatement(){}

DciStatement::~DciStatement(){

}

void DciStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
    qDebug() << test;
    //split the instr into tokens/arguments
    //do some additional validation on arguments
    //create variables or check if they exist in prgmVars
}

void DciStatement::run(){

}
