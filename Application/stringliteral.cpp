#include "stringliteral.h"

StringLiteral::StringLiteral(QString str) : Identifier(str){}
StringLiteral::~StringLiteral(){}

QString StringLiteral::getValue(){
    return getName();
}

void StringLiteral::serialize(QJsonObject &json){

}

void StringLiteral::unserialize(const QJsonObject &json) const{

}
