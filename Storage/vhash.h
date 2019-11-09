#ifndef VHASH_H
#define VHASH_H

#include <QMap>
#include "identifier.h"

class VHash
{

private:
    QMap<QString, Identifier*> hash;

public:
    VHash();
    ~VHash();
    void insert(QString &key, Identifier* id);
    Identifier* find(QString &key);
    bool contains(QString &key);
};

#endif // VHASH_H
