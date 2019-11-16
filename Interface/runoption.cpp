#include "runoption.h"

RunOption::RunOption()
{

}
bool RunOption::run(MainController *ctlr, QString *inText, QString *outText, QString *errText)
{
    bool rc = false;
    QString fileName = ctlr->getCurrentFileName();

    if (fileName.isEmpty()) {
        *errText = "Save the program using SaveAs option first";
        return false;
    }

    rc = ctlr->manageControl("run", fileName, inText, outText, errText);

    return rc;
}
