#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QtWidgets>
#include <QtCore>
#include <QWheelEvent>


//QT_BEGIN_NAMESPACE
namespace Ui { class ToolBar;}
//class QGraphicsView;
//class QGraphicsItem;
//class QPixmap;

//QT_END_NAMESPACE


class ToolBar : public QMainWindow
{
    Q_OBJECT

public:
    ToolBar();
    ~ToolBar();



private:
    Ui::ToolBar *ui;
    //QGraphicsView *viewArea;


    bool isUntitled;



private slots:

};
#endif // TOOLBAR_H
