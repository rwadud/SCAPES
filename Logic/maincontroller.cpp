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
bool MainController::openFile(QString filename, QString *outText)
{
    QString errTxt = "";
    if (store->getSourceData(filename, outText, &errTxt) == false) {
        QMessageBox msgBox;
        msgBox.setText("Error! Cannot Open file: " + errTxt);
        msgBox.exec();

        return false;
    }

    return true;
}
bool MainController::saveFile(QString filename, QString *inText)
{
    QString errTxt = "";
    if (store->setSourceData(filename, inText, &errTxt) == false) {
        QMessageBox msgBox;
        msgBox.setText("Error! Cannot Open file: " + errTxt);
        msgBox.exec();

        return false;
    }
    return true;
}

void MainController::compile(QString *inSrcTxt)
{

    QString fileName = currentFileName;
    QString compiledTxt; //  JSON or XML format
    QString errTxt = "";
    Program *myPgm = nullptr;

    // save the data
    saveFile(fileName, inSrcTxt);

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


    if (myPgm->compile(inSrcTxt, &compiledTxt, &errTxt) == false) {
        QMessageBox msgBox;
        msgBox.setText("Error! Compile failed: " + errTxt);
        msgBox.exec();
       
       return;
    }

   compiledTxt =  " Will be a JSON or XML document once implemented ......\n"; // To be removed
   QString compiledFileName = fileName + ".json";

   // save the compiled file (in xml format)
   saveFile(compiledFileName, &compiledTxt);

}
