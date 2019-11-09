#ifndef ADDSTATEMENT_H
#define ADDSTATEMENT_H

#include "statement.h"

class AddStatement : public Statement
{
public:
    AddStatement();
    ~AddStatement();
    void compile(QString *instr);
    void run();
};

#endif // ADDSTATEMENT_H
