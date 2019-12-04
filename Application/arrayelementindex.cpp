#include "arrayelementindex.h"
#include <QStringList>

ArrayElementIndex::ArrayElementIndex(QString s) :  Identifier(s,"ArrayElementIndex")
{
    index = s.split("+")[1].toInt();
}

ArrayElementIndex::~ArrayElementIndex()
{

}

int ArrayElementIndex::getValue(){
    return index;
}

void ArrayElementIndex::setValue(int i){
    index = i;
}

void ArrayElementIndex::serialize(QJsonObject &json){
    json["identifierType"] = getIdentifierType();
    json["name"] = getName();
    json["value"] = index;
}

void ArrayElementIndex::unserialize(const QJsonObject &json) const{

}
