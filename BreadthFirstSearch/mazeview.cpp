#include "mazeview.h"
#include <iostream>
#include <QtGui>

using namespace std;
MazeView::MazeView(MazeModel *pmodel):model(pmodel){

}

void MazeView::advance(int phase){
    if ( phase == 0 )
        model->exploreMore();
    else
        update();
}

void MazeView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QBrush whitebrush(Qt::white);
    QBrush blackbrush(Qt::black);
    QBrush yellowbrush(Qt::yellow);
    QBrush greenbrush(Qt::green);
    QBrush graybrush(Qt::gray);
    QBrush currbrush;
    int cell;
    Location dest = model->getDestination();

    for(int i = 0; i < model->SIZE; i ++)
        for(int j = 0 ; j < model->SIZE ; j ++){
            cell = model->get(i, j);
            switch (cell){
            case MazeModel::OPEN:
                currbrush = whitebrush;
                break;
            case MazeModel::WALL:
                currbrush = blackbrush;
                break;
            case MazeModel::QUEUED:
                currbrush = yellowbrush;
                break;
            case MazeModel::SOLUTION:
                currbrush = greenbrush;
                break;
            case MazeModel::DEQUEUED:
                currbrush = graybrush;
                break;
            }
            if ( dest.row == i && dest.col == j)
                currbrush = greenbrush;

            painter->setBrush(currbrush);
            painter->drawRect(j*LOCSIZE, i*LOCSIZE, LOCSIZE, LOCSIZE);
        }
}

QRectF MazeView::boundingRect() const{
    return QRect(0, 0, model->SIZE*LOCSIZE, model->SIZE*LOCSIZE);
}

void MazeView::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qreal x = event->pos().x();
    qreal y = event->pos().y();
    model->toggle((int)y/LOCSIZE, (int)x/LOCSIZE);
    update();
}

