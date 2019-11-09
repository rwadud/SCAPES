#ifndef JMRSTATEMENT_H
#define JMRSTATEMENT_H

#include "statement.h"

class JmrStatement : public Statement
{
public:
    JmrStatement();
    ~JmrStatement();
    void compile(QString *instr);
    void run();
};

#endif // JMRSTATEMENT_H
