#ifndef LABEL_H
#define LABEL_H

#include "Identifier.h"
#include <QString>

class Label : public Identifier
{
private:
    /* data */
    QString value;
public:
    Label(QString str);
    ~Label();
};

#endif
