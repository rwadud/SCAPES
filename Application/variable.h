#ifndef VARIABLE_H
#define VARIABLE_H

#include "identifier.h"
#include <QDebug>

class Variable : public Identifier 
{
private:
    int value;
public:
    Variable(QString str);
    ~Variable();
    void setValue(int);
    int getValue();
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json);
};

#endif
