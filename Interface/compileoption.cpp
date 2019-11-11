#include "compileoption.h"
#include "notifymsg.h"
#include <QMessageBox>

CompileOption::CompileOption()
{

}
bool CompileOption::compile(MainController *ctlr, QString *inText, QString *errText)
{
    bool rc = false;
    QString fileName = ctlr->getCurrentFileName();

    if (fileName.isEmpty()) {
        //NotifyMsg::show("Error! Save the program using SaveAs option first: ");
        *errText = "Save the program using SaveAs option first";
        return false;
    }

    rc = ctlr->manageControl("compile", fileName, inText, nullptr, errText);

    return rc;
}
