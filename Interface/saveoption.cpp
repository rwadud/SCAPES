#include "saveoption.h"

SaveOption::SaveOption(MainWindow *w)
{
    myWindow = w;
}

bool SaveOption::save(MainController *ctlr, QString fileName, QString *srcText, QString *errText)
{
    // Save the  data
    if (ctlr->manageControl("saveData", fileName, srcText, nullptr, errText) == false) {
        return false;
    };

    myWindow->setWindowTitle(fileName);
    return true;
}
