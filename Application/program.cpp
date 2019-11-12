#include "program.h"
#include "compilecontrol.h"
#include <QStringList>
#include <QDebug>


Program::Program(QString fileName)
{
    filename = fileName;
    prgmVars = new VHash;
    stmtList = new StatementList;
}

Program::~Program()
{
   // delete the contained objects
   delete stmtList;
   delete prgmVars;
}


QString Program:: getFileName()
{
    return filename;
}


bool Program::compile(QString *inSrcTxt, QString *outCmplTxt, QString *errTxt)
{
    *outCmplTxt = "";
    *errTxt = "";

    CompileControl compiler;

    if(!compiler.compile(inSrcTxt, outCmplTxt, errTxt, stmtList, prgmVars))
        return false;

    return true;
}
