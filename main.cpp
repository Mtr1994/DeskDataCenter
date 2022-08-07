#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qApp->setStyleSheet("file:///:/Resource/qss/style.qss");

    MainWindow w;
    w.show();

    return a.exec();
}
