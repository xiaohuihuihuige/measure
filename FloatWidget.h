#ifndef FLOATWIDGET_H
#define FLOATWIDGET_H

#include <QWidget>
#include <QMouseEvent>

enum DisplayPos{
    DisplayPos_Top = 0,
    DisplayPos_Left,
    DisplayPos_Bottom,
    DisplayPos_Right,
};

class FloatWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FloatWidget(QWidget *parent = nullptr);
    //设置停放的位置
    DisplayPos m_pos = DisplayPos_Right;
    QRect m_rectParent;
    short m_iWidgetWidth = 400;
    short m_iWidgetHeight = 400;
    short m_iLeftTopPosX = 10;
    short m_iLeftTopPosY = 10;
    bool m_bHideAuto = false;
public:
    virtual void setParentRect(QRect rect);
    virtual void setDisplayPos(DisplayPos pos = DisplayPos_Top);
    virtual void calLeftTopPos();
    virtual void setHideAuto(bool active);
    virtual void showEvent(QShowEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;



signals:

};

#endif // FLOATWIDGET_H
