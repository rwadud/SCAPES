#include "label.h"

Label::Label(QString str, int i) : Identifier(str), sIndex(i){}

Label::~Label(){}

int Label::getStatementIndex(){
    return sIndex;
}

void Label::setStatementIndex(int i){
    sIndex = i;
}

void Label::serialize(QJsonObject &json){
    json["IdentifierType"] = "Label";
    json["id"] = getName();
    json["index"] = sIndex;
}

void Label::unserialize(const QJsonObject &json) const{

}
