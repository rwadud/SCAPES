#ifndef STATEMENT_H
#define STATEMENT_H

#include <QString>
#include "label.h"

class Statement
{
private:
    /* data */
    Label label;

public:
    Statement(/* args */);
    ~Statement();
    void compile(QString *instr);
    void run();
    void setLabel(QString str);
};


#endif
