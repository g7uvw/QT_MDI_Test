#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sliceview.h"


MainWindow::MainWindow()
    :   ui(new Ui::MainWindow), XY(new SliceView), YZ(new SliceView), XZ(new SliceView)
{
     ui->setupUi(this);
    //setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint|Qt::SizeHint());
    setWindowFlags(Qt::WindowStaysOnTopHint);

    // we start up with XY view on and showing
    XY->SetPlane(XYPLANE);
    XY->setWindowTitle(QStringLiteral("XY Slice View"));
    XY->ShowSlice(XYPLANE);
    XY->show();
    XY_on = true;

    // create other two views, but don't show them yet.
    YZ->SetPlane(YZPLANE);
    YZ->setWindowTitle(QStringLiteral("YZ Slice View"));
    YZ->ShowSlice(YZPLANE);

    XZ->SetPlane(XZPLANE);
    XZ->setWindowTitle(QStringLiteral("XZ Slice View"));
    XZ->ShowSlice(XZPLANE);
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

void MainWindow::on_actionYZ_toggled(bool arg1)
{
    if (YZ_on)
    {
        YZ->hide();
        YZ_on = false;
    }
    else
    {
        YZ->show();
        YZ_on = true;
    }
}

void MainWindow::on_actionXZ_toggled(bool arg1)
{
    if (XZ_on)
    {
        XZ->hide();
        XZ_on = false;
    }
    else
    {
        XZ->show();
        XZ_on = true;
    }
}
