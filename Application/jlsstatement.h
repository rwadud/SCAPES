#ifndef JLSSTATEMENT_H
#define JLSSTATEMENT_H

#include "statement.h"

class JlsStatement : public Statement
{
public:
    JlsStatement();
    ~JlsStatement();
    void compile(QString *instr);
    void run();
};

#endif // JLSSTATEMENT_H
