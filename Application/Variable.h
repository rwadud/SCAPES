#ifndef VARIABLE_H
#define VARIABLE_H

#include "Identifier.h"

class Variable : public Identifier 
{
private:
    int value;
public:
    Variable(/* args */);
    ~Variable();
};

#endif