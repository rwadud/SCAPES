#include "filebrowser.h"
#include <QCoreApplication>
#include <QFileDialog>

FileBrowser::FileBrowser()
{

}
QString FileBrowser::getOpenFileName(MainWindow *w)
{
    //QString resourceDir = QCoreApplication::applicationDirPath() + "/Resources";
    QString resourceDir = QCoreApplication::applicationDirPath().section("/", 0, -2) + "/SCAPES/Resources";
    QString fileName = QFileDialog::getOpenFileName(w, "Open file", resourceDir);

    return fileName;
}
QString FileBrowser::getSaveFileName(MainWindow *w)
{
    QString resourceDir = QCoreApplication::applicationDirPath().section("/", 0, -2) + "/SCAPES/Resources";
    QString fileName = QFileDialog::getSaveFileName(w, "Save As", resourceDir);

    return fileName;
}
