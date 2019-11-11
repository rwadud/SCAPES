#ifndef TOKEN_H
#define TOKEN_H

#include <QStringList>

class Token
{
public:
    Token(QStringList tkn);
    const QString getArg(int i);
    const QString getArg1();
    const QString getArg2();
    const QString getLabel();
    QString getInstr();
    bool hasLabel();
    int length();
    static bool isStringLiteral(QString &str);
    static bool isValidIdentifierName(QString &str);
    static bool isIntegerLiteral(QString &str);
    static bool isArrayElement(QString &str);
    static bool isLiteral(QString &str, QString &out);

private:
    QStringList data;
};

#endif // TOKEN_H
