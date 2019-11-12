#ifndef VARIABLE_H
#define VARIABLE_H

#include "identifier.h"

class Variable : public Identifier 
{
private:
    int value;
public:
    Variable(QString str);
    ~Variable();
    void dummy(){}
    void setValue(int);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;
};

#endif
