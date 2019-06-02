#include "mainwindow.h"
#include <QApplication>
#include <QMainWindow>
#include <QFont>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont f("微软雅黑", 10);
    a.setFont(f);

    QFile qss(":/qss/style.qss");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();

    MainWindow w;
    w.show();

    return a.exec();
}
