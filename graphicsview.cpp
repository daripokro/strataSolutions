#include "graphicsview.h"
#include <math.h>
#include <QGraphicsItem>

GraphicsView::GraphicsView( QWidget *parent ) : QGraphicsView( parent )
{
}

void GraphicsView::initialization()
{
    this->setMinimumHeight( 300 );
    this->setMinimumWidth( 500 );

    scene()->setSceneRect( 0, 0, this->width(), this->height() );
    drawCoordinatePlane();
}

void GraphicsView::drawCoordinatePlane()
{
    this->scene()->addLine( QLineF( 0, 0, this->width(), 0 ) );
    this->scene()->addLine( QLineF( 0, 0, 0, this->height() ) );
}

void GraphicsView::drawPoint(qreal x, qreal y)
{
    scene()->addEllipse(x - 1, y - 1, 3.0, 3.0, QPen(), QBrush( Qt::SolidPattern ) );
}




