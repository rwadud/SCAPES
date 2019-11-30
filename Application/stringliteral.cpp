#include "stringliteral.h"

StringLiteral::StringLiteral(QString str) : Identifier(str,"StringLiteral"){}
StringLiteral::~StringLiteral(){}

QString StringLiteral::getValue(){
    return getName();
}

void StringLiteral::serialize(QJsonObject &json){
    json["identifierType"] = getIdentifierType();
    json["name"] = getName();
}

void StringLiteral::unserialize(const QJsonObject &json) const{

}
