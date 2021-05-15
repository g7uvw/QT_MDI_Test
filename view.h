#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QtWidgets>
#include "mainwindow.h"
#include <QtCore>
#include <QtWidgets>
#include <QWheelEvent>

const short XYPLANE = 1;
const short XZPLANE = 2;
const short YZPLANE = 3;

class MDI_View : public QMainWindow
{
     Q_OBJECT
public:
    MDI_View();
    void ShowSlice();

private:
    bool isUntitled;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPixmap image;
};

#endif // VIEW_H
