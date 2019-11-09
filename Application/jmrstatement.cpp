#include "jmrstatement.h"

JmrStatement::JmrStatement(){}

JmrStatement::~JmrStatement(){

}

void JmrStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
}

void JmrStatement::run(){

}
