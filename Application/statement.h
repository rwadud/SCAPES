#ifndef STATEMENT_H
#define STATEMENT_H

#include <QString>
#include "operand.h"
#include "label.h"
#include "vhash.h"
#include <QDebug>

class Statement
{
private:
    /* data */
    Label label;

protected:
    VHash *prgmVars = nullptr;

public:
    Statement();
    virtual ~Statement();
    virtual void compile(QString *instr) = 0;
    virtual void run() = 0;
    void setLabel(QString str);
    void setEnviroment(VHash *env);
};


#endif
