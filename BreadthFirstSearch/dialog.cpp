#include "dialog.h"
#include "ui_dialog.h"
#include "location.h"
#include "mazemodel.h"
#include "mazeview.h"
#include "queue.h"
#include <QTimer>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QGraphicsScene * scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    model = new MazeModel;
    MazeView  * view = new MazeView(model);
    scene->addItem(view);
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
    //timer->start(1000);
    //timer->start(1);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    model->initSearch();
    timer->start(ui->delay->text().toInt());
}
