#include "arrayvariable.h"
#include <stdexcept>

ArrayVariable::ArrayVariable(QString str, int s) : Identifier(str, "ArrayVariable"), MAX_SIZE(s) {
    array = new int[MAX_SIZE];
}

ArrayVariable::~ArrayVariable()
{
}

void ArrayVariable::set(int i, int value){
    if(i < 0 || i > size()-1)
        throw std::out_of_range("index out of range");
    array[i] = value;
}

int ArrayVariable::get(int i){
    if(i < 0 || i > size()-1)
        throw std::out_of_range("index out of range");
    return array[i];
}

int ArrayVariable::get(){
    return array[index];
}

void  ArrayVariable::setIndex(int i){
    if(i < 0 || i > size()-1)
        throw std::out_of_range("index out of range");
    index = i;
}

int ArrayVariable::size(){
    return (sizeof(*array)/sizeof(*array));
}

void ArrayVariable::serialize(QJsonObject &json){
    json["identifierType"] = getIdentifierType();
    json["name"] = getName();
}

void ArrayVariable::unserialize(const QJsonObject &json) const{

}


