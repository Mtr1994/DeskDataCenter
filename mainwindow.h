#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabBar>
#include <QMouseEvent>
#include <QPoint>
#include <QStringList>
#include <QThread>
#include <QFileDialog>
#include "dialogtoast.h"
#include <QStyledItemDelegate>
#include <QtMath>
#include <QStandardItemModel>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

enum enumTabPage {
    PAGE_HOME = 0,
    PAGE_LOG,
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnLog_clicked();

    void on_btnExit_clicked() __attribute__ ((noreturn));

    void on_btnHHome_clicked();

    void on_tableUser_clicked(const QModelIndex &index);

private:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    void decorateUi();

    // 提示
    void showToast(const QString& pMsg);
    void initModel();
    void initTable();

private:
    Ui::MainWindow *ui;
    QPoint last_mouse_position_;
    QString mMobile;
    QString mPassword;
    QThread mThread;
    QStandardItemModel mModelUsers;
};

#endif // MAINWINDOW_H
