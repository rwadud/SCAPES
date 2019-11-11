#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "compileoption.h"
#include "saveoption.h"
#include "loadoption.h"
#include "filebrowser.h"
#include "notifymsg.h"
#include <QString>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, MainController *ctlrRef) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    ctlr = ctlrRef; // cache it

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveFile(QString fileName)
{
    QString      srcText =  ui->textEdit->toPlainText();
    QString      errText;
    SaveOption   option(this);

    // Save the  program
    if (option.save(ctlr, fileName, &srcText, &errText) == false) {
        NotifyMsg::show("File Save Failed: " + errText, ui->statusBar);
    } else {
        NotifyMsg::show("File Save Done!", ui->statusBar);
    }

}

bool MainWindow::loadFile(QString fileName)
{
    QString      outText;
    QString      errText;
    LoadOption   option(this);
    bool         rc = false;

    // get the data
    rc = option.load(ctlr, fileName, &outText, &errText);
    if (rc == true) {
        // Put file data in the Editor window
        ui->textEdit->setText(outText);
    } else {
        NotifyMsg::show("File Load Failed: " + errText, ui->statusBar);
    }

    return rc;
}
void MainWindow::compile()
{
    QString         srcText =  ui->textEdit->toPlainText();
    QString         errText;
    CompileOption  option;

    if (option.compile(ctlr, &srcText, &errText) == false) {
        NotifyMsg::show("Compile Failed: " + errText, ui->statusBar);
    } else {
        NotifyMsg::show("Compile OK!", ui->statusBar);
    }

}
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionNew_triggered()
{
    ctlr->setCurrentFileName("");
    ui->textEdit->setText("");
    setWindowTitle("SCAPES");
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = FileBrowser::getOpenFileName(this);

    if (loadFile(fileName) == false) {
        return;
    }
    // cache the current file name
    ctlr->setCurrentFileName(fileName);
}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = ctlr->getCurrentFileName();

    // save program text
    saveFile(fileName);
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = FileBrowser::getSaveFileName(this);

    // save program text
    saveFile(fileName);

    // cache the current file name
    ctlr->setCurrentFileName(fileName);
}

void MainWindow::on_actionCompile_triggered()
{
   compile();
}

void MainWindow::on_actionRun_triggered()
{
    //ctlr->run();
}

void MainWindow::on_actionAbout_triggered()
{
    QString aboutText = "The SCAPES system is a development environment \n"
                        "to write, compile and execute programs. \n";
    aboutText += "Version: 1.0 \n";
    aboutText += "Authors: Pallab Saha, Redwan, Salim, Robby\n";
    aboutText += "Copyright:, SCAPES (C), 2019";
    QMessageBox::about(this,tr("About SCAPES"), aboutText);
}

void MainWindow::on_actionDocumentation_triggered()
{
    QString docText = "The SCAPES system is a development environment to write, compile and execute programs \n"
                       "in SCAPL(School of Computer Science Assembly Programming Language). \n\n";

    docText += "To write a new program use New option from File Menu and write program in the Editor Window.\n";
    docText += "To save a program written in the Editor window, use Save or Save As option from File Menu.\n";
    docText += "To load a saved program into the Editor window, use Open  option from File Menu.\n";
    docText += "To compile a program written in the Editor window, use Compile option from Build Menu.\n";
    docText += "To execute a program written in the Editor window, use Run option from Build Menu\n";

    QMessageBox::about(this,tr("SCAPES System"), docText);
}

void MainWindow::on_textEdit_cursorPositionChanged()
{
    int line = ui->textEdit->textCursor().blockNumber()+1;
    int pos = ui->textEdit->textCursor().columnNumber()+1;
    ui->statusBar->showMessage(QString("Ln %1, Col %2").arg(line).arg(pos));
}

