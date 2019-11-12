#ifndef LABEL_H
#define LABEL_H

#include "identifier.h"
#include <QString>

class Label : public Identifier
{
private:
    /* data */
    int index;
public:
    Label(QString str="", int i=0);
    ~Label();
    void dummy(){}
    int getIndex();
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;
};

#endif
