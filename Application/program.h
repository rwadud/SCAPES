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
    void parseInstructions(QString &line, QString &instructionType, QString &labelName);

private:
    QString filename;
    StatementList* stmtList;
    VHash* prgmVars;
};

#endif // PROGRAM_H
