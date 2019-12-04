#ifndef JMRSTATEMENT_H
#define JMRSTATEMENT_H

#include "statement.h"
#include "cmpflag.h"

class JmrStatement : public Statement
{
public:
    JmrStatement();
    ~JmrStatement();
    bool compile(Token *tokens, QString *errMsg);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;

private:
    const static int numArgs = 1;
};

#endif // JMRSTATEMENT_H
