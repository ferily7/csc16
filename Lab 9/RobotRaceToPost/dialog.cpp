#include "dialog.h"
#include "ui_dialog.h"
#include "robotrace.h"
#include "robotraceview.h"
#include <QTimer>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    RobotRace * race = new RobotRace(10);
    RobotRaceView  * view = new RobotRaceView(*race);
    scene->addItem(view);
    QTimer * timer = new QTimer;
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    timer->start(100);
}

Dialog::~Dialog()
{
    delete ui;
}
