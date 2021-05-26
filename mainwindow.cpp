#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sliceview.h"


MainWindow::MainWindow()
    :   ui(new Ui::MainWindow), XY(new SliceView), YZ(new SliceView), XZ(new SliceView)
{
     ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);

    // we start up with XY view on and showing
    XY->SetPlane(XYPLANE);
    XY->setWindowTitle(QStringLiteral("XY Slice View"));
    XY->show();
    XY_on = true;

    // create other two views, but don't show them yet.
    YZ->SetPlane(YZPLANE);
    YZ->setWindowTitle(QStringLiteral("YZ Slice View"));

    XZ->SetPlane(XZPLANE);
    XZ->setWindowTitle(QStringLiteral("XZ Slice View"));

}

MainWindow::~MainWindow()
{
    QCoreApplication::quit();
    //delete ui;
}





void MainWindow::on_actionXY_toggled(bool arg1)
{
    if (XY_on)
    {
        XY->hide();
        XY_on = false;
    }
    else
    {
        XY->show();
        XY_on = true;
    }
}
