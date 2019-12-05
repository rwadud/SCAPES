#include "operand.h"

Operand::Operand(Identifier *id) : identifier(id)
{
}

Operand::~Operand()
{
    //delete identifier;
}

Identifier* Operand::getIdentifier(){
    return identifier;
}
