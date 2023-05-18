#ifndef TOPWIDGET_H
#define TOPWIDGET_H

#include <QWidget>
#include "FloatWidget.h"
#include <QPushButton>

class TopWidget : public FloatWidget
{
    Q_OBJECT
public:
    explicit TopWidget(QWidget *parent = nullptr);
    QPushButton* pbtnFixed;
    QPushButton* pbtnClose;
    QPushButton* pbtnMouse;
private:
    void setupUI();
    void initConnection();
signals:
    void sglCloseExe();
};

#endif // TOPWIDGET_H
