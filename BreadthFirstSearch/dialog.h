#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "mazemodel.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    MazeModel * model;
    QTimer * timer;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
