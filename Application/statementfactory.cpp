#include "statementfactory.h"

Statement* StatementFactory::NewStatement(QString &instructionStr, QString &data)
{
    if(instructionStr == "dci")
        return new DciStatement;
    if(instructionStr == "dca")
        return new DcaStatement;
    if(instructionStr == "rdi")
        return new RdiStatement;
    if(instructionStr == "prt")
        return new PrtStatement;
    if(instructionStr == "mov")
        return new MovStatement;
    if(instructionStr == "add")
        return new AddStatement;
    if(instructionStr == "cmp")
        return new CmpStatement;
    if(instructionStr == "jls")
        return new JlsStatement;
    if(instructionStr == "jmr")
        return new JmrStatement;
    if(instructionStr == "jeq")
        return new JeqStatement;
    if(instructionStr == "jmp")
        return new JmpStatement;
    if(instructionStr == "end")
        return new EndStatement;
    if(instructionStr == "label"){
        //some extra work required here

        return new EndStatement;
    }

    return nullptr;
}
