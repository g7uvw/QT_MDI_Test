#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QtWidgets>
#include <QtCore>
#include <QWheelEvent>
//#include "view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QGraphicsView;
class QGraphicsItem;
class QPixmap;
////class QMdiArea;
////class QMdiSubWindow;
////class MDI_View;
QT_END_NAMESPACE

//class MdiChild;
//QT_BEGIN_NAMESPACE
//class QAction;
//class QMenu;
//class QMdiArea;
//class QMdiSubWindow;
//QT_END_NAMESPACE

const short XYPLANE = 1;
const short XZPLANE = 2;
const short YZPLANE = 3;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    //MainWindow(const short plane);
    ~MainWindow();
    void SetPlane(const short plane);
    void ShowSlice(size_t slice);


private:
    Ui::MainWindow *ui;
    QGraphicsView *viewArea;
    //QMdiArea *mdiArea;
    //MDI_View *XY;
   // MDI_View *XZ;
    //MDI_View *YZ;

    short m_plane;

    bool isUntitled;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPixmap image;


private slots:
    //MDI_View *createMdiChild();
};
#endif // MAINWINDOW_H
