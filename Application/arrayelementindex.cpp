#include "arrayelementindex.h"
#include <QStringList>
#include <QDebug>

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

bool ArrayElementIndex::isVariableIndex(){
    return _isVariableIndex;
}

void ArrayElementIndex::setVariable(Identifier *var){
    this->var = var;
    _isVariableIndex = true;
}

void ArrayElementIndex::updateVariableIndex(){
    index = var->getValue();
    initialize();
}

void ArrayElementIndex::serialize(QJsonObject &json){
    json["identifierType"] = getIdentifierType();
    json["name"] = getName();
    json["value"] = index;
}

void ArrayElementIndex::unserialize(const QJsonObject &json) const{

}
