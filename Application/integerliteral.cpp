#include "integerliteral.h"

IntegerLiteral::IntegerLiteral(QString str) : Identifier(str,"IntegerLiteral"), value(str.toInt()) {}
IntegerLiteral::~IntegerLiteral(){}

int IntegerLiteral::getValue(){
    return value;
}

void IntegerLiteral::serialize(QJsonObject &json){
    json["identifierType"] = getIdentifierType();
    json["name"] = getName();
}

void IntegerLiteral::unserialize(const QJsonObject &json){

}
