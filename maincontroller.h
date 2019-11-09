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
    bool manageControl(QString actionName, QString filename, QString *inText, QString *outText);

    void autoCompile(QString filename); // for testing purposes

private:
    QString        currentFileName;
    Repository     *store;
    QMap<QString, Program *> pgmMap;

    bool openFile(QString filename, QString *outText);
    bool saveFile(QString filename, QString *inText);
    bool compile(QString *inText);
};

#endif // MAINCONTROLLER_H
