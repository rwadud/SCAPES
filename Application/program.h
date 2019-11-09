#ifndef PROGRAM_H
#define PROGRAM_H
#include <QString>
#include <QList>
#include "statement.h"
#include "vhash.h"

class Program
{
public:
    Program(QString fileName);
    ~Program();
    QString getFileName();
    bool compile(QString *inSrcTxt, QString *outCmplTxt, QString *errTxt);
    void parseInstructions(QString &line, QString &instructionStr);

private:
    QString filename;
    QVector<Statement*> statements;
    VHash* prgmVars;

};

#endif // PROGRAM_H
