#ifndef PROGRAM_H
#define PROGRAM_H
#include <QString>
#include <QList>
#include "statement.h"

class Program
{
public:
    Program(QString fileName);
    ~Program();
    QString getFileName();
    bool compile(QString *inSrcTxt, QString *outCmplTxt, QString *errTxt);
    bool instructionValidator(QStringList &tokens, QString &instructionStr);

private:
    QString filename;
    QVector<Statement*> statements;
    QMap<QString, Identifier*> programVariables;

};

#endif // PROGRAM_H
