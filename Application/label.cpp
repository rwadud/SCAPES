#include "label.h"

Label::Label(QString str, int i) : Identifier(str), index(i){}

Label::~Label(){}

int Label::getIndex(){
    return index;
}

void Label::setIndex(int i){
    index = i;
}

void Label::serialize(QJsonObject &json){
    json["IdentifierType"] = "Label";
    json["id"] = getName();
    json["index"] = index;
}

void Label::unserialize(const QJsonObject &json) const{

}
