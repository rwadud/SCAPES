#include "vhash.h"

VHash::VHash(){}
VHash::~VHash(){
    QHashIterator<QString, Identifier*> i(hash);
    while (i.hasNext()) {
        i.next();
        delete i.value();
    }
}
void VHash::insert(QString &key, Identifier *id){
    hash.insert(key, id);
}

void VHash::add(QString &key, Identifier *id){
    hash.insert(key, id);
}

bool VHash::contains(QString &key){
    return hash.contains(key);
}

Identifier* VHash::get(QString &key){
    return hash.value(key, nullptr);
}

Identifier* VHash::find(QString &key){
    return get(key);
}
