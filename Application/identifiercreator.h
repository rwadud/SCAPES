#ifndef IDENTIFIERCREATOR_H
#define IDENTIFIERCREATOR_H

#include "identifier.h"

class IdentifierCreator
{
public:
    IdentifierCreator();
    ~IdentifierCreator();
    static Identifier* create(QString &, QString &);
};

#endif // IDENTIFIERCREATOR_H
