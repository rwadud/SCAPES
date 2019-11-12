#ifndef TOKEN_H
#define TOKEN_H

#include <QStringList>
//Helper class to make parsing easier. Splits a line into tokens
//and provides useful methods.
class Token
{
public:
    Token(QString line);
    ~Token();
    const QString getArg(int i);
    const QString getArg1();
    const QString getArg2();
    const QString getLabel();
    QString getInstr();
    bool hasLabel();
    int length(); // number of tokens
    static bool isStringLiteral(QString &str);
    static bool isValidIdentifierName(QString &str);
    static bool isIntegerLiteral(QString &str);
    static bool isArrayElement(QString &str);
    static bool isLiteral(QString &str, QString &out);

private:
    QStringList data;
};

#endif // TOKEN_H
