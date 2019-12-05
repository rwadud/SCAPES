#ifndef PRTSTATEMENT_H
#define PRTSTATEMENT_H

#include "statement.h"

class PrtStatement : public Statement
{
public:
    PrtStatement();
    ~PrtStatement();
    bool compile(Token *tokens, QString *errMsg);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 1;
};

#endif // PRTSTATEMENT_H
