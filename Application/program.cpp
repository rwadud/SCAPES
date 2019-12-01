#include "program.h"
#include "compilecontrol.h"
#include "runcontrol.h"
#include <QStringList>
#include <QDebug>
#include "flatfileimp.h" //delete

Program::Program(QString fileName)
{
    filename = fileName;
    env = new ProgramEnviroment;
    stmtList = new StatementList;
}

Program::~Program()
{
   // delete the contained objects
   delete stmtList;
   delete env;
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

    if(!compiler.compile(inSrcTxt, outCmplTxt, errTxt, stmtList, env))
        return false;

    return true;
}


bool Program::run(QString *inJsonTxt, QString *errTxt)
{
    *errTxt = "";
    RunControl executor;

    //TEMPORARILY LOADING JSON DIRECTLY
    FlatFileImp storage;
    QString jsonFile = filename+".json";
    storage.getSourceData(jsonFile, inJsonTxt, errTxt);

    if(!executor.run(inJsonTxt, errTxt))
        return false;

    return true;
}
