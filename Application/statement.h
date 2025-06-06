#ifndef STATEMENT_H
#define STATEMENT_H

#include "operand.h"
#include "label.h"
#include "programenviroment.h"
#include "token.h"
#include "serializable.h"
#include "arrayvariable.h"
#include "arrayelementindex.h"
#include "identifiercreator.h"
#include <QString>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

//Abstract statement class
class Statement : public Serializable
{
public:
    Statement();
    virtual ~Statement();
    virtual void compile(Token *tokens) = 0;
    virtual void run(QString &result) = 0;
    void setLabel(Identifier *label);
    void setEnviroment(ProgramEnviroment *env);
    bool hasLabel();
    Token* tokenize(const QJsonObject &json);

protected:
    ProgramEnviroment *env = nullptr; //program variable enviroment
    Identifier* label = nullptr;
    Operand *op1 = nullptr; //Operand 1
    Operand *op2 = nullptr; //Operand 2
    QString error;
    int lineNumber;
    int getLineNumber();
    void setLineNumber(int);
    void validate(int numArgs, Token *tokens); //Validate argument/labels
    void updateOperands(int numArgs, Token *tokens); //update operands and label references
    void updateLabel(Token *tokens);
    //QString result;
};


#endif
