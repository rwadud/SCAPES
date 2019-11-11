#ifndef JLSSTATEMENT_H
#define JLSSTATEMENT_H

#include "statement.h"

class JlsStatement : public Statement
{
public:
    JlsStatement();
    ~JlsStatement();
    bool compile(Token *tokens, QString *errMsg);
    bool run();
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;

private:
    const static int numArgs = 1;
};

#endif // JLSSTATEMENT_H
