#include "vhash.h"

VHash::VHash()
{

}

void VHash::insert(QString &key, Identifier *id){
    hash.insert(key, id);
}

bool VHash::contains(QString &key){
    return hash.contains(key);
}

Identifier* VHash::find(QString &key){
    return hash.value(key);
}
