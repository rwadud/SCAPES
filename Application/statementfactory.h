#ifndef STATEMENTFACTORY_H
#define STATEMENTFACTORY_H

#include "statement.h"
#include <QString>

class StatementFactory{
    public:
        static Statement *NewStatement(QString &instructionStr, QString data);
 };

#endif // STATEMENTFACTORY_H
