#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include "graphicsview.h"
#include <QPainter>

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
{
    ui->setupUi(this);
    _scene = new QGraphicsScene( this ) ;

    ui->graphicsView->setScene( _scene );
    ui->graphicsView->scale( 1, -1 );
    ui->graphicsView->initialization();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonStart_clicked()
{
    if ( _graphikThread->threadState() == GraphThread::ThreadState::Pause )
    {
        _graphikThread->setThreadState( GraphThread::ThreadState::Running ) ;
        _graphikThread->threadResume();
    }
    else
    {
        _newThread();
        _graphikThread->setThreadState( GraphThread::ThreadState::Running ) ;
        ui->graphicsView->drawCoordinatePlane();
        _graphikThread->start();
    }
}


void MainWindow::on_pushButtonPause_clicked()
{
    if ( _graphikThread->threadState() == GraphThread::Running )
    {
        _graphikThread->setThreadState( GraphThread::ThreadState::Pause );
        _graphikThread->threadPause();
    }
}


void MainWindow::on_pushButtonStop_clicked()
{
    if ( _graphikThread->threadState() != GraphThread::ThreadState::Stop )
    {
        _graphikThread->setThreadState( GraphThread::ThreadState::Stop );
        _scene->clear();
        _graphikThread->wait();
        _graphikThread->quit();
    }
}

void MainWindow::_newThread()
{
    _graphikThread = new GraphThread( ui->graphicsView->width(), ui->graphicsView->height(), this );
    connect( _graphikThread, &GraphThread::drawPoint, ui->graphicsView, &GraphicsView::drawPoint );
    ui->graphicsView->moveToThread( _graphikThread );
}

