#include "CenterLine.h"
#include <QPainter>

CenterLine::CenterLine(QObject *parent)
    : QObject{parent}
{

}

int CenterLine::height() const
{
    return m_height;
}

void CenterLine::setHeight(int newHeight)
{
    if (m_height == newHeight)
        return;
    m_height = newHeight;
    emit heightChanged();
    update();
}

int CenterLine::width() const
{
    return m_width;
}

void CenterLine::setWidth(int newWidth)
{
    if (m_width == newWidth)
        return;
    m_width = newWidth;
    emit widthChanged();
    update();
}
QRectF CenterLine::boundingRect() const
{
    return QRectF(this->pos().x(),this->pos().y(),m_width,m_height);
//    return this->sceneBoundingRect();
}
void CenterLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    QRectF rect = this->boundingRect();
    painter->drawLine(QPointF(rect.x() + rect.width()/2,0),QPointF(rect.x() + rect.width()/2,rect.height()));
    painter->drawLine(QPointF(0,rect.y() + rect.height()/2),QPointF(rect.width(),rect.y() + rect.height()/2));

}
