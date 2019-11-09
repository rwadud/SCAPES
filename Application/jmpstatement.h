#ifndef JMPSTATEMENT_H
#define JMPSTATEMENT_H

#include "statement.h"

class JmpStatement : public Statement
{
public:
    JmpStatement();
    ~JmpStatement();
    void compile(QString *instr);
    void run();
};

#endif // JMPSTATEMENT_H
