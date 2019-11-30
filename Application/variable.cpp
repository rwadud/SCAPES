#include "variable.h"

Variable::Variable(QString str) : Identifier(str,"Variable"){}

Variable::~Variable()
{
}

void Variable::setValue(int v){
    value = v;
}

void Variable::serialize(QJsonObject &json){
    json["identifierType"] = getIdentifierType();
    json["name"] = getName();
}

void Variable::unserialize(const QJsonObject &json) const{

}
