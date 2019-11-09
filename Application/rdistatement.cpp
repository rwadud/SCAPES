#include "rdistatement.h"

RdiStatement::RdiStatement(){}

RdiStatement::~RdiStatement(){

}

void RdiStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
}

void RdiStatement::run(){

}
