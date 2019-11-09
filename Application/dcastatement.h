#ifndef DCASTATEMENT_H
#define DCASTATEMENT_H

#include "statement.h"

class DcaStatement : public Statement
{
public:
    DcaStatement();
    ~DcaStatement();
    void compile(QString *instr);
    void run();
};

#endif // DCASTATEMENT_H
