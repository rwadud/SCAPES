#include "label.h"

Label::Label(QString str, int i) : Identifier(str,"Label"), sIndex(i){}

Label::~Label(){}

int Label::getStatementIndex(){
    return sIndex;
}

void Label::setStatementIndex(int i){
    sIndex = i;
}

void Label::serialize(QJsonObject &json){
    json["IdentifierType"] = getIdentifierType();
    json["id"] = getName();
    json["statementIndex"] = sIndex;
}

void Label::unserialize(const QJsonObject &json) const{

}
