#include "mainwindow.h"
#include "toolbar.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToolBar tb;
    tb.show();

//    MainWindow XY(XYPLANE);
//    MainWindow YZ(YZPLANE);
//    MainWindow XZ(XZPLANE);
//    XY.show();
//    YZ.show();
//    XZ.show();


    return a.exec();
}
