#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QGraphicsScene>
#include "graphthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonPause_clicked();

    void on_pushButtonStop_clicked();

private:
    void _newThread();

    Ui::MainWindow *ui;
    GraphThread *_graphikThread;
    QGraphicsScene *_scene;

};
#endif // MAINWINDOW_H
