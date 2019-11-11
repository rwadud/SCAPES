#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <QString>

class Identifier
{
public:
    Identifier(QString str = "", bool b = false);
    virtual ~Identifier();
    virtual void dummy() = 0;
    QString getName();
    bool isLiteral();
    static Identifier* createLiteral(QString &literalType, QString data);
private:
    const QString name;
    const bool _isLiteral;
};

#endif
