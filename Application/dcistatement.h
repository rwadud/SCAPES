#ifndef DCISTATEMENT_H
#define DCISTATEMENT_H

#include "statement.h"

class DciStatement : public Statement
{
private:
    Operand op1;
public:
    DciStatement();
};

#endif // DCISTATEMENT_H
