#include "loadoption.h"

LoadOption::LoadOption(MainWindow *w)
{
    myWindow = w;
}
bool LoadOption::load(MainController *ctlr, QString fileName, QString *outText, QString *errText)
{
    // Get the data
    if (ctlr->manageControl("getData", fileName, nullptr, outText, errText) == false) {
        return false;
    };

    myWindow->setWindowTitle(fileName);

    return true;
}
