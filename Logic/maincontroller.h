#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "Program.h"
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
    bool openFile(QString filename, QString *outText);
    bool saveFile(QString filename, QString *inText);
    void compile(QString *inText);
    void autoCompile(QString filename); // for testing purposes

private:
    QString        currentFileName;
    Repository     *store;
    QMap<QString, Program *> pgmMap;
};

#endif // MAINCONTROLLER_H
