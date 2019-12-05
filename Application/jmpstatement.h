#ifndef JMPSTATEMENT_H
#define JMPSTATEMENT_H

#include "statement.h"
#include "cmpflag.h"

class JmpStatement : public Statement
{
public:
    JmpStatement();
    ~JmpStatement();
    void compile(Token *tokens);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 1;
};

#endif // JMPSTATEMENT_H
