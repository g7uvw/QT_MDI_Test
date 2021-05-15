#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QMdiArea;
class QMdiSubWindow;
class MDI_View;
QT_END_NAMESPACE

class MdiChild;
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMdiArea *mdiArea;
    MDI_View *XY;
    MDI_View *XZ;
    MDI_View *YZ;

private slots:
    MDI_View *createMdiChild();
};
#endif // MAINWINDOW_H
