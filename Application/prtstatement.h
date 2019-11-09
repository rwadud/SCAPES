#ifndef PRTSTATEMENT_H
#define PRTSTATEMENT_H

#include "statement.h"

class PrtStatement : public Statement
{
public:
    PrtStatement();
    ~PrtStatement();
    void compile(QString *instr);
    void run();
};

#endif // PRTSTATEMENT_H
