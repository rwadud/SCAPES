#include "addstatement.h"

AddStatement::AddStatement(){}

AddStatement::~AddStatement(){

}

void AddStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
}

void AddStatement::run(){

}
