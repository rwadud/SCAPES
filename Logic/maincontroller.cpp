#include "maincontroller.h"
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
    Program *myPgm = nullptr;

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

   return true;
}
