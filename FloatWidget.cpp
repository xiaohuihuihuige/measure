#include "FloatWidget.h"
#include <QGuiApplication>
#include <QDebug>
#include <QScreen>

FloatWidget::FloatWidget(QWidget *parent)
    : QWidget{parent}
{
    //获取主屏分辨率
    QRect mRect;
    mRect = QGuiApplication::primaryScreen()->geometry();
    this->setMouseTracking(true);
    this->setStyleSheet("QWidget{background-color:#111111;"
                        "color:white;"
                        "border-width:1px;"
                        "border-color:white;}"
                        "QPushButton{background-color:#333333;}"
                        "QPushButton::checked{background-color:#999999;}"
                        "QPushButton::hover{background-color:#666666;}"
                        "QTabBar::tab{background-color:#444444;}"
                        "QTabWidget QWidget{background-color:#444444;}"
                        "QComboBox{background-color:#333333;}"
                        "QHeaderView::section{background-color:#333333;}");
}

void FloatWidget::setParentRect(QRect rect)
{
    m_rectParent = rect;
}

void FloatWidget::setDisplayPos(DisplayPos pos)
{
    m_pos = pos;
    calLeftTopPos();
    move(m_iLeftTopPosX, m_iLeftTopPosY);
}

void FloatWidget::calLeftTopPos()
{
    const short space = 10;
    switch(m_pos){
    case DisplayPos_Top:
        m_iLeftTopPosX = m_rectParent.x() + m_rectParent.width() / 2 - m_iWidgetWidth / 2;
        m_iLeftTopPosY = m_rectParent.y() + space;
    break;
    case DisplayPos_Left:
        m_iLeftTopPosX = m_rectParent.x() + space;
        m_iLeftTopPosY = m_rectParent.y() + m_rectParent.height() / 2 - m_iWidgetHeight / 2;
    break;
    case DisplayPos_Bottom:
        m_iLeftTopPosX = m_rectParent.x() + m_rectParent.width() / 2 - m_iWidgetWidth / 2;
        m_iLeftTopPosY = m_rectParent.y() + m_rectParent.height() - m_iWidgetHeight - space;
    break;
    case DisplayPos_Right:
        m_iLeftTopPosX = m_rectParent.x() + m_rectParent.width() - m_iWidgetWidth - space;
        m_iLeftTopPosY = m_rectParent.y() + m_rectParent.height() / 2 - m_iWidgetHeight / 2;
    break;
    default:
        break;
    }
}

void FloatWidget::setHideAuto(bool active)
{
    m_bHideAuto = active;
}

void FloatWidget::showEvent(QShowEvent *event)
{
    calLeftTopPos();
    move(m_iLeftTopPosX, m_iLeftTopPosY);

}

void FloatWidget::leaveEvent(QEvent *event)
{
    if(m_bHideAuto){
        this->hide();
    }
}
void FloatWidget::resizeEvent(QResizeEvent *event)
{
    m_iWidgetWidth = this->width();
    m_iWidgetHeight = this->height();
}



