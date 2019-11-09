#ifndef CMPSTATEMENT_H
#define CMPSTATEMENT_H

#include "statement.h"

class CmpStatement : public Statement
{
public:
    CmpStatement();
    ~CmpStatement();
    void compile(QString *instr);
    void run();
};

#endif // CMPSTATEMENT_H
