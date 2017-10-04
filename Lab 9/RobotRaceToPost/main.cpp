#include "dialog.h"
#include <QApplication>
#include <Qt>
#include <QTime>

int main(int argc, char *argv[])
{
  qsrand(QTime().currentTime().elapsed());
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    
    return a.exec();
}
