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
    void unserialize(const QJsonObject &json);
    bool isVariableIndex();
    void updateVariableIndex();
    void setVariable(Identifier*);

private:
    int index;
    Identifier *var = nullptr;
    bool _isVariableIndex = false;
};

#endif // ARRAYELEMENTINDEX_H
