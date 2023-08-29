#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sliceview.h"


MainWindow::MainWindow()
    :   ui(new Ui::MainWindow), XY(new SliceView), YZ(new SliceView), XZ(new SliceView)
{
     ui->setupUi(this);
    //setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint|Qt::SizeHint());
    setWindowFlags(Qt::WindowStaysOnTopHint);
    slicer = TOMSlicer::getInstance();
    // we start up with XY view on and showing
    XY->SetPlane(XYPLANE);
    XY->setWindowTitle(QStringLiteral("XY Slice View"));
    XY->ShowSlice(XYPLANE);
    XY->show();
    XY_on = true;

    // create other two views, but don't show them yet.
    YZ->SetPlane(YZPLANE);
    YZ->setWindowTitle(QStringLiteral("YZ Slice View"));
    YZ->ShowSlice(YZPLANE);

    XZ->SetPlane(XZPLANE);
    XZ->setWindowTitle(QStringLiteral("XZ Slice View"));
    XZ->ShowSlice(XZPLANE);
}

MainWindow::~MainWindow()
{
    QCoreApplication::quit();
    //delete ui;
}

void MainWindow::ReceiveHeader(thead header)
{
    m_Header = header;
}

QString MainWindow::strippedName(const QString &fullFileName)
{
     return QFileInfo(fullFileName).fileName();
}


void MainWindow::CreateDefaultLookup()
{
    QVector<QRgb> colorTable;
    for (auto i = 0; i < 256; i++)
        colorTable.push_back(QColor(i, i, i).rgb());
}

void MainWindow::on_actionXY_toggled(bool arg1)
{
    if (XY_on)
    {
        XY->hide();
        XY_on = false;
    }
    else
    {
        XY->show();
        XY_on = true;
    }
}

void MainWindow::on_actionYZ_toggled(bool arg1)
{
    if (YZ_on)
    {
        YZ->hide();
        YZ_on = false;
    }
    else
    {
        YZ->show();
        YZ_on = true;
    }
}

void MainWindow::on_actionXZ_toggled(bool arg1)
{
    if (XZ_on)
    {
        XZ->hide();
        XZ_on = false;
    }
    else
    {
        XZ->show();
        XZ_on = true;
    }
}

void MainWindow::on_actionDown_Slice_triggered()
{
    MainWindow::s_Slice Slice;

    // Set some defaults in case things go wrong.
    Slice.Plane  = XYPLANE;
    Slice.XSlice = 0;
    Slice.YSlice = 0;
    Slice.ZSlice = 0;

    switch (m_Plane)
    {
    case XYPLANE:
            Slice.Plane = XYPLANE;
            if (m_ZSlice == 0)
            {
                Slice.ZSlice = 0;
                return;
            }
            --m_ZSlice;
            Slice.ZSlice = m_ZSlice;
            break;

        case XZPLANE:
            Slice.Plane = XZPLANE;
            if (m_YSlice == 0)
            {
                Slice.YSlice = 0;
                return;
            }
            --m_YSlice;
            Slice.YSlice = m_YSlice;
            break;

        case YZPLANE:
            Slice.Plane = YZPLANE;
            if (m_XSlice == 0)
            {
                Slice.XSlice = 0;
                return;
            }
            --m_XSlice;
            Slice.XSlice = m_XSlice;
            break;
        }
        --m_CurrentSlice;

    if (m_CurrentSlice == 0)
        m_CurrentSlice = 0;

    //view_area->UpdateSlice(Slice);

}

void MainWindow::on_actionUpSlice_triggered()
{
    switch (m_Plane	)
        {
        case XYPLANE:
            if (m_ZSlice == m_Header.zsize-1)
                return;
            ++m_ZSlice;
            break;
        case XZPLANE:
            if (m_YSlice == m_Header.ysize-1)
                return;
            ++m_YSlice;
            break;
        case YZPLANE:
            if (m_XSlice == m_Header.xsize-1)
                return;
            ++m_XSlice;
            break;
        }
        ++m_CurrentSlice;

    MainWindow::s_Slice Slice;
    Slice.Plane = m_Plane;
    Slice.XSlice = m_XSlice;
    Slice.YSlice = m_YSlice;
    Slice.ZSlice = m_ZSlice;
    //view_area->UpdateSlice(Slice);
}



//void MainWindow::on_actionXY_Slice_triggered()
//{
//    m_Plane = XYPLANE;
//    QTomV_View::s_Slice Slice;
//    Slice.Plane = m_Plane;
//    Slice.XSlice = m_XSlice;
//    Slice.YSlice = m_YSlice;
//    Slice.ZSlice = m_ZSlice;
//    view_area->UpdateSlice(Slice);
//}

//void MainWindow::on_actionYZ_Slice_triggered()
//{
//    m_Plane = YZPLANE;
//    QTomV_View::s_Slice Slice;
//    Slice.Plane = m_Plane;
//    Slice.XSlice = m_XSlice;
//    Slice.YSlice = m_YSlice;
//    Slice.ZSlice = m_ZSlice;
//    view_area->UpdateSlice(Slice);
//}

//void MainWindow::on_actionXZ_Slice_triggered()
//{
//    m_Plane = XZPLANE;
//    QTomV_View::s_Slice Slice;
//    Slice.Plane = m_Plane;
//    Slice.XSlice = m_XSlice;
//    Slice.YSlice = m_YSlice;
//    Slice.ZSlice = m_ZSlice;
//    view_area->UpdateSlice(Slice);
//}



//QTomV_View *MainWindow::createMdiChild()
//{
//    QTomV_View *child = new QTomV_View;
//    mdiArea->addSubWindow(child);
//    return child;
//}



void MainWindow::Texit(QString Message)
{
    QMessageBox msgBox;
    msgBox.setText(Message);
    msgBox.exec();
    qApp->exit();
}
void MainWindow::Alert(QString Message, QString Title)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(Title);
    msgBox.setText(Message);
    msgBox.exec();
}




//void MainWindow::on_actionInformation_triggered()
//{
//    InfoDialog *id = new InfoDialog(m_Header);
//    id->show();
//}




void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionOpen_triggered()
{
//    m_FileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.tom)"));
//    QFile TOMFILE(m_FileName);
//    if (!TOMFILE.open(QIODevice::ReadOnly)) Alert("Cannot open file","File open error.");
//    qint64 bytes = TOMFILE.read((char*) &m_Header, sizeof(m_Header));
//    if (bytes != sizeof(m_Header)) Alert("Cannot read header", "File open error.");

//    size_t volumeBytes = m_Header.xsize*m_Header.ysize *m_Header.zsize;
//    std::cerr << "Trying to allocate vector with storage for  " << volumeBytes << " bytes." << std::endl;
//    try {
//        view_area->volume.resize(volumeBytes);
//    }
//    catch (std::length_error& vecerror){
//        std::cerr << vecerror.what() << std::endl;
//        return;
//    }
//    TOMFILE.seek(0);                // seek to start so we're in a known place
//    TOMFILE.seek(sizeof(m_Header));  // seek to end of header
//    TOMFILE.read((char*) &view_area->volume[0],volumeBytes);
//    TOMFILE.close();

//    view_area->ReceiveHeader(m_Header);
//    view_area->setWindowTitle(QFileInfo(m_FileName).fileName());
//    m_Plane = XYPLANE;
//    m_CurrentSlice = m_Header.zsize/2;
//    m_XSlice = m_Header.xsize / 2;
//    m_YSlice = m_Header.ysize / 2;
//    m_ZSlice = m_Header.zsize / 2;

//    QTomV_View::s_Slice Slice;
//    Slice.Plane = m_Plane;
//    Slice.XSlice = m_XSlice;
//    Slice.YSlice = m_YSlice;
//    Slice.ZSlice = m_ZSlice;
//    view_area->UpdateSlice(Slice);
}


//void MainWindow::wheelEvent(QWheelEvent *event)
//{

//    auto numDegrees = event->angleDelta();

//    if (numDegrees.y() > 0)
//        on_actionUpSlice_triggered();
//    else
//        on_actionDown_Slice_triggered();

//    event->accept();
//}
