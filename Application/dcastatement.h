#ifndef DCASTATEMENT_H
#define DCASTATEMENT_H

#include "statement.h"

class DcaStatement : public Statement
{
public:
    DcaStatement();
    ~DcaStatement();
    void compile(Token *tokens);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 2;
};

#endif // DCASTATEMENT_H
