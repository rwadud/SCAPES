#ifndef LABEL_H
#define LABEL_H

#include "identifier.h"
#include <QString>

class Label : public Identifier
{
private:
    /* data */
    int index; //index of statement
public:
    Label(QString str="", int i=-1);
    ~Label();
    int getValue();
    void setValue(int);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;
};

#endif
