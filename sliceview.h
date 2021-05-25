#ifndef SLICEVIEW_H
#define SLICEVIEW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QtWidgets>
#include <QtCore>
#include <QWheelEvent>

namespace Ui {
class SliceView;
}


const short XYPLANE = 1;
const short XZPLANE = 2;
const short YZPLANE = 3;

class SliceView : public QMainWindow
{
    Q_OBJECT

public:
    explicit SliceView(QWidget *parent = nullptr);
    ~SliceView();
    void SetPlane(const short plane);
    void ShowSlice(size_t slice);


private:
    Ui::SliceView *ui;

    QGraphicsView *viewArea;

    short m_plane;

    bool isUntitled;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPixmap image;
};

#endif // SLICEVIEW_H
