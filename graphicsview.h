#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QObject>


class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView( QWidget *parent = nullptr );
    void initialization();
    void drawCoordinatePlane();

public slots:
    void drawPoint( qreal x, qreal y );

};

#endif // GRAPHICSVIEW_H
