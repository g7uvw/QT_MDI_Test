#include "sliceview.h"
#include "ui_sliceview.h"

SliceView::SliceView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SliceView)
{
    ui->setupUi(this);
    viewArea = new QGraphicsView;
    scene = new QGraphicsScene(0, 0, this->x(), this->y(), this);
    viewArea->setScene(scene);
    //setCentralWidget(view);
    setCentralWidget(viewArea);

}

SliceView::~SliceView()
{
    delete ui;
}

void SliceView::SetPlane(const short plane)
{
    m_plane = plane;
}

void SliceView::ShowSlice(size_t slice)
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
    scene->addLine(0,0,100,100,QPen(Qt::yellow));
    //scene->addRect(QRectF(0, 0, 500, 500), QPen(Qt::black), QBrush(Qt::green));

    scene->update();
    //auto width = image.width();
    //auto height = image.height();
    //viewArea->resize(width,height);
    //viewArea->resize(scene->width(),scene->height());
    //viewArea->update();
}
