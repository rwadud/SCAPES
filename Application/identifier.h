#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <QString>
#include "serializable.h"

//Abstract Identifier class
class Identifier : public Serializable
{
public:
    Identifier(QString str = "", QString type = "");
    virtual ~Identifier();
    virtual void dummy() = 0; //necessary for abstraction
    QString getName();
    QString getIdentifierType();
    bool isLiteral();
    bool isVariable();
    bool isArray();
    bool isLabel();
    void initialize();
    bool isInitialized();
    static Identifier* createLiteral(QString &literalType, QString data);

private:
    const QString name;
    const QString identifierType;
    bool initialized = false;
};

#endif
