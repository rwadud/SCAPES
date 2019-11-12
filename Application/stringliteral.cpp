#include "stringliteral.h"

StringLiteral::StringLiteral(QString str) : Identifier(str){}

StringLiteral::~StringLiteral(){}

QString StringLiteral::getValue(){
    return getName();
}
