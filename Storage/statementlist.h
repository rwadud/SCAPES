#ifndef STATEMENTLIST_H
#define STATEMENTLIST_H

#include <QVector>
#include "statement.h"

//Encapsulated QVector used to store a list of statements
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
