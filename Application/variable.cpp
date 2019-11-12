#include "variable.h"

Variable::Variable(QString str) : Identifier(str){}

Variable::~Variable()
{
}

void Variable::setValue(int v){
    value = v;
}

void Variable::serialize(QJsonObject &json){
    json["IdentifierType"] = "Variable";
    json["id"] = getName();
    json["value"] = value;
}

void Variable::unserialize(const QJsonObject &json) const{

}
