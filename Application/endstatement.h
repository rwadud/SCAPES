#ifndef ENDSTATEMENT_H
#define ENDSTATEMENT_H

#include "statement.h"

class EndStatement : public Statement
{
public:
    EndStatement();
    ~EndStatement();
    bool compile(Token *tokens, QString *errMsg);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 0;
};

#endif // ENDSTATEMENT_H
