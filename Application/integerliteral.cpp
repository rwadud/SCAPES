#include "integerliteral.h"

IntegerLiteral::IntegerLiteral(QString str) : Identifier(str), value(str.toInt()) {}
IntegerLiteral::~IntegerLiteral(){}

int IntegerLiteral::getValue(){
    return value;
}

void IntegerLiteral::serialize(QJsonObject &json){
    json["IdentifierType"] = "IntegerLiteral";
    json["id"] = getName();
    json["value"] = getValue();
}

void IntegerLiteral::unserialize(const QJsonObject &json) const{

}
