#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QtWidgets>
#include <QtCore>
#include <QWheelEvent>
#include "tomslicer.h"
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
    struct thead m_Header;
    bool m_Empty;
    bool m_New;

    uint16_t xsize,ysize,zsize,num_samples,num_proj,num_blocks,num_slices,num_frames;
    float scale,voltage,current,pixel_size,exposure;
    uint32_t theta;
    QString time,duration,owner,user,specimen,scan,comment;

    void ReceiveHeader(thead header);
    std::vector<uint8_t> volume;

    struct s_Slice
    {
        uint8_t Plane  = XYPLANE;
        size_t  XSlice = 0;
        size_t  YSlice = 0;
        size_t  ZSlice = 0;

    };

    void UpdateSlice(s_Slice Slice);

private:
    Ui::MainWindow *ui;
    bool isUntitled;
    bool XY_on = true;
    bool XZ_on = false;
    bool YZ_on = false;

    SliceView *XY;
    SliceView *YZ;
    SliceView *XZ;
    TOMSlicer* slicer;

protected:
    void AllocateMemory(void);
    void StartMessage(void);
    void CreateDefaultLookup(void);
    void UpdateSlice(void);
    void CreateBitmap();
    unsigned char *** GetIm();
    QString m_FilePath;
    QString m_FileName;
protected:

    QByteArray tomData;
    QVector<QRgb> colorTable;
    //struct thead m_Header;
    //TOMSlicer* slicer;
    //bool eventFilter(QObject *obj, QEvent *event);
    //void mousePressEvent ( QMouseEvent * e );

    //void CreateDefaultLookup(void);
    void wipe();
    void showSlice(QImage &slice);
    //unsigned int m_Plane, m_CurrentSlice, m_XSlice, m_YSlice, m_ZSlice;

private:
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);
    //QGraphicsView *view;
    //QGraphicsScene *scene;
    QPixmap currentslice;
    QString curFile;
    //bool isUntitled;
public:
    int m_MinX;
    int m_MaxX;
    int m_MinY;
    int m_MaxY;
    int m_MinZ;
    int m_MaxZ;
    unsigned int m_CurrentSlice, m_XSlice, m_YSlice, m_ZSlice;
    unsigned int m_Plane;
    //unsigned int m_XSlice, m_YSlice, m_ZSlice, m_BMPSlice, m_BMPPlane,m_BitmapBufferSize;
    bool m_CropTags;
    void Texit(QString Message);
    void Alert(QString Message, QString Title);

private slots:

    void on_actionXY_toggled(bool arg1);
    void on_actionYZ_toggled(bool arg1);
    void on_actionXZ_toggled(bool arg1);
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionDown_Slice_triggered();
    void on_actionUpSlice_triggered();
};
#endif // MAINWINDOW_H
