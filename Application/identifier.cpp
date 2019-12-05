#include "identifier.h"


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
void Identifier::initialize(){
    initialized = true;
}
bool Identifier::isInitialized(){
    return initialized;
}
bool Identifier::isIntegerLiteral(){
    if(identifierType=="IntegerLiteral")
       return true;
    return false;
}
bool Identifier::isStringLiteral(){
    if(identifierType=="StringLiteral")
       return true;
    return false;
}

bool Identifier::isArray(){
    if(identifierType=="ArrayVariable")
       return true;
    return false;
}
bool Identifier::isArrayElementIndex(){
    if(identifierType=="ArrayElementIndex")
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
