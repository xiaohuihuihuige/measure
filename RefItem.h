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

class LineItem : public RefItem
{
    Q_OBJECT

public:
    explicit LineItem(QObject *parent = nullptr);
    enum LineType{
        LineType_Any = 0,
        LineType_Hor,
        LineType_Ver,
    };
    LineType m_lineType = LineType_Any;//1:任意线，2、水平线
    QFont m_font{"微软雅黑",12};
    double m_lineLength;
    bool m_showText = true;
    QPoint m_startPoint;
    QPoint m_endPoint;

    virtual void paint(QPainter *painter,
                           const QStyleOptionGraphicsItem *option,
                       QWidget *widget) override;

    LineType lineType() const;
    void setLineType(LineType newLineType);
    double lineLength() const;

    bool showText() const;
    void setShowText(bool newShowText);

    QPoint startPoint() const;
    void setStartPoint(QPoint newStartPoint);

    QPoint endPoint() const;
    void setEndPoint(QPoint newEndPoint);

        virtual QRectF boundingRect() const override;

signals:
    void lineTypeChanged();
    void lineLengthChanged();

    void showTextChanged();

    void startPointChanged();

    void endPointChanged();

private:
    Q_PROPERTY(LineType lineType READ lineType WRITE setLineType NOTIFY lineTypeChanged)
    Q_PROPERTY(double lineLength READ lineLength NOTIFY lineLengthChanged)
    Q_PROPERTY(bool showText READ showText WRITE setShowText NOTIFY showTextChanged)
    Q_PROPERTY(QPoint startPoint READ startPoint WRITE setStartPoint NOTIFY startPointChanged)
    Q_PROPERTY(QPoint endPoint READ endPoint WRITE setEndPoint NOTIFY endPointChanged)
};


#endif // REFITEM_H
