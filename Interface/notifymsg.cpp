#include "notifymsg.h"
#include "QMessageBox"

NotifyMsg::NotifyMsg()
{

}
void NotifyMsg::show(QString msg)
{
    if (msg.isEmpty() == false) {
        QMessageBox msgBox;
        msgBox.setText(msg);
        msgBox.exec();
    }
}

void NotifyMsg::show(QString msg, QStatusBar *statusBar)
{
    statusBar->showMessage(msg);
}

void NotifyMsg::show(QString msg, QTextBrowser *console)
{
    console->setText(msg);
}
void NotifyMsg::showAppend(QString msg, QTextBrowser *console)
{
    console->append(msg);
}
