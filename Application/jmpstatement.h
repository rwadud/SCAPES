#ifndef JMPSTATEMENT_H
#define JMPSTATEMENT_H

#include "statement.h"
#include "cmpflag.h"

class JmpStatement : public Statement
{
public:
    JmpStatement();
    ~JmpStatement();
    bool compile(Token *tokens, QString *errMsg);
    bool run();
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;

private:
    const static int numArgs = 1;
};

#endif // JMPSTATEMENT_H
