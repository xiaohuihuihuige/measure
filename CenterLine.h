#ifndef CENTERLINE_H
#define CENTERLINE_H

#include <QObject>
#include <QAbstractGraphicsShapeItem>

class CenterLine : public QObject, public QAbstractGraphicsShapeItem
{
    Q_OBJECT
public:
    explicit CenterLine(QObject *parent = nullptr);

    int m_width;
    int m_height;

    virtual QRectF boundingRect() const override;

    virtual void paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget) override;

    int width() const;
    void setWidth(int newWidth);

    int height() const;
    void setHeight(int newHeight);

signals:



    void widthChanged();
    void heightChanged();

private:
    Q_PROPERTY(int width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(int height READ height WRITE setHeight NOTIFY heightChanged)
};

#endif // CENTERLINE_H
