#ifndef PROGRAM_H
#define PROGRAM_H
#include <QString>
#include <QList>


class Program
{
public:
    Program(QString fileName);
    ~Program();
    QString getFileName();
    bool compile(QString *inSrcTxt, QString *outCmplTxt, QString *errTxt);

private:
    QString filename;

};

#endif // PROGRAM_H
