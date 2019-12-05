#include "identifiercreator.h"
#include "variable.h"
#include "stringliteral.h"
#include "integerliteral.h"

IdentifierCreator::IdentifierCreator(){}
IdentifierCreator::~IdentifierCreator(){}

Identifier* IdentifierCreator::create(QString &identifierType, QString &data){
    Identifier *id = nullptr;
    if(identifierType=="Variable"){
        id = new Variable(data);
    } else if(identifierType=="ArrayVarialbe"){
        id = new IntegerLiteral(data);
    } else if(identifierType=="ArrayElementIndex"){
        id = new IntegerLiteral(data);
    } else if(identifierType=="Label"){
        id = new IntegerLiteral(data);
    } else if(identifierType=="IntegerLiteral"){
        id = new IntegerLiteral(data);
    } else if(identifierType=="StringLiteral"){
        id = new StringLiteral(data.remove("\""));
    }
    return id;
}
