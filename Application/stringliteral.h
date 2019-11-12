#ifndef STRINGLITERAL_H
#define STRINGLITERAL_H

#include "identifier.h"
#include <QString>

class StringLiteral : public Identifier
{
public:
    StringLiteral(QString);
    ~StringLiteral();
    QString getValue();
    void dummy(){}
};

#endif // STRINGLITERAL_H
