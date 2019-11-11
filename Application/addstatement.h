#ifndef ADDSTATEMENT_H
#define ADDSTATEMENT_H

#include "statement.h"

class AddStatement : public Statement
{
public:
    AddStatement();
    ~AddStatement();
    bool compile(Token *tokens, QString *errMsg);
    bool run();
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;

private:
    const static int numArgs = 2;
};

#endif // ADDSTATEMENT_H
