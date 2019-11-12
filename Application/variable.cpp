#include "variable.h"

Variable::Variable(QString str) : Identifier(str){}

Variable::~Variable()
{
}

void Variable::setValue(int v){
    value = v;
}

void Variable::serialize(QJsonObject &json){

}

void Variable::unserialize(const QJsonObject &json) const{

}
