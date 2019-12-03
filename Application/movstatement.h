#ifndef MOVSTATEMENT_H
#define MOVSTATEMENT_H

#include "statement.h"

class MovStatement : public Statement
{
public:
    MovStatement();
    ~MovStatement();
    bool compile(Token *tokens, QString *errMsg);
    bool run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;

private:
    const static int numArgs = 2;
};

#endif // MOVSTATEMENT_H
