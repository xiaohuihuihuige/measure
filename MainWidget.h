#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "TopWidget.h"
#include "RightWidget.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "RefItem.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    TopWidget* topwgt;
    RightWidget* rightwgt;
    QRect topActiveRect,rightActiveRect;

    QGraphicsView* m_view;
    RulerItem* m_rulerH;
    RulerItem* m_rulerV;
    CenterLine* m_centerLine;
    SingleLongItem* m_singleItem;
private:
    void setupUI();
    void initConnection();
    virtual void mouseMoveEvent(QMouseEvent *event) override;
signals:

};

#endif // MAINWIDGET_H
