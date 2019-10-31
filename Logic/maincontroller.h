#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "program.h"
#include "repository.h"
#include <QString>
#include <QMap>
class MainController
{
public:
    MainController(Repository *storeRef);
    ~MainController();
    QString getCurrentFileName();
    void setCurrentFileName(QString name);
    bool openFile(QString filename, QString *inText);
    bool saveFile(QString filename, QString *outText);
    void compile();

private:
    QString        currentFileName;
    Repository     *store;
    QMap<QString, Program *> pgmMap;
};

#endif // MAINCONTROLLER_H
