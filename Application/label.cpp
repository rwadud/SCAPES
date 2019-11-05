#include "label.h"

Label::Label(QString str) : Identifier(str){}

Label::~Label(){}

void Label::setName(QString str){
    this->name = str;
}
