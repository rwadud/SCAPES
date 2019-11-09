#include "compileoption.h"
#include <QMessageBox>

CompileOption::CompileOption()
{

}
bool CompileOption::compile(MainController *ctlr, QString *inText)
{
    bool rc = false;
    QString fileName = ctlr->getCurrentFileName();

    if (fileName.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setText("Error! Save the program using SaveAs option first: ");
        msgBox.exec();
        return false;
    }

    rc = ctlr->manageControl("compile", fileName, inText, nullptr);

    return rc;
}
