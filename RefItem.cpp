#include "RefItem.h"
#include <QPainter>

RefItem::RefItem(QObject *parent)
    : QObject{parent}
{

}
int RefItem::height() const
{
    return m_height;
}

void RefItem::setHeight(int newHeight)
{
    if (m_height == newHeight)
        return;
    m_height = newHeight;
    emit heightChanged();
    update();
}

int RefItem::width() const
{
    return m_width;
}

void RefItem::setWidth(int newWidth)
{
    if (m_width == newWidth)
        return;
    m_width = newWidth;
    emit widthChanged();
    update();
}
QRectF RefItem::boundingRect() const
{
    return QRectF(this->pos().x(),this->pos().y(),m_width,m_height);
//    return this->sceneBoundingRect();
}

//画十字线
CenterLine::CenterLine(QObject *parent)
    : RefItem{parent}
{

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

//画标尺
RulerItem::RulerItem(Qt::Orientations orientation, QObject *parent)
    : RefItem{parent},
      m_orientation(orientation)
{
    m_orientation == Qt::Horizontal ? m_height = 100 : m_width = 100;
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

//单位长度刻度
SingleLongItem::SingleLongItem(QObject *parent)
{

}

QRectF SingleLongItem::boundingRect() const
{
    return QRectF(m_pos.x(),m_pos.y(),m_width,m_height);
}

QPoint SingleLongItem::pos() const
{
    return m_pos;
}

void SingleLongItem::setPos(QPoint newPos)
{
    if (m_pos == newPos)
        return;
    m_pos = newPos;
    emit posChanged();
}

const QString &SingleLongItem::text() const
{
    return m_text;
}

void SingleLongItem::setText(const QString &newText)
{
    if (m_text == newText)
        return;
    m_text = newText;
    emit textChanged();
    update();
}

void SingleLongItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->setFont(m_font);
    QRectF rect = this->boundingRect();
    int height1 = rect.height() * 0.3;
    int height2 = rect.height() * 0.6;
    //画标尺
    painter->drawLine(QPointF(rect.x(),rect.y() + height1),QPointF(rect.x(),rect.y() + rect.height()));
    painter->drawLine(QPointF(rect.x() + rect.width(),rect.y() + height1),QPointF(rect.x() + rect.width(), rect.y() + rect.height()));
    painter->drawLine(QPointF(rect.x(),rect.y() + height2),QPointF(rect.x()+rect.width(),rect.y() + height2));
    //文字
    painter->drawText(QRectF(rect.x(),rect.y(),rect.width(),height2-10),Qt::AlignCenter | Qt::TextWordWrap, m_text);
}

LineItem::LineItem(QObject *parent)
{

}

QPoint LineItem::endPoint() const
{
    return m_endPoint;
}

void LineItem::setEndPoint(QPoint newEndPoint)
{
    m_endPoint = newEndPoint;
    emit endPointChanged();
    update();
}

QRectF LineItem::boundingRect() const
{
//    return this->sceneBoundingRect();
    float x = std::min(m_startPoint.x() - 20,m_endPoint.x() - 20);
    float y = std::min(m_startPoint.y() - 20,m_endPoint.y() - 20);
    float width = abs(m_startPoint.x() - m_endPoint.x()) + 250;
    float height = abs(m_startPoint.y() - m_endPoint.y()) + 40;

    return QRectF(x,y,width,height);


}

QPoint LineItem::startPoint() const
{
    return m_startPoint;
}

void LineItem::setStartPoint(QPoint newStartPoint)
{
    if (m_startPoint == newStartPoint)
        return;
    m_startPoint = newStartPoint;
    m_endPoint = m_startPoint;
    emit startPointChanged();
    update();
}

bool LineItem::showText() const
{
    return m_showText;
}

void LineItem::setShowText(bool newShowText)
{
    if (m_showText == newShowText)
        return;
    m_showText = newShowText;
    emit showTextChanged();
}

void LineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->setFont(m_font);
    //画端点
    painter->drawEllipse(m_startPoint,5,5);
    painter->drawEllipse(m_endPoint,5,5);
    //画线
    painter->drawLine(m_startPoint,m_endPoint);
//    //文字
    if(m_showText){
        QString str = "distance:" + QString::number(QLineF(m_startPoint,m_endPoint).length(),'f', 3);
        QRectF ret = QRectF(m_startPoint.x(),m_startPoint.y()-20,200,20);
        painter->drawText(ret,Qt::AlignCenter | Qt::TextWordWrap, str);
        painter->drawRoundedRect(ret,5,5);
    }
}

double LineItem::lineLength() const
{
    return m_lineLength;
}


LineItem::LineType LineItem::lineType() const
{
    return m_lineType;
}

void LineItem::setLineType(LineType newLineType)
{
    if (m_lineType == newLineType)
        return;
    m_lineType = newLineType;
    emit lineTypeChanged();
}

