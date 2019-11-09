#ifndef MOVSTATEMENT_H
#define MOVSTATEMENT_H

#include "statement.h"

class MovStatement : public Statement
{
public:
    MovStatement();
    ~MovStatement();
    void compile(QString *instr);
    void run();
};

#endif // MOVSTATEMENT_H
