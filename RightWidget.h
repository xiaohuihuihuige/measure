#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <QWidget>
#include "FloatWidget.h"
#include <QPushButton>

class RightWidget : public FloatWidget
{
    Q_OBJECT
public:
    explicit RightWidget(QWidget *parent = nullptr);

    QPushButton* pbtnFixed;
    QList<QPushButton*> lstBtn;

private:
    void setupUI();
    void initConnection();
signals:

};

#endif // RIGHTWIDGET_H
