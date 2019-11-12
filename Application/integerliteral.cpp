#include "integerliteral.h"

IntegerLiteral::IntegerLiteral(QString str) : Identifier(str), value(str.toInt()) {}
IntegerLiteral::~IntegerLiteral(){}

int IntegerLiteral::getValue(){
    return value;
}

void IntegerLiteral::serialize(QJsonObject &json){

}

void IntegerLiteral::unserialize(const QJsonObject &json) const{

}
