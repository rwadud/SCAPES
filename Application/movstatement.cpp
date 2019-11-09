#include "movstatement.h"

MovStatement::MovStatement(){}

MovStatement::~MovStatement(){

}

void MovStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
}

void MovStatement::run(){

}
