#include "robotraceview.h"
#include <QString>

RobotRaceView::RobotRaceView(RobotRace &world): winner(-1), theworld(world), tickTime(0), robot(":/new/prefix1/images/robot.png")
{
    setFlags(ItemIsMovable | ItemIsFocusable | QGraphicsItem::ItemIsSelectable);
}

void RobotRaceView::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        keyPresses.push_back(0);
    }
    else if ( event->key() == Qt::Key_Right){
        keyPresses.push_back(1);
    }
}

void RobotRaceView::advance(int phase)
{

    if ( theworld.hasWinner(winner) ){
        //qDebug(QString().sprintf("here %d",winner).toStdString().c_str());
        return;
    }
    if ( phase == 1){
        tickTime = tickTime + 100;
        if ( tickTime >= 1000){
            tickTime = 0;
            theworld.update();
            update();
        }
    }
}

void RobotRaceView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QBrush redbrush(Qt::gray);
    QBrush greenbrush(Qt::gray);

    theworld.hasWinner(winner);
    redbrush.setColor(Qt::red);
    greenbrush.setColor(Qt::green);

    for(int i = 0; i < theworld.getNumRobots(); i ++){
        painter->drawImage(theworld.getRobotPos(i)*2, i * 48, robot);
    }
    for(int i = 0; i < theworld.getNumRobots()+1; i ++){
        painter->drawLine(0, i*48, 220, i*48);
    }
    for(int i = 0; i < theworld.getNumRobots(); i ++){
           if ( i == winner )
                painter->drawText(0, (i+1)*48 - 20, "Winner!");
            else if ( i == theworld.getLeader() )
                painter->drawText(0, (i+1)*48 -20, "Leader " + QString().sprintf("%d", i+1));
            else
                painter->drawText(0, (i+1)*48 - 20, QString().sprintf("%d", i+1));

    }


    //qDebug(QString().sprintf("here %d",winner).toStdString().c_str());
    /*
    if ( winner == -1){
        int leader = theworld.getLeader();
        painter->drawText(0, leader*48+30, "Leader" + QString().sprintf("%d", leader+1));
    }
    else{
        painter->drawText(0, winner*48 + 30, "Winner!");
    }*/
}

QRectF RobotRaceView::boundingRect() const
{
    return QRect(0, 0, 248, 48*10);
}
