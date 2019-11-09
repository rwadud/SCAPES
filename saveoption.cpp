#include "saveoption.h"

SaveOption::SaveOption(MainWindow *w)
{
    myWindow = w;
}

void SaveOption::save(MainController *ctlr, QString fileName, QString *srcText)
{
    // Save the  data
    if (ctlr->manageControl("saveData", fileName, srcText, nullptr) == false) {
        return;
    };

    myWindow->setWindowTitle(fileName);
}
