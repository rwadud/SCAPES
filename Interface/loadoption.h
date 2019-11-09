#ifndef LOADOPTION_H
#define LOADOPTION_H
#include "mainwindow.h"

class LoadOption
{
public:
    LoadOption(MainWindow *w);
    bool load(MainController *ctlr, QString fileName, QString *outText);
private:
    MainWindow *myWindow;
};

#endif // LOADOPTION_H
