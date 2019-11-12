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
    ArrayVariable(QString str, int s);
    ~ArrayVariable();
    void dummy(){}
    void set(int i, int value);
    int get(int i);
    int get();
    void setIndex(int i);
    int size();
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;
};

#endif
