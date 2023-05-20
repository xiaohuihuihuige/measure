#ifndef REFITEM_H
#define REFITEM_H

#include <QObject>
#include <QAbstractGraphicsShapeItem>
#include <QFont>

class RefItem : public QObject, public QAbstractGraphicsShapeItem
{
    Q_OBJECT
public:
    explicit RefItem(QObject *parent = nullptr);

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

class CenterLine : public RefItem
{
    Q_OBJECT
public:
    explicit CenterLine(QObject *parent = nullptr);


    virtual void paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget) override;
};


class RulerItem : public RefItem
{
    Q_OBJECT
public:
    explicit RulerItem(Qt::Orientations orientation, QObject *parent = nullptr);
    Qt::Orientations m_orientation;
    QFont m_font{"微软雅黑",18};

    virtual void paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                           QWidget *widget) override;
};


class SingleLongItem : public RefItem
{
    Q_OBJECT
public:
    explicit SingleLongItem(QObject *parent = nullptr);

    QPoint m_pos;
    QString m_text;
    QFont m_font{"微软雅黑",18};
    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;
    const QString &text() const;
    void setText(const QString &newText);
    QPoint pos() const;
    void setPos(QPoint newPos);

signals:
    void textChanged();
    void posChanged();

private:
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QPoint pos READ pos WRITE setPos NOTIFY posChanged)
};




#endif // REFITEM_H
