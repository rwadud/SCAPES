#ifndef DCISTATEMENT_H
#define DCISTATEMENT_H

#include "statement.h"

class DciStatement : public Statement
{
public:
    DciStatement();
    ~DciStatement();
    bool compile(Token *tokens, QString *errMsg);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;

private:
    const static int numArgs = 1;
};

#endif // DCISTATEMENT_H
