#include "inputhelper.h"
#include <QInputDialog>
#include <QDebug>


InputHelper::InputHelper()
{

}
int InputHelper::readInteger(QString varName)
{
    int  intValue = 0; // default

    intValue = QInputDialog::getInt(nullptr, QString("Enter Integer "),
                                    QString("Value for Variable " + varName + ": "), 0, 0);


    return intValue;
}
