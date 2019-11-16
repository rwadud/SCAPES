#ifndef RUNOPTION_H
#define RUNOPTION_H
#include "maincontroller.h"

class RunOption
{
public:
    RunOption();
    bool run(MainController *ctlr, QString *inText,QString *outText, QString *errText);
};

#endif // RUNOPTION_H
