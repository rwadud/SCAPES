#ifndef CREATOR_H
#define CREATOR_H

#include "statement.h"

class Creator
{
public:
    Creator();
    virtual Statement* CreateStatement() = 0;
};

#endif // CREATOR_H
