#ifndef PROGRAM_H
#define PROGRAM_H
#include <QString>
#include <QList>
#include "vhash.h"
#include "statementlist.h"

class Program
{
public:
    Program(QString fileName);
    ~Program();
    QString getFileName();
    bool compile(QString *inSrcTxt, QString *outCmplTxt, QString *errTxt);

private:
    QString filename;
    StatementList* stmtList;
    VHash* prgmVars;
};

#endif // PROGRAM_H
