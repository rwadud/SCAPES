#ifndef JEQSTATEMENT_H
#define JEQSTATEMENT_H

#include "statement.h"

class JeqStatement : public Statement
{
public:
    JeqStatement();
    ~JeqStatement();
    void compile(QString *instr);
    void run();
};

#endif // JEQSTATEMENT_H
