#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <QString>
#include "serializable.h"

class Identifier : public Serializable
{
public:
    Identifier(QString str = "", bool b = false);
    virtual ~Identifier();
    virtual void dummy() = 0;
    QString getName();
    bool isLiteral();
    static Identifier* createLiteral(QString &literalType, QString data);
    QString getTypeName();
    void setTypeName(QString type);

private:
    const QString name;
    const bool _isLiteral;
protected:
    QString _typename;
};

#endif
