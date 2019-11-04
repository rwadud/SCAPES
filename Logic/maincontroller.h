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
    bool openFile(QString filename, QString *outText);
    bool saveFile(QString filename, QString *inText);
    void compile(QString *inText);

private:
    QString        currentFileName;
    Repository     *store;
    QMap<QString, Program *> pgmMap;
};

#endif // MAINCONTROLLER_H
