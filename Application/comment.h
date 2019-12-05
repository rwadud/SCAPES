#ifndef COMMENT_H
#define COMMENT_H

#include "statement.h"

class Comment : public Statement
{
public:
    Comment();
    ~Comment();
    void compile(Token *tokens);
    void run(QString &result);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);

private:
    const static int numArgs = 0;
};

#endif // COMMENT_H
