#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "view.h"

MainWindow::MainWindow(const short plane)
    : viewArea(new QGraphicsView)
{
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;
    view = new QGraphicsView;
    scene = new QGraphicsScene(0, 0, this->x(), this->y(), this);
    view->setScene(scene);
    setCentralWidget(view);
    setCentralWidget(viewArea);

    ShowSlice(plane);

}

MainWindow::~MainWindow()
{
    //delete ui;
}

//MDI_View *MainWindow::createMdiChild()
//{
//    MDI_View *child = new MDI_View;
//    mdiArea->addSubWindow(child);
//    return child;
//}

void MainWindow::ShowSlice(const short plane)
{
    scene->clear();
    if (plane == XYPLANE)
    {
        setWindowTitle("XY");
        image = QPixmap(":/images/XY.png");
    }
    else if (plane == YZPLANE)
    {
        setWindowTitle("YZ");
        image = QPixmap(":/images/YZ.png");
    }
    else
    {
        setWindowTitle("XZ");
        image = QPixmap(":/images/XZ.png");
    }

    scene->addPixmap(image);
    scene->update();
    auto width = image.width();
    auto height = image.height();
    view->resize(width,height);
    view->resize(scene->width(),scene->height());
    view->update();
}
