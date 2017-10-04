#ifndef MAZEVIEW_H
#define MAZEVIEW_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QGraphicsSceneMouseEvent>
#include "mazemodel.h"
#include "location.h"

class MazeView : public QGraphicsItem{

private:
    MazeModel* model;
public:
    static const int LOCSIZE = 10;
    MazeView(MazeModel* pmodel);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MAZEVIEW_H
