#ifndef RUNCONTROL_H
#define RUNCONTROL_H

#include <QString>
#include <QTextBrowser>
#include "statement.h"
#include "statementlist.h"
#include "programenviroment.h"

class RunControl
{
public:
    RunControl();
    ~RunControl();
    bool run(QString *inJsonTxt, QTextBrowser *resultConsole, QString *errMsg, StatementList *stmtList, ProgramEnviroment *env);
    void regenerate(QString *inJsonTxt);

private:
    ProgramEnviroment *env;
    StatementList *slist;
};

#endif // RUNCONTROL_H
