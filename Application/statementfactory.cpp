#include "statementfactory.h"

Statement* StatementFactory::NewStatement(QString &instructionStr, QString &data)
{
    if(instructionStr == "DciStatement")
        return new DciStatement;
    if(instructionStr == "DcaStatement")
        return new DcaStatement;
    if(instructionStr == "RdiStatement")
        return new RdiStatement;
    if(instructionStr == "PrtStatement")
        return new PrtStatement;
    if(instructionStr == "MovStatement")
        return new MovStatement;
    if(instructionStr == "AddStatement")
        return new AddStatement;
    if(instructionStr == "CmpStatement")
        return new CmpStatement;
    if(instructionStr == "JlsStatement")
        return new JlsStatement;
    if(instructionStr == "JmrStatement")
        return new JmrStatement;
    if(instructionStr == "JeqStatement")
        return new JeqStatement;
    if(instructionStr == "JmpStatement")
        return new JmpStatement;
    if(instructionStr == "EndStatement")
        return new EndStatement;
    if(instructionStr == "Label"){
        //some extra work required here
    }

    return nullptr;
}
