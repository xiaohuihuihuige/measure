#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "TopWidget.h"
#include "RightWidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    TopWidget* topwgt;
    RightWidget* rightwgt;
    QRect topActiveRect,rightActiveRect;


private:
    void setupUI();
    void initConnection();
    virtual void mouseMoveEvent(QMouseEvent *event) override;
signals:

};

#endif // MAINWIDGET_H
