#ifndef ARRAY_VARIABLE_H
#define ARRAY_VARIABLE_H

#include "identifier.h"

/*
    Author: Redwan Wadud
*/

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
    int get();
    int get(int i);
    int size();
    void dummy(){}
    void set(int i, int value);
    void setIndex(int i);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;
};

#endif
