#include "mainwindow.h"
#include "maincontroller.h"
#include "flatfileimp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlatFileImp    storeImp; // Currently supports only flat file System Repository
    Repository     store(&storeImp);
    MainController ctlr(&store);
    MainWindow w(nullptr, &ctlr);

    w.show();

    return a.exec();
}
