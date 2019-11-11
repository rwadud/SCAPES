#include "statementcreator.h"

Statement* StatementCreator::Create (QString &instr) {

    Statement *stmt = nullptr;

    if(instr == "dci")
        stmt = new DciStatement();
    if(instr == "dca")
        stmt = new DcaStatement();
    if(instr == "rdi")
        stmt = new RdiStatement();
    if(instr == "prt")
        stmt = new PrtStatement();
    if(instr == "mov")
        stmt = new MovStatement();
    if(instr == "add")
        stmt = new AddStatement();
    if(instr == "cmp")
        stmt = new CmpStatement();
    if(instr == "jls")
        stmt = new JlsStatement();
    if(instr == "jmr")
        stmt = new JmrStatement();
    if(instr == "jeq")
        stmt = new JeqStatement();
    if(instr == "jmp")
        stmt = new JmpStatement();
    if(instr == "end")
        stmt = new EndStatement();

    return stmt;
}
