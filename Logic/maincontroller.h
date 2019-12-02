#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "program.h"
#include "repository.h"
#include <QString>
#include <QTextBrowser>
#include <QMap>
class MainController
{
public:
    MainController(Repository *storeRef);
    ~MainController();
    QString getCurrentFileName();
    void setCurrentFileName(QString name);
    void setResultConsole(QTextBrowser   *console);
    void sendRunResult(QString result);
    bool manageControl(QString actionName, QString filename, QString *inText, QString *outText, QString *errText);
    static void addLineNumToErrText(int lineNum, QString *errText);
private:
    QString        currentFileName;
    bool           currentFileCompiled;
    Repository     *store;
    QTextBrowser   *resultConsole;
    QMap<QString, Program *> pgmMap;
    Program *myPgm = nullptr;
    bool openFile(QString filename, QString *outText, QString *errText);
    bool saveFile(QString filename, QString *inText, QString *errText);
    bool compile(QString *inText, QString *errText);
    bool run(QString *inText, QString *outText, QString *errText);
};

#endif // MAINCONTROLLER_H
