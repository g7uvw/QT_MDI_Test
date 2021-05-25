#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "view.h"

//MainWindow::MainWindow(const short plane)
MainWindow::MainWindow()
    : viewArea(new QGraphicsView)
{
    ui->setupUi(this);
    //isUntitled = true;
    viewArea = new QGraphicsView;
    scene = new QGraphicsScene(0, 0, this->x(), this->y(), this);
    viewArea->setScene(scene);
    //setCentralWidget(view);
    setCentralWidget(viewArea);


}

MainWindow::~MainWindow()
{
}


void MainWindow::SetPlane(const short plane)
{
    m_plane = plane;
}

void MainWindow::ShowSlice(size_t slice)
{
    scene->clear();
    if (m_plane == XYPLANE)
    {
        setWindowTitle("XY");
        image = QPixmap(":/images/XY.png");
    }
    else if (m_plane == YZPLANE)
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
    viewArea->resize(width,height);
    viewArea->resize(scene->width(),scene->height());
    viewArea->update();
}
