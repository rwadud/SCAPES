#ifndef COMPILECONTROL_H
#define COMPILECONTROL_H

#include <QString>
#include "statement.h"
#include "statementlist.h"
#include "vhash.h"
#include "token.h"

//Compiles program
class CompileControl
{
public:
    CompileControl();
    ~CompileControl();
    bool compile(QString *inSrcTxt, QString *outCmplTxt, QString *errMsg, StatementList *stmtList, VHash *prgmVars);
    void generateJson(Statement*,QString*);

};

#endif // COMPILECONTROL_H
