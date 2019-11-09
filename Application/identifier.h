#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <QString>

class Identifier
{
protected:
    QString name;
public:
    Identifier(QString str = "");
    virtual ~Identifier();
    virtual void dummy() = 0;
};

#endif
