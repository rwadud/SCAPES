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
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;
};

#endif // STRINGLITERAL_H
