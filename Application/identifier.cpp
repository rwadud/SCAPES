#include "identifier.h"
#include "stringliteral.h"
#include "integerliteral.h"

Identifier::Identifier(QString str, QString type) : name(str), identifierType(type){}

Identifier::~Identifier()
{
}

QString Identifier::getName(){
    return name;
}

QString Identifier::getIdentifierType(){
    return identifierType;
}
bool Identifier::isLiteral(){
    if(identifierType.contains("Literal"))
       return true;
    return false;
}
bool Identifier::isArray(){
    if(identifierType=="ArrayVariable")
       return true;
    return false;
}
bool Identifier::isVariable(){
    if(identifierType=="Variable")
       return true;
    return false;
}
bool Identifier::isLabel(){
    if(identifierType=="Label")
       return true;
    return false;
}

Identifier* Identifier::createLiteral(QString &literalType, QString data){
    Identifier *id = nullptr;
    if(literalType=="IntegerLiteral"){
        id = new IntegerLiteral(data);
    } else if(literalType=="StringLiteral"){
        id = new StringLiteral(data.remove("\""));
    }
    return id;
}
