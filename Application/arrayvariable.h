#ifndef ARRAY_VARIABLE_H
#define ARRAY_VARIABLE_H

#include "Identifier.h"

class ArrayVariable : public Identifier 
{
private:
    /* data */
    int index;
    int size;
public:
    ArrayVariable(/* args */);
    ~ArrayVariable();
};

#endif
