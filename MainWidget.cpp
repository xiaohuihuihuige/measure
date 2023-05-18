#include "MainWidget.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QButtonGroup>


MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    setupUI();
    setMouseTracking(true);
    initConnection();
}

void MainWidget::setupUI()
{
    this->resize(900,800);
    this->move(500,300);
//    this->showFullScreen();
    QHBoxLayout* hLayout = new QHBoxLayout();
    this->setLayout(hLayout);
    this->setWindowFlags(Qt::FramelessWindowHint);

    topwgt = new TopWidget();
    topwgt->setDisplayPos(DisplayPos_Top);
    topwgt->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    topwgt->setHideAuto(false);
    topwgt->setParentRect(this->frameGeometry());
    topwgt->show();

    rightwgt = new RightWidget();
    rightwgt->setDisplayPos(DisplayPos_Right);
    rightwgt->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    rightwgt->setHideAuto(false);
    rightwgt->setParentRect(this->frameGeometry());
    rightwgt->show();

    QButtonGroup* btngrp = new QButtonGroup();
    btngrp->addButton(topwgt->pbtnMouse);
    for(int i = 0; i < rightwgt->lstBtn.size(); ++i){
        btngrp->addButton(rightwgt->lstBtn.at(i));
    }


    //计算鼠标移动弹出的区域
    const short activeWidth = 10;
    topActiveRect = QRect(topwgt->pos().x(), this->y(), topwgt->width(), activeWidth);
    rightActiveRect = QRect(this->pos().x() + this->width() - activeWidth, rightwgt->pos().y(),activeWidth,rightwgt->height());
}

void MainWidget::initConnection()
{
    connect(topwgt, &TopWidget::sglCloseExe, this, [this](){
        close();
    });
}

void MainWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(topActiveRect.contains(event->globalPos())){
        topwgt->show();
    }

    if(rightActiveRect.contains(event->globalPos())){
        rightwgt->show();
    }

}
