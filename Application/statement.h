#ifndef STATEMENT_H
#define STATEMENT_H

#include <QString>
#include "operand.h"
#include "label.h"
#include "vhash.h"
#include "token.h"
#include <QDebug>
#include "serializable.h"

class Statement : public Serializable
{
public:
    Statement();
    virtual ~Statement();
    virtual bool compile(Token *tokens, QString *errMsg) = 0;
    virtual bool run() = 0;
    void setLabel(Identifier *label);
    void setEnviroment(VHash *env);
    bool hasLabel();

protected:
    VHash *prgmVars = nullptr;
    Identifier* label = nullptr;
    Operand *op1 = nullptr;
    Operand *op2 = nullptr;
    bool validate(int numArgs, Token *tokens, QString *errMsg);
    bool updateOperands(int numArgs, Token *tokens, QString *errMsg);
};


#endif
