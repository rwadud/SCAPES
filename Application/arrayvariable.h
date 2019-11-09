#ifndef ARRAY_VARIABLE_H
#define ARRAY_VARIABLE_H

#include "identifier.h"

class ArrayVariable : public Identifier 
{
private:
    /* data */
    const int MAX_SIZE;
    int* array;

public:
    ArrayVariable(QString str, int s);
    ~ArrayVariable();
    void dummy(){}
    void set(int index, int value);
    int size();
};

#endif
