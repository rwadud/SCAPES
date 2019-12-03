#ifndef DCASTATEMENT_H
#define DCASTATEMENT_H

#include "statement.h"

class DcaStatement : public Statement
{
public:
    DcaStatement();
    ~DcaStatement();
    bool compile(Token *tokens, QString *errMsg);
    bool run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;

private:
    const static int numArgs = 2;
};

#endif // DCASTATEMENT_H
