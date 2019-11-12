#include "token.h"
#include <stdexcept>
#include <QDebug>

Token::Token(QString &line)
{
    if(line.contains('"')){
        data = line.split(" \"");
        data[1] = "\"" + data[1];
    }
    else{
        data = line.split(" ");
    }
}

Token::~Token(){

}
const QString Token::getArg(int i){
    if(i == 2)
        return getArg2();
    return getArg1();
}

const QString Token::getArg1(){
    if(hasLabel())
        return data[2];
    return data[1];
}

const QString Token::getArg2(){
    if(hasLabel())
        return data[3];
    return data[2];
}

const QString Token::getLabel(){
    QString label = data[0];
    return label.remove(":");
}

QString Token::getInstr(){
    if(hasLabel())
        return data[1];
    return data[0];
}

bool Token::hasLabel(){
    return data[0].contains(":");
}

int Token::length(){
    return hasLabel() ? (data.length()-1): data.length();
}

bool Token::isStringLiteral(QString &str){
    QRegExp rgx("^(\").*(\")$");
    if(rgx.exactMatch(str)){
        rgx.setPattern("^(\")(.*)(\")(.*)(\")$");
        if(rgx.exactMatch(str))
            return false;
        return true;
    }
    return false;
}

bool Token::isIntegerLiteral(QString &str){
    QRegExp rgx("\\d*");
    return rgx.exactMatch(str);
}

bool Token::isLiteral(QString &str, QString &out){
    if(isStringLiteral(str)){
        out = "StringLiteral";
        return true;
    } else if(isIntegerLiteral(str)){
        out = "IntegerLiteral";
        return true;
    }
    return false;
}

bool Token::isValidIdentifierName(QString &str){
    return (!str.isEmpty() && !str.contains(QRegExp("[^a-zA-Z0-9_+$]")));
}

bool Token::isArrayElement(QString &str){
    QRegExp rgx("^(\\$)[a-zA-Z0-9_]+(\\+)(\\d*)");
    return rgx.exactMatch(str);
}
