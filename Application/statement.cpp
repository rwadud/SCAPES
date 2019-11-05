#include "statement.h"

Statement::Statement(/* args */)
{
}

Statement::~Statement()
{
}

void Statement::setLabel(QString str)
{
    this->label.setName(str);
}
