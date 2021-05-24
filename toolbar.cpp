#include "toolbar.h"
#include "ui_toolbar.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"


ToolBar::ToolBar()
    :   ui(new Ui::ToolBar), XY(new Ui::MainWindow)
{
     ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);


 //       MainWindow *XY = new MainWindow(XYPLANE);
        //MainWindow *YZ = new MainWindow(YZPLANE);
        //MainWindow *XZ = new MainWindow(XZPLANE);
//        XY->show();
    //    YZ.show();
    //    XZ.show();

}

ToolBar::~ToolBar()
{
    QCoreApplication::quit();
    //delete ui;
}

//MDI_View *MainWindow::createMdiChild()
//{
//    MDI_View *child = new MDI_View;
//    mdiArea->addSubWindow(child);
//    return child;
//}



void ToolBar::on_actionXY_toggled(bool arg1)
{
    if (XY_on)
    {
        //XY->hide();
    }
}
