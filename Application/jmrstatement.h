#ifndef JMRSTATEMENT_H
#define JMRSTATEMENT_H

#include "statement.h"
#include "cmpflag.h"

class JmrStatement : public Statement
{
public:
    JmrStatement();
    ~JmrStatement();
    void compile(Token *tokens);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 1;
};

#endif // JMRSTATEMENT_H
