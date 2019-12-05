#ifndef RDISTATEMENT_H
#define RDISTATEMENT_H

#include "statement.h"

class RdiStatement : public Statement
{
public:
    RdiStatement();
    ~RdiStatement();
    void compile(Token *tokens);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 1;
};

#endif // RDISTATEMENT_H
