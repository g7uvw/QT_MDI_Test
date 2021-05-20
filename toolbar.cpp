#include "toolbar.h"
#include "ui_toolbar.h"


ToolBar::ToolBar()
    :   ui(new Ui::ToolBar)
{
     ui->setupUi(this);

//    //isUntitled = true;
//    viewArea = new QGraphicsView;
//    scene = new QGraphicsScene(0, 0, this->x(), this->y(), this);
//    viewArea->setScene(scene);
//    //setCentralWidget(view);
//    setCentralWidget(viewArea);

    //ShowSlice(plane);

}

ToolBar::~ToolBar()
{
    //delete ui;
}

//MDI_View *MainWindow::createMdiChild()
//{
//    MDI_View *child = new MDI_View;
//    mdiArea->addSubWindow(child);
//    return child;
//}


