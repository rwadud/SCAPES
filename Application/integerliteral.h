#ifndef INTEGERLITERAL_H
#define INTEGERLITERAL_H

#include "identifier.h"

class IntegerLiteral : public Identifier
{
public:
    IntegerLiteral(QString str);
    ~IntegerLiteral();
    int getValue();
    void setValue(int){}
private:
    const int value;
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);
};

#endif // INTEGERLITERAL_H
