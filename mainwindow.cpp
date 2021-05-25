#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sliceview.h"


MainWindow::MainWindow()
    :   ui(new Ui::MainWindow), XY(new SliceView)//, YZ(new ViewWindow)
{
     ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);

    XY->SetPlane(XYPLANE);
    XY->show();
    XY_on = true;

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
