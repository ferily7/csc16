#include "dialog.h"
#include "ui_dialog.h"

void Dialog::evaluate(QString input_symbol){

    //Complete this function.
    /* Postfix evaluation algorithm.
     * Perform the following action on the given
     * input_symbol: */

    double x, y, ans;

    if(input_symbol == "+"){
        y = stack.pop();
        x = stack.pop();
        ans = x + y;
        stack.push(ans);
    }
    else if(input_symbol == "-"){
        y = stack.pop();
        x = stack.pop();
        ans = x - y;
        stack.push(ans);
    }
    else if(input_symbol == "*"){
        y = stack.pop();
        x = stack.pop();
        ans = x * y;
        stack.push(ans);
    }
    else if(input_symbol == "/"){
        y = stack.pop();
        x = stack.pop();
        ans = x / y;
        stack.push(ans);
    }
    else{
        stack.push(input_symbol.toDouble());
    }
}

/* Don't mess the functions below this line.*/

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog(){
    delete ui;
}

void Dialog::on_inputLine_returnPressed(){
    QString input = ui->inputLine->text();
    ui->outputText->append("Input: " + input);
    evaluate(input);
    ui->inputLine->setText("");
    ui->inputLine->setFocus();
    double temp = stack.pop();
    ui->outputText->append("Stack top: " + QString::number(temp));
    stack.push(temp);
}



