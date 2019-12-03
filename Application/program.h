#ifndef PROGRAM_H
#define PROGRAM_H
#include <QString>
#include <QList>
#include <QTextBrowser>
#include "programenviroment.h"
#include "statementlist.h"

class Program
{
public:
    Program(QString fileName);
    ~Program();
    QString getFileName();
    bool compile(QString *inSrcTxt, QString *outCmplTxt, QString *errTxt);
    bool run(QString *compiledTxt, QTextBrowser *resultConsole, QString *errTxt);

private:
    QString filename;
    StatementList* stmtList;
    ProgramEnviroment* env;
};

#endif // PROGRAM_H
