#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <QJsonObject>

//Abstract Serialization interface
class Serializable
{
public:
    Serializable();
    virtual ~Serializable();
    virtual void serialize(QJsonObject &json) = 0;
    virtual void unserialize(const QJsonObject &json) = 0;
};

#endif // SERIALIZABLE_H
