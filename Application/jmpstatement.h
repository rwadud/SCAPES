#ifndef JMPSTATEMENT_H
#define JMPSTATEMENT_H

#include "statement.h"

class JmpStatement : public Statement
{
private:
    Operand* op1;
    const QString test = "object splicing is not happening!!!"; //delete

public:
    JmpStatement();
    ~JmpStatement();
    void compile(QString *instr);
    void run();
};

#endif // JMPSTATEMENT_H
