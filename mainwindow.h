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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMdiArea *mdiArea;

private slots:
    MDI_View *createMdiChild();
};
#endif // MAINWINDOW_H
