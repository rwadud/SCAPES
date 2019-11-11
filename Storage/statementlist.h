#ifndef STATEMENTLIST_H
#define STATEMENTLIST_H

#include <QVector>
#include "statement.h"

class StatementList
{
public:
    StatementList();
    ~StatementList();
    Statement* get(int i);
    void add(Statement* stmt);
    int size();

private:
    QVector<Statement*> statements;
};

#endif // STATEMENTLIST_H
