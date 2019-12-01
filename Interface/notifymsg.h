#ifndef NOTIFYMSG_H
#define NOTIFYMSG_H
#include <QString>
#include <QStatusBar>
#include <QTextBrowser>

class NotifyMsg
{
public:
    NotifyMsg();
    static void show(QString msg);
    static void show(QString msg, QStatusBar *statusBar);
    static void show(QString msg, QTextBrowser *console);
    static void showAppend(QString msg, QTextBrowser *console);
};

#endif // NOTIFYMSG_H
