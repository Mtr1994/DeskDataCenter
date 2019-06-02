#ifndef DIALOGTOAST_H
#define DIALOGTOAST_H

#include <QWidget>
#include <QLabel>

enum {
    MSG_ERROR = 0,
    MSG_CORRECT
};

class DialogToast : public QWidget
{
    Q_OBJECT
public:
    explicit DialogToast(QWidget *parent = nullptr);

    void showMessage(const QString& pMsg, int pType = MSG_ERROR);

private:
    void paintEvent(QPaintEvent *event);

private:
    QLabel mLbMsg;
    QLabel mLbImg;
};

#endif // DIALOGTOAST_H
