#include "jlsstatement.h"

JlsStatement::JlsStatement(){}

JlsStatement::~JlsStatement(){

}

void JlsStatement::compile(QString *instr){
    qDebug() << "Compiling statement: " << *instr; //delete
}

void JlsStatement::run(){

}
