#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
        ui->setupUi(this);
    XY = createMdiChild();
    XY->autoFillBackground();
    XY->showMaximized();
    //MDI_View *YZ = createMdiChild();
    //MDI_View *XZ = createMdiChild();


}

MainWindow::~MainWindow()
{
    delete ui;
}

MDI_View *MainWindow::createMdiChild()
{
    MDI_View *child = new MDI_View;
    mdiArea->addSubWindow(child);
    return child;
}
