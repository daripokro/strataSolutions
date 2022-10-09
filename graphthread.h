#ifndef GRAPHTHREAD_H
#define GRAPHTHREAD_H

#include <QThread>
#include <QObject>
#include <QMutex>

class GraphThread : public QThread
{
    Q_OBJECT
public:
    explicit GraphThread( int widthLimit, int heightLimit, QObject *parent = nullptr );
    void threadPause();
    void threadResume();

    enum ThreadState
    {
        Running,
        Pause,
        Stop
    };

    void setThreadState( ThreadState state );
    ThreadState threadState();

signals:
    void drawPoint( qreal x, qreal y );

protected:
    void run() override;

private:
    QMutex _mutex;
    int _widthLimit;
    int _heightLimit;
    ThreadState _state;

};

#endif // GRAPHTHREAD_H
