#include "label.h"

Label::Label(QString str, int i) : Identifier(str), index(i){}

Label::~Label(){}

int Label::getIndex(){
    return index;
}
