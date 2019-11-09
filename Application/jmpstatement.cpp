#include "jmpstatement.h"

JmpStatement::JmpStatement(){}

JmpStatement::~JmpStatement(){

}

void JmpStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
}

void JmpStatement::run(){

}
