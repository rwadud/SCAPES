#ifndef DCISTATEMENT_H
#define DCISTATEMENT_H

#include "statement.h"

class DciStatement : public Statement
{
private:
    Operand op1;
    const QString test = "object splicing is not happening!!!"; //delete
public:
    DciStatement();
    ~DciStatement();
    void compile(QString *instr);
    void run();
};

#endif // DCISTATEMENT_H
