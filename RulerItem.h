#ifndef RULERITEM_H
#define RULERITEM_H

#include <QObject>
#include <QAbstractGraphicsShapeItem>
#include <QFont>

class RulerItem : public QObject, public QAbstractGraphicsShapeItem
{
    Q_OBJECT
public:
    explicit RulerItem(Qt::Orientations orientation, QObject *parent = nullptr);

    int m_width;
    int m_height;


    int width() const;
    void setWidth(int newWidth);

    int height() const;
    void setHeight(int newHeight);

    virtual QRectF boundingRect() const override;

signals:

    void widthChanged();
    void heightChanged();

private:
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
};

#endif // RULERITEM_H
