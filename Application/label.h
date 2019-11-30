#ifndef LABEL_H
#define LABEL_H

#include "identifier.h"
#include <QString>

class Label : public Identifier
{
private:
    /* data */
    int sIndex; //index of statement
public:
    Label(QString str="", int i=-1);
    ~Label();
    int getStatementIndex();
    void dummy(){}
    void setStatementIndex(int i);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;
};

#endif
