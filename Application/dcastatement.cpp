#include "dcastatement.h"

DcaStatement::DcaStatement(){}

DcaStatement::~DcaStatement(){

}

void DcaStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
}

void DcaStatement::run(){

}
