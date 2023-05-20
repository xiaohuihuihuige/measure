#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "TopWidget.h"
#include "RightWidget.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "RefItem.h"

class MainWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    TopWidget* topwgt;
    RightWidget* rightwgt;
    QRect topActiveRect,rightActiveRect;

    RulerItem* m_rulerH;
    RulerItem* m_rulerV;
    CenterLine* m_centerLine;
    SingleLongItem* m_singleItem;

    QButtonGroup* btngrp;
    int m_drawType = 0;
    bool m_drawEnable = false;
    QList<RefItem*> m_lstItem;
    int m_clickNum = 0;
private:
    void setupUI();
    void initConnection();
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event)override;
    virtual void mouseReleaseEvent(QMouseEvent *event)override;
signals:

};

#endif // MAINWIDGET_H
