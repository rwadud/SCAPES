#ifndef OPERAND_H
#define OPERAND_H

#include "identifier.h"

//This class is the operand of a statement
class Operand
{
private:
    Identifier *identifier = nullptr;
public:
    Operand(Identifier *id);
    ~Operand();
    Identifier* getIdentifier();
};

#endif
