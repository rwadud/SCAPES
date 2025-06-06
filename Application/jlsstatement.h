#ifndef JLSSTATEMENT_H
#define JLSSTATEMENT_H

#include "statement.h"
#include "cmpflag.h"

class JlsStatement : public Statement
{
public:
    JlsStatement();
    ~JlsStatement();
    void compile(Token *tokens);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 1;
};

#endif // JLSSTATEMENT_H
