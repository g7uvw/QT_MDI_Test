#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "ui_toolbar.h"


//QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
    class toolbar;
}
//class QGraphicsView;
//class QGraphicsItem;
//class QPixmap;
//QT_END_NAMESPACE

class toolbar : public QWidget
{
    Q_OBJECT

public:
    explicit toolbar(QWidget *parent = nullptr);

signals:

private:
    Ui::toolbar *ui;
};

#endif // TOOLBAR_H
