#include "sliceview.h"
#include "ui_sliceview.h"

SliceView::SliceView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SliceView)
{
    ui->setupUi(this);
    viewArea = new QGraphicsView;

    scene = new QGraphicsScene(this);
    scene->setSceneRect(QRectF());

   // scene->setSceneRect(-1.5, -1.5, 1.5, 1.5);
    viewArea->setScene(scene);
    //viewArea->show();

    //scene = new QGraphicsScene(0, 0, this->x(), this->y(), this);
    //viewArea->setScene(scene);
    //scene->setAligment(Qt::AlignTop | Qt::AlignLeft);
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
    QRectF bound = scene->itemsBoundingRect();
    //slice not used in minimal example

    scene->clear();
    if (m_plane == XYPLANE)
    {
        setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
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
    bound.setWidth(image.width());
    bound.setHeight(image.height());

    viewArea->fitInView(bound, Qt::KeepAspectRatio);
    viewArea->centerOn(0, 0);


    scene->addLine(0,0,100,100,QPen(Qt::yellow));




    viewArea->update();
    scene->update();
    viewArea->show();
    auto width = image.width();
    auto height = image.height();
    viewArea->resize(width,height);
    viewArea->resize(scene->width(),scene->height());


}
