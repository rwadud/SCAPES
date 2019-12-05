#ifndef CMPSTATEMENT_H
#define CMPSTATEMENT_H

#include "statement.h"
#include "cmpflag.h"

class CmpStatement : public Statement
{
public:
    CmpStatement();
    ~CmpStatement();
    void compile(Token *tokens);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 2;
};

#endif // CMPSTATEMENT_H
