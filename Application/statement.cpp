#include "statement.h"

Statement::Statement(){}

Statement::~Statement()
{
}

void Statement::setLabel(QString str)
{
    this->label.setName(str);
}

void Statement::setEnviroment(VHash *env){
    prgmVars = env;
}
