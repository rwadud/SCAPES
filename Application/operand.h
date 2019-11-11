#ifndef OPERAND_H
#define OPERAND_H

#include "identifier.h"

class Operand
{
private:
    Identifier *identifier;
public:
    Operand(Identifier *id);
    ~Operand();
};

#endif
