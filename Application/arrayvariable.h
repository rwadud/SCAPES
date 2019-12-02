#ifndef ARRAY_VARIABLE_H
#define ARRAY_VARIABLE_H

#include "identifier.h"

class ArrayVariable : public Identifier 
{
private:
    /* data */
    const int MAX_SIZE;
    int* array;
    int index = 0;

public:
    ArrayVariable(QString, int);
    ~ArrayVariable();
    int getValue();
    int get(int);
    int size();
    void dummy(){}
    void set(int, int);
    void setValue(int);
    void setIndex(int);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;
};

#endif
