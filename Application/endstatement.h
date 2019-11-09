#ifndef ENDSTATEMENT_H
#define ENDSTATEMENT_H

#include "statement.h"

class EndStatement : public Statement
{
public:
    EndStatement();
    ~EndStatement();
    void compile(QString *instr);
    void run();
};

#endif // ENDSTATEMENT_H
