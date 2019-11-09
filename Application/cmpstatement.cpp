#include "cmpstatement.h"

CmpStatement::CmpStatement(){}

CmpStatement::~CmpStatement(){

}

void CmpStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
}

void CmpStatement::run(){

}
