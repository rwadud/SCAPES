#ifndef SAVEOPTION_H
#define SAVEOPTION_H
#include "mainwindow.h"

class SaveOption
{
public:
    SaveOption(MainWindow *w);
    void save(MainController *ctlr, QString fileName, QString *srcText);
private:
    MainWindow *myWindow;
};

#endif // SAVEOPTION_H
