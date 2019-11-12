#ifndef INTEGERLITERAL_H
#define INTEGERLITERAL_H

#include "identifier.h"

class IntegerLiteral : public Identifier
{
public:
    IntegerLiteral(QString str);
    ~IntegerLiteral();
    int getValue();
    void dummy(){}
private:
    const int value;
};

#endif // INTEGERLITERAL_H
