#ifndef ARRAYELEMENTINDEX_H
#define ARRAYELEMENTINDEX_H

#include "identifier.h"

class ArrayElementIndex: public Identifier
{
public:
    ArrayElementIndex(QString);
    ~ArrayElementIndex();
    int getValue();
    void setValue(int);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;
private:
    int index;
};

#endif // ARRAYELEMENTINDEX_H
