#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QtWidgets>
#include <QtCore>
#include <QWheelEvent>
#include "mainwindow.h"

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
    bool isUntitled;
    bool XY_on = true;
    bool XZ_on = false;
    bool YZ_on = false;

    MainWindow *XY;
    MainWindow *YZ;
    Ui::MainWindow *XZ;


private slots:

    void on_actionXY_toggled(bool arg1);
};
#endif // TOOLBAR_H
