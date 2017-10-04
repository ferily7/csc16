#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "stack.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private slots:
    void on_inputLine_returnPressed();


private:
    void evaluate(QString input_symbol);
    Ui::Dialog *ui;
    Stack stack;
};

#endif // DIALOG_H
