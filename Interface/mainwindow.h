#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "maincontroller.h"
#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent, MainController *ctlrRef);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionCompile_triggered();

    void on_actionRun_triggered();

    void on_actionAbout_triggered();

    void on_actionDocumentation_triggered();

    void on_textEdit_cursorPositionChanged();


private:
    Ui::MainWindow *ui;
    MainController *ctlr; // reference to the Controller object
    void saveFile(QString fileName);
    bool loadFile(QString fileName);
    void compile();
    void run();
};

#endif // MAINWINDOW_H
