#include "identifier.h"
#include "stringliteral.h"
#include "integerliteral.h"

Identifier::Identifier(QString str, bool b) : name(str), _isLiteral(b){}

Identifier::~Identifier()
{
}

QString Identifier::getName(){
    return name;
}

bool Identifier::isLiteral(){
    return _isLiteral;
}

Identifier* Identifier::createLiteral(QString &literalType, QString data){
    Identifier *id = nullptr;
    if(literalType=="IntegerLiteral"){
        id = new IntegerLiteral(data);
    } else if(literalType=="IntegerLiteral"){
        id = new StringLiteral(data);
    }
    return id;
}
