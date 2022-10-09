#include "graphthread.h"

GraphThread::GraphThread( int widthLimit, int heightLimit, QObject *parent )
    : QThread(parent)
    , _widthLimit( widthLimit )
    , _heightLimit( heightLimit )
{
    _state = ThreadState::Stop;
}

void GraphThread::threadPause()
{
    this->_mutex.lock();
}

void GraphThread::threadResume()
{
    this->_mutex.unlock();
}

void GraphThread::run()
{
    while( threadState() != ThreadState::Stop )
    {
        _mutex.lock();
        emit drawPoint( qrand() % ( _widthLimit + 1 ), qrand()% ( _heightLimit + 1 ) );
        this->sleep( 1 );
        _mutex.unlock();
    }

}

void GraphThread::setThreadState( ThreadState state )
{
    _state = state;
}

GraphThread::ThreadState GraphThread::threadState()
{
    return _state;
}
