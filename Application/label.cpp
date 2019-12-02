#include "label.h"

Label::Label(QString str, int i) : Identifier(str,"Label"){
    setValue(i);
}

Label::~Label(){}

int Label::getValue(){
    return index;
}

void Label::setValue(int i){
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
