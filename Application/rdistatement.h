#ifndef RDISTATEMENT_H
#define RDISTATEMENT_H

#include "statement.h"

class RdiStatement : public Statement
{
private:
    Operand *op1;

public:
    RdiStatement();
    ~RdiStatement();
    void compile(QString *instr);
    void run();
};

#endif // RDISTATEMENT_H
