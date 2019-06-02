#include "dialogtoast.h"
#include <QLabel>
#include <QTimer>
#include <QPainter>

DialogToast::DialogToast(QWidget *parent) : QWidget(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    this->setFixedSize(195, 76);

    mLbImg.setGeometry(22, 22, 32, 32);
    mLbMsg.setGeometry(76, 0, this->width() - 76, 76);
    mLbMsg.setStyleSheet("color: #fefefe; font-family: '微软雅黑'; font-size: 14px");
    mLbImg.setParent(this);
    mLbMsg.setParent(this);

    this->move(parent->width() / 2 - this->width() / 2, parent->height() / 3 - this->height() / 2);
}

void DialogToast::showMessage(const QString &pMsg, int pType)
{
    mLbMsg.setText(pMsg);
    QTimer::singleShot(3000, this, SLOT(deleteLater()));
    if (pType == MSG_ERROR)
    {
        mLbImg.setStyleSheet("image: url(:/icon/error.png);");
    }
    else
    {
        mLbImg.setStyleSheet("image: url(:/icon/correct.png);");
    }
    this->show();
}

void DialogToast::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(QBrush(QColor(0, 0, 0, 160)));
    p.setRenderHint(QPainter::Antialiasing);
    p.drawRoundedRect(0, 0, width() - 1, height() - 1, 12, 12);
}
