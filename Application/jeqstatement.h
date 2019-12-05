#ifndef JEQSTATEMENT_H
#define JEQSTATEMENT_H

#include "statement.h"

class JeqStatement : public Statement
{
public:
    JeqStatement();
    ~JeqStatement();
    void compile(Token *tokens);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 1;
};

#endif // JEQSTATEMENT_H
