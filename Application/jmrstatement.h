#ifndef JMRSTATEMENT_H
#define JMRSTATEMENT_H

#include "statement.h"

class JmrStatement : public Statement
{
private:
    Operand* op1;

public:
    JmrStatement();
    ~JmrStatement();
    void compile(QString *instr);
    void run();
};

#endif // JMRSTATEMENT_H
