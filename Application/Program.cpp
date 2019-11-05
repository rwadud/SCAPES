#include "program.h"
#include <QStringList>
#include <QDebug>
#include <QSet>

Program::Program(QString fileName)
{
    filename = fileName;

}

Program::~Program()
{
   // delete the contained objects
}


QString Program:: getFileName()
{
    return filename;
}


bool Program::compile(QString *inSrcTxt, QString *outCmplTxt, QString *errTxt)
{
    *outCmplTxt = "";
    *errTxt = "";

    qDebug()  << "file: " + filename; // To Be Removed
    qDebug()  << "inSrcTxt: " + *inSrcTxt; // To Be Removed
    //parse;
    //validate;

    // create identifiers
    // create statements

    // compile statements
    // generate json(or xml) output
    return true;
}

