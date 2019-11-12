#ifndef LABEL_H
#define LABEL_H

#include "identifier.h"
#include <QString>

class Label : public Identifier
{
private:
    /* data */
    int sIndex;
public:
    Label(QString str="", int i=0);
    ~Label();
    void dummy(){}
    int getStatementIndex();
    void setStatementIndex(int i);
    void serialize(QJsonObject &json);
    void unserialize(const QJsonObject &json) const;
};

#endif
