#ifndef FILEBROWSER_H
#define FILEBROWSER_H
#include "mainwindow.h"
#include <QString>

class FileBrowser
{
public:
    FileBrowser();
    static QString getOpenFileName(MainWindow *w);
    static QString getSaveFileName(MainWindow *w);
};

#endif // FILEBROWSER_H
