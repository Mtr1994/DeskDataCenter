#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qt_windows.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setCurrentIndex(PAGE_HOME);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
    this->resize(qRound(GetSystemMetrics(SM_CXSCREEN) * 0.6), qRound(GetSystemMetrics(SM_CYSCREEN) * 0.7));
    decorateUi();
    initModel();
    ui->tableUser->setModel(&mModelUsers);
    initTable();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->pos().x() > ui->widgetMenu->width())
    {
        return;
    }
    if (event->button() == Qt::LeftButton)
    {
        last_mouse_position_ = event->globalPos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->pos().x() > ui->widgetMenu->width())
    {
        return;
    }
    if (!event->buttons().testFlag(Qt::LeftButton))
    {
            return;
    }
    const QPoint position = pos() + event->globalPos() - last_mouse_position_; //the position of mainfrmae + (current_mouse_position - last_mouse_position)
    move(position.x(), position.y());
    last_mouse_position_ = event->globalPos();
}

void MainWindow::decorateUi()
{
    QWidget *widget1 = new QWidget(ui->statusBar);
    widget1->setFixedWidth(145);
    widget1->setFixedHeight(12);
    widget1->setStyleSheet("background-color: #273d55");
}

void MainWindow::showToast(const QString &pMsg)
{
    DialogToast *aToast = new DialogToast(ui->tabWidget);
    aToast->showMessage(pMsg);
}

void MainWindow::initModel()
{
    mModelUsers.setHorizontalHeaderItem(0, new QStandardItem("姓名"));
    mModelUsers.setHorizontalHeaderItem(1, new QStandardItem("手机"));
    mModelUsers.setHorizontalHeaderItem(2, new QStandardItem("计划"));
    mModelUsers.setHorizontalHeaderItem(3, new QStandardItem("状态"));
    mModelUsers.setHorizontalHeaderItem(4, new QStandardItem("操作"));

    ui->tableUser->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
}

void MainWindow::initTable()
{
    for (int i = 0; i < 5; i++)
    {
        mModelUsers.setItem(i, 0, new QStandardItem("邹小珊"));
        mModelUsers.setItem(i, 1, new QStandardItem("18040571676"));
        mModelUsers.setItem(i, 2, new QStandardItem("周期计划"));
        mModelUsers.setItem(i, 3, new QStandardItem("启用"));
        QPushButton *item = new QPushButton;
        item->setText("编辑");
        item->setStyleSheet("QPushButton {font: 12px;border-radius: 1ex; background-color: #fc9153;color: #fefefe;max-width: 48px;margin: 4px 0px 4px 4px;}");
        ui->tableUser->setIndexWidget(mModelUsers.index(i, 4), item);
    }
}

void MainWindow::on_btnExit_clicked()
{
    // 清理程序并退出
    exit(0);
}

void MainWindow::on_btnLog_clicked()
{
    if (ui->tabWidget->currentIndex() == PAGE_LOG)
    {
        return;
    }
    ui->tabWidget->setCurrentIndex(PAGE_LOG);
    ui->lbTitle->setText("运行日志");
    ui->editLog->clearFocus();
}

void MainWindow::on_btnHHome_clicked()
{
    ui->tabWidget->setCurrentIndex(PAGE_HOME);
}

void MainWindow::on_tableUser_clicked(const QModelIndex &index)
{
    if (index.column() == 4)
    {
        qDebug() << "点击：菜单";
    }
    else {
        qDebug() << "ignore";
    }
}
