#ifndef RDISTATEMENT_H
#define RDISTATEMENT_H

#include "statement.h"

class RdiStatement : public Statement
{
public:
    RdiStatement();
    ~RdiStatement();
    bool compile(Token *tokens, QString *errMsg);
    bool run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;

private:
    const static int numArgs = 1;
};

#endif // RDISTATEMENT_H
