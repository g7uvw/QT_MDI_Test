#include "sliceview.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow tb;
    tb.show();

    return a.exec();
}
