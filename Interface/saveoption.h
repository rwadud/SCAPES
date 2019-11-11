#ifndef SAVEOPTION_H
#define SAVEOPTION_H
#include "mainwindow.h"

class SaveOption
{
public:
    SaveOption(MainWindow *w);
    bool save(MainController *ctlr, QString fileName, QString *srcText, QString *errText);
private:
    MainWindow *myWindow;
};

#endif // SAVEOPTION_H
