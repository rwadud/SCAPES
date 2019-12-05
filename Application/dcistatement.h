#ifndef DCISTATEMENT_H
#define DCISTATEMENT_H

#include "statement.h"

class DciStatement : public Statement
{
public:
    DciStatement();
    ~DciStatement();
    void compile(Token *tokens);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 1;
};

#endif // DCISTATEMENT_H
