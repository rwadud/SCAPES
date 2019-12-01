#ifndef RUNCONTROL_H
#define RUNCONTROL_H

#include <QString>
#include "statement.h"
#include "statementlist.h"
#include "programenviroment.h"

class RunControl
{
public:
    RunControl();
    ~RunControl();
    bool run();
    void regnerate();
};

#endif // RUNCONTROL_H
