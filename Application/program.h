#ifndef PROGRAM_H
#define PROGRAM_H
#include <QString>
#include <QList>
#include "programenviroment.h"
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
    ProgramEnviroment* env;
};

#endif // PROGRAM_H
