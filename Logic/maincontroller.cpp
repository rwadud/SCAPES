#include "maincontroller.h"
#include "notifymsg.h"
#include <QMessageBox>
#include <QDebug>

MainController::MainController(Repository *storeRef)
{
    store = storeRef;
}
MainController::~MainController()
{
    QMap<QString, Program *>::const_iterator i = pgmMap.constBegin();
    while (i != pgmMap.constEnd()) {
       //qDebug()  << "Deleting Program Object for file: " + i.key();
       delete (i.value());
       i++;
    }
    pgmMap.clear();
}
QString MainController:: getCurrentFileName()
{
    return currentFileName;
}

void MainController::setCurrentFileName(QString name)
{
    currentFileName = name;
    currentFileCompiled = false;
}
void MainController::setResultConsole(QTextBrowser *console)
{
    resultConsole = console;
}
void MainController::sendRunResult(QString result)
{
     NotifyMsg::showAppend(result, resultConsole);
}
void MainController::addLineNumToErrText(int lineNum, QString *errText)
{
    *errText = QString("Line %1 - ").arg(lineNum) + *errText;
}
bool MainController::manageControl(QString actionName, QString filename, QString *inText,
                                   QString *outText, QString *errText)
{
    bool rc = false;

    if (actionName == "getData") {
        rc = openFile(filename, outText, errText);
    } else if (actionName == "saveData") {
        rc = saveFile(filename, inText, errText);
    } else if (actionName == "compile") {
        rc = compile(inText, errText);
    } else if (actionName == "run") {
        rc = run(inText, outText, errText);
    }
    return rc;
}
bool MainController::openFile(QString filename, QString *outText, QString *errText)
{

    return store->getSourceData(filename, outText, errText);
}

bool MainController::saveFile(QString filename, QString *inText, QString *errText)
{
    return store->setSourceData(filename, inText, errText);
}


bool MainController::compile(QString *inSrcTxt, QString *errTxt)
{

    QString fileName = currentFileName;
    QString compiledTxt; //  JSON or XML format

    currentFileCompiled = false;
    // save the data
    saveFile(fileName, inSrcTxt, errTxt);

    if (pgmMap.contains(fileName)) {
        // remove it from the map ???
        myPgm = pgmMap.take(fileName);
        if (myPgm != nullptr) {
            // delete the existing Program object
            delete myPgm;
        }
    }
    // Create a Program object for this fileName
    myPgm = new Program(fileName);
    // Add it to the map
    pgmMap.insert(fileName, myPgm);

    //qDebug()  << "Created the Program Object for file: " + fileName;
    //qDebug()  << "pgmMap size: " + QString(pgmMap.size());


    if (myPgm->compile(inSrcTxt, &compiledTxt, errTxt) == false) {

        return false;
    }

   //compiledTxt =  " Will be a JSON or XML document once implemented ......\n"; // To be removed
   QString compiledFileName = fileName + ".json";

   // save the compiled file (in xml format)
   saveFile(compiledFileName, &compiledTxt, errTxt);

   currentFileCompiled = true;
   return true;
}

bool MainController::run(QString *inSrcTxt, QString *outResultTxt, QString *errTxt)
{
    QString compiledTxt;
    QString compiledFileName = currentFileName +".json";
    bool    needToCompile = true;

    if (currentFileCompiled) {
        QString programTxt = "";

        // read the saved current program file from the persistent storage
        openFile(currentFileName, &programTxt, errTxt);

       // Check if the text-editor program is same as the saved program
        if (QString::compare((*inSrcTxt), &programTxt,  Qt::CaseSensitive) == 0) {
            needToCompile = false;
        }
    }

    if (needToCompile) {
        qDebug()  << "Compiling before Run... ";

        // first compile the program in text-editor
        if (compile(inSrcTxt, errTxt) == false) {
            return false;
        }
    }

    // Now read the compiled json file from the persistent storage
    if (openFile(compiledFileName, &compiledTxt, errTxt) == false) {
        return false;
    }

    //qDebug()  << "Run Program: " + compiledTxt;

    //Temporary, replace with correct implementation
    if(myPgm != nullptr){
        myPgm->run(&compiledTxt, resultConsole, errTxt);
    } else {

    }

    //*outResultTxt = "Run finished"; // To Be Removed
    return true;
}
