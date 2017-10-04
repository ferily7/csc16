#ifndef ROBOTRACEVIEW_H
#define ROBOTRACEVIEW_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QRect>
#include <vector>
#include <QImage>
#include "robotrace.h"
using namespace std;

class RobotRaceView : public QGraphicsItem
{
private:
    static const int LEFT = 0;
    static const int RIGHT = 1;
    RobotRace theworld;
    vector<int> keyPresses;
    int tickTime, winner;
    QImage robot;
public:
    RobotRaceView(RobotRace &world);
    void keyPressEvent(QKeyEvent *event);
    void advance(int phase);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // ROBOTRACEVIEW_H
