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



class MDI_View : public QMainWindow
{
     Q_OBJECT
public:
    MDI_View();
    void ShowSlice(const short plane);

private:
    bool isUntitled;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPixmap image;
};

#endif // VIEW_H
