#include "MainWidget.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QButtonGroup>
#include <QGraphicsProxyWidget>

MainWidget::MainWidget(QWidget *parent) : QGraphicsView(parent)
{
    setupUI();
    setMouseTracking(true);
    initConnection();
}

void MainWidget::setupUI()
{
    this->resize(1200,700);
    this->move(200,50);
    this->showFullScreen();
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setDragMode(QGraphicsView::RubberBandDrag);

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

    btngrp = new QButtonGroup();
    for(int i = 0; i < rightwgt->lstBtn.size(); ++i){
        btngrp->addButton(rightwgt->lstBtn.at(i),i);
    }
    btngrp->addButton(topwgt->pbtnMouse,20);


    //计算鼠标移动弹出的区域
    const short activeWidth = 10;
    topActiveRect = QRect(topwgt->pos().x(), this->y(), topwgt->width(), activeWidth);
    rightActiveRect = QRect(this->pos().x() + this->width() - activeWidth, rightwgt->pos().y(),activeWidth,rightwgt->height());


    QGraphicsScene* scene = new QGraphicsScene;
    scene->setSceneRect(0,0, this->width(), this->height());
    this->setScene(scene);


    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_rulerH = new RulerItem(Qt::Horizontal);
    m_rulerH->setWidth(this->width()-5);
    m_rulerH->setHeight(100);
    scene->addItem(m_rulerH);

    m_rulerV = new RulerItem(Qt::Vertical);
    m_rulerV->setWidth(100);
    m_rulerV->setHeight(this->height());
    scene->addItem(m_rulerV);

    m_centerLine = new CenterLine;
    m_centerLine->setWidth(scene->width());
    m_centerLine->setHeight(scene->height());
    scene->addItem(m_centerLine);

    m_singleItem = new SingleLongItem;
    m_singleItem->setWidth(100);
    m_singleItem->setHeight(60);
    m_singleItem->setText("100pixel");
    m_singleItem->setPos(QPoint(100,900));

    scene->addItem(m_singleItem);

}

void MainWidget::initConnection()
{
    connect(topwgt, &TopWidget::sglCloseExe, this, [this](){
        close();
    });
    connect(topwgt,&TopWidget::sglCenterChecked,this, [this](bool checked){
        m_centerLine->setVisible(checked);
    });
    connect(topwgt,&TopWidget::sglRightAngleRulerChecked,this, [this](bool checked){
        m_rulerV->setVisible(checked);
        m_rulerH->setVisible(checked);
    });
    connect(topwgt,&TopWidget::sglSingleRunlerChecked,this, [this](bool checked){
        m_singleItem->setVisible(checked);
    });
    connect(btngrp,&QButtonGroup::idClicked,this,[this](int id){
        switch(id){
        case 20:
            m_drawType = 0;
            break;
        default:
            m_drawType = 1;
        break;

        }
    });

}

void MainWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(m_drawType == 1){
        if(m_drawEnable){
            LineItem* item =dynamic_cast<LineItem*>(m_lstItem.at(m_lstItem.size() - 1));
            item->setEndPoint(event->pos());
            this->scene()->update();
        }
    }
    if(topActiveRect.contains(event->globalPos())){
        topwgt->show();
    }

    if(rightActiveRect.contains(event->globalPos())){
        rightwgt->show();
    }

}



void MainWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        if(m_drawType == 1 ){
            m_clickNum++;
            if(m_clickNum == 1){
                m_drawEnable = true;
                LineItem* line = new LineItem;
                m_lstItem << line;
                line->setLineType(LineItem::LineType_Any);
                line->setShowText(true);
                line->setStartPoint(event->pos());
                line->setAcceptHoverEvents(true);
                line->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
                this->scene()->addItem(line);
            } else if(m_clickNum == 2){
                if(m_drawEnable){
                    LineItem* item =dynamic_cast<LineItem*>(m_lstItem.at(m_lstItem.size() - 1));
                    item->setEndPoint(event->pos());
                    m_drawEnable = false;
                    m_clickNum = 0;
                    this->scene()->update();
                }
            }
        }


    }
}

void MainWidget::mouseReleaseEvent(QMouseEvent *event)
{

}
