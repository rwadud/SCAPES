#include "variable.h"

Variable::Variable(QString str) : Identifier(str){}

Variable::~Variable()
{
}

void Variable::setValue(int v){
    value = v;
}
