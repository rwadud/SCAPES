#include "flatfileimp.h"
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>

FlatFileImp::FlatFileImp()
{

}
FlatFileImp::~FlatFileImp()
{

}
bool FlatFileImp::getSourceData(QString fileName, QString *outData, QString *outErrTxt)
{
    QFile   file(fileName);

    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        *outErrTxt =  file.errorString();
        return false;
    }

    QTextStream  textStream(&file);
    *outData = textStream.readAll();

    file.close();

    return true;
}
bool FlatFileImp::setSourceData(QString fileName, QString *inData, QString *outErrTxt)
{
    QFile   file(fileName);

    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        *outErrTxt =  file.errorString();
        return false;
    }
    QTextStream  textStream(&file);
    textStream << *inData;

    file.flush();
    file.close();

    return true;
}

