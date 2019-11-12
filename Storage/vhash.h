#ifndef VHASH_H
#define VHASH_H

#include <QHash>
#include "identifier.h"

//Encapsulated QHash map used to store program variables
class VHash
{

private:
    QHash<QString, Identifier*> hash;

public:
    VHash();
    ~VHash();
    void insert(QString &key, Identifier* id);
    void add(QString &key, Identifier* id);
    Identifier* get(QString &key);
    Identifier* find(QString &key);
    bool contains(QString &key);
};

#endif // VHASH_H
