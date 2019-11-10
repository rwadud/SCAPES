#ifndef DCISTATEMENT_H
#define DCISTATEMENT_H

#include "statement.h"

class DciStatement : public Statement
{
private:
    Operand* op1;

public:
    DciStatement();
    ~DciStatement();
    void compile(QString *instr);
    void run();
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;
};

#endif // DCISTATEMENT_H
