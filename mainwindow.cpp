#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "view.h"

MainWindow::MainWindow()
    : mdiArea(new QMdiArea)
{
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea);

    XY = createMdiChild();
    XY->autoFillBackground();
    XY->show();
    MDI_View *YZ = createMdiChild();
    YZ->autoFillBackground();
    YZ->show();
    MDI_View *XZ = createMdiChild();
    XZ->autoFillBackground();
    XZ->show();


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
