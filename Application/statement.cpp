#include "statement.h"

Statement::Statement(){}

Statement::~Statement()
{
}

void Statement::setLabel(QString str)
{

}

void Statement::setEnviroment(VHash *env){
    prgmVars = env;
}
