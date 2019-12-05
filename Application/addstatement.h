#ifndef ADDSTATEMENT_H
#define ADDSTATEMENT_H

#include "statement.h"

class AddStatement : public Statement
{
public:
    AddStatement();
    ~AddStatement();
    void compile(Token *tokens);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 2;
};

#endif // ADDSTATEMENT_H
