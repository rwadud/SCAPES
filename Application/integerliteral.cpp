#include "integerliteral.h"

IntegerLiteral::IntegerLiteral(QString str) : Identifier(str), value(str.toInt()) {}

IntegerLiteral::~IntegerLiteral(){}

int IntegerLiteral::getValue(){
    return value;
}
