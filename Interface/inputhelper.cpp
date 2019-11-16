#include "inputhelper.h"
#include <QInputDialog>
#include <QDebug>


InputHelper::InputHelper()
{

}
int InputHelper::readInteger(QString varName)
{
    int  intValue = 0; // default

    intValue = QInputDialog::getInt(nullptr, QString("Enter Integer Value"),
                                    QString(varName + ":"), 0);

    //qDebug() << (QString("%1%").arg(intValue));

    return intValue;
}
