#include "jeqstatement.h"

JeqStatement::JeqStatement(){}

JeqStatement::~JeqStatement(){

}

void JeqStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
}

void JeqStatement::run(){

}
