#ifndef COMPILEOPTION_H
#define COMPILEOPTION_H
#include "maincontroller.h"

class CompileOption
{
public:
    CompileOption();
    bool compile(MainController *ctlr, QString *inText);
};

#endif // COMPILEOPTION_H
