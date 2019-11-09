#include "prtstatement.h"

PrtStatement::PrtStatement(){}

PrtStatement::~PrtStatement(){

}

void PrtStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
}

void PrtStatement::run(){

}
