#ifndef PRTSTATEMENT_H
#define PRTSTATEMENT_H

#include "statement.h"

class PrtStatement : public Statement
{
public:
    PrtStatement();
    ~PrtStatement();
    bool compile(Token *tokens, QString *errMsg);
    bool run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;

private:
    const static int numArgs = 1;
};

#endif // PRTSTATEMENT_H
