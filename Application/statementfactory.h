#ifndef STATEMENTFACTORY_H
#define STATEMENTFACTORY_H

#include "statement.h"
#include "dcistatement.h"
#include "dcastatement.h"
#include "rdistatement.h"
#include "addstatement.h"
#include "jmpstatement.h"
#include "jmrstatement.h"
#include "jlsstatement.h"
#include "jeqstatement.h"
#include "endstatement.h"
#include "cmpstatement.h"
#include "movstatement.h"
#include "prtstatement.h"
#include "label.h"

#include <QString>

class StatementFactory{
    public:
        static Statement *NewStatement(QString &instructionStr, QString &data);
 };

#endif // STATEMENTFACTORY_H
