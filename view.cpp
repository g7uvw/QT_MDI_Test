#include "view.h"

MDI_View::MDI_View()
{
    //setWindowTitle("New");
    setAttribute(Qt::WA_DeleteOnClose);
    isUntitled = true;
    view = new QGraphicsView;
    scene = new QGraphicsScene(0, 0, this->x(), this->y(), this);
    view->setScene(scene);
    setCentralWidget(view);

    // cargo cult programming - https://stackoverflow.com/questions/32714105/mousemoveevent-is-not-called
    //QCoreApplication::instance()->installEventFilter(this);
}


void MDI_View::ShowSlice(const short plane)
{
    scene->clear();
    if (plane == XYPLANE)
    {
        image = QPixmap(":/images/XY.png");
    }
    else if (plane == YZPLANE)
    {
        image = QPixmap(":/images/YZ.png");
    }
    else
        image = QPixmap(":/images/XZ.png");

    scene->addPixmap(image);
    scene->update();
    auto width = image.width();
    auto height = image.height();
    view->resize(width,height);
    view->resize(scene->width(),scene->height());
    view->update();
}
