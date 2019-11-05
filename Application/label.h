#ifndef LABEL_H
#define LABEL_H

#include "identifier.h"
#include <QString>

class Label : public Identifier
{
private:
    /* data */
    QString value;
public:
    Label(QString str = "");
    ~Label();
    void setName(QString str);
};

#endif
