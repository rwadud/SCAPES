#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <QString>
#include "serializable.h"

//Abstract Identifier class
class Identifier : public Serializable
{
public:
    Identifier(QString str = "", bool b = false);
    virtual ~Identifier();
    virtual void dummy() = 0; //necessary for abstraction
    QString getName();
    bool isLiteral();
    static Identifier* createLiteral(QString &literalType, QString data);

private:
    const QString name;
    const bool _isLiteral;

};

#endif
