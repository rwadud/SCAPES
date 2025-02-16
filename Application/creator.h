#ifndef CREATOR_H
#define CREATOR_H

#include "statement.h"

//Abstract factory method implementor
class Creator
{
public:
    virtual Statement* Create(QString &instructionType) = 0;
};

#endif // CREATOR_H
