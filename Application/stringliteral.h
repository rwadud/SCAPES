#ifndef STRINGLITERAL_H
#define STRINGLITERAL_H

#include "identifier.h"
#include <QString>

class StringLiteral : public Identifier
{
public:
    StringLiteral(QString);
    ~StringLiteral();
    int getValue(){return 0;}
    QString getStrValue();
    void setValue(int){}
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);
};

#endif // STRINGLITERAL_H
