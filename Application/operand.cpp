#include "operand.h"

Operand::Operand(Identifier *id) : identifier(id)
{
}

Operand::~Operand()
{
}

Identifier* Operand::getIdentifier(){
    return identifier;
}
