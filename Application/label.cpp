#include "label.h"

Label::Label(QString str, int i) : Identifier(str,"Label"){
    setIndex(i);
}

Label::~Label(){}

int Label::getIndex(){
    return index;
}

void Label::setIndex(int i){
    if(i>-1){
        index = i;
        initialize();
    }
}

void Label::serialize(QJsonObject &json){
    json["identifierType"] = getIdentifierType();
    json["name"] = getName();
}

void Label::unserialize(const QJsonObject &json) const{

}
