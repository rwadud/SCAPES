#include "endstatement.h"

EndStatement::EndStatement(){}

EndStatement::~EndStatement(){

}

void EndStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
}

void EndStatement::run(){

}
