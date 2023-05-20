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
    QPushButton* pbtnSingleRuler;
    QPushButton* pbtnCenter;
    QPushButton* pbtnRightAngleRuler;
private:
    void setupUI();
    void initConnection();
signals:
    void sglCloseExe();
    void sglSingleRunlerChecked(bool);
    void sglCenterChecked(bool);
    void sglRightAngleRulerChecked(bool);
};

#endif // TOPWIDGET_H
