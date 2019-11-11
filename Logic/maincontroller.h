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
    bool manageControl(QString actionName, QString filename, QString *inText, QString *outText, QString *errText);

    void autoCompile(QString filename); // for testing purposes

private:
    QString        currentFileName;
    Repository     *store;
    QMap<QString, Program *> pgmMap;

    bool openFile(QString filename, QString *outText, QString *errText);
    bool saveFile(QString filename, QString *inText, QString *errText);
    bool compile(QString *inText, QString *errText);
};

#endif // MAINCONTROLLER_H
