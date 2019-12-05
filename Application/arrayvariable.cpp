#include "arrayvariable.h"
#include <stdexcept>
#include <QDebug>

ArrayVariable::ArrayVariable(QString str, int s) : Identifier(str, "ArrayVariable"), MAX_SIZE(s) {
    array = new int[MAX_SIZE];
}

ArrayVariable::~ArrayVariable()
{
    delete[] array;
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

int ArrayVariable::getValue(){
    return array[index];
}

void ArrayVariable::setValue(int value){
    set(index,value);
}

void  ArrayVariable::setIndex(int i){
    if(i < 0 || i > size()-1)
        throw std::out_of_range("index out of range");
    index = i;
}

int ArrayVariable::size(){
    return MAX_SIZE;
}

void ArrayVariable::serialize(QJsonObject &json){
    json["identifierType"] = getIdentifierType();
    json["name"] = getName();
}

void ArrayVariable::unserialize(const QJsonObject &json){

}


