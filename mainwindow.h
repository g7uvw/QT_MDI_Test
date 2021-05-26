#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QtWidgets>
#include <QtCore>
#include <QWheelEvent>
#include "sliceview.h"

//QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
//class QGraphicsView;
//class QGraphicsItem;
//class QPixmap;

//QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    bool isUntitled;
    bool XY_on = true;
    bool XZ_on = false;
    bool YZ_on = false;

    SliceView *XY;
    SliceView *YZ;
    SliceView *XZ;


private slots:

    void on_actionXY_toggled(bool arg1);
};
#endif // MAINWINDOW_H
