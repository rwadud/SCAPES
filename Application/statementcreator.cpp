#include "statementcreator.h"

Statement* StatementCreator::Create (QString &instructionType) {

    Statement *stmt = nullptr;

    if(instructionType == "DciStatement")
        stmt = new DciStatement();
    if(instructionType == "DcaStatement")
        stmt = new DcaStatement();
    if(instructionType == "RdiStatement")
        stmt = new RdiStatement();
    if(instructionType == "PrtStatement")
        stmt = new PrtStatement();
    if(instructionType == "MovStatement")
        stmt = new MovStatement();
    if(instructionType == "AddStatement")
        stmt = new AddStatement();
    if(instructionType == "CmpStatement")
        stmt = new CmpStatement();
    if(instructionType == "JlsStatement")
        stmt = new JlsStatement();
    if(instructionType == "JmrStatement")
        stmt = new JmrStatement();
    if(instructionType == "JeqStatement")
        stmt = new JeqStatement();
    if(instructionType == "JmpStatement")
        stmt = new JmpStatement();
    if(instructionType == "EndStatement")
        stmt = new EndStatement();

    return stmt;
}
