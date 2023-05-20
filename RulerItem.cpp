#include "RulerItem.h"
#include <QPainter>

RulerItem::RulerItem(Qt::Orientations orientation, QObject *parent)
    : QObject{parent},
      m_orientation(orientation)
{
    m_orientation == Qt::Horizontal ? m_height = 100 : m_width = 100;
}

int RulerItem::height() const
{
    return m_height;
}

void RulerItem::setHeight(int newHeight)
{
    if (m_height == newHeight)
        return;
    m_height = newHeight;
    emit heightChanged();
    update();

}

QRectF RulerItem::boundingRect() const
{
    return QRectF(this->pos().x(),this->pos().y(),m_width,m_height);
}

int RulerItem::width() const
{
    return m_width;
}

void RulerItem::setWidth(int newWidth)
{
    if (m_width == newWidth)
        return;
    m_width = newWidth;
    emit widthChanged();
    update();
}
void RulerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->setFont(m_font);
    QRectF rect = this->boundingRect();
    auto length = (m_orientation == Qt::Horizontal ? this->boundingRect().width() : this->boundingRect().height());
    qDebug() << m_orientation;
    if(m_orientation == Qt::Horizontal)
    {
        auto height = rect.height();
        auto shortLine_y = height * 0.2;
        auto longLine_y = height * 0.3;
        auto halfHeight = height * 0.4;
        int temp = 0;
        for(int i = 0;i < length;i+=10)
        {
            //画长刻度、中刻度、短刻度
            if(temp % 10 == 0) {
                painter->drawLine(QPointF(i,0),QPointF(i,halfHeight));
                painter->drawText(QRectF(i-50,halfHeight,100,20),Qt::AlignCenter | Qt::TextWordWrap,QString::number(i));
            }
            else if(temp % 5 == 0) {
                painter->drawLine(QPointF(i,0),QPointF(i,longLine_y));
            }
            else {
                painter->drawLine(QPointF(i,0),QPointF(i,shortLine_y));
            }
            ++temp;
        }
    }
    else
    {
        auto width = rect.width();
        auto shortLineWidth = width * 0.25;
        auto longLineWidth = width * 0.5;
        auto middleLineWidth = width * 0.375;
        auto harfWidth = width / 2;
        int temp = 0;
        for(int i = 0;i < length;i+=10)
        {
            if(temp % 10 == 0)//画长线
            {
                painter->drawLine(QPointF(longLineWidth,i),QPointF(0,i));
                painter->drawText(QRectF(harfWidth,i-50,harfWidth,100),Qt::AlignCenter | Qt::TextWordWrap,QString::number(i));

            }
            else if(temp % 5 == 0)
            {
                painter->drawLine(QPointF(middleLineWidth,i),QPointF(0,i));
            }
            else
            {
                painter->drawLine(QPointF(shortLineWidth,i),QPointF(0,i));
            }
            ++temp;
        }
    }
}
