#ifndef VARIABLE_H
#define VARIABLE_H

#include "identifier.h"

class Variable : public Identifier 
{
private:
    int value;
public:
    Variable(QString str);
    ~Variable();
};

#endif
