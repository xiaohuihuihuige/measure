#include "TopWidget.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QIcon>

TopWidget::TopWidget(QWidget *parent)
    : FloatWidget{parent}
{
    setupUI();
    initConnection();
}

void TopWidget::setupUI()
{
    QHBoxLayout* layout = new QHBoxLayout();
    this->setLayout(layout);

    pbtnFixed = new QPushButton();
    pbtnFixed->setCheckable(true);
    pbtnFixed->setChecked(true);
    pbtnFixed->setMinimumSize(50,50);
    pbtnFixed->setIcon(QIcon(":/icons/resource/lock.png"));
    pbtnFixed->setIconSize(QSize(50,50));
    layout->addWidget(pbtnFixed);

    pbtnMouse = new QPushButton();
    pbtnMouse->setMinimumSize(50,50);
    pbtnMouse->setCheckable(true);
    pbtnMouse->setIcon(QIcon(":/icons/resource/mouse.png"));
    pbtnMouse->setIconSize(QSize(50,50));
    layout->addWidget(pbtnMouse);

    QPushButton* pbtnRun = new QPushButton();
    pbtnRun->setCheckable(true);
    pbtnRun->setMinimumSize(50,50);
    pbtnRun->setIcon(QIcon(":/icons/resource/run.png"));
    pbtnRun->setIconSize(QSize(50,50));
    layout->addWidget(pbtnRun);

    QPushButton* pbtnAE = new QPushButton();
    pbtnAE->setCheckable(true);
    pbtnAE->setMinimumSize(50,50);
    pbtnAE->setIcon(QIcon(":/icons/resource/ae.png"));
    pbtnAE->setIconSize(QSize(50,50));
    layout->addWidget(pbtnAE);

    QPushButton* pbtnlr = new QPushButton();
    pbtnlr->setCheckable(true);
    pbtnlr->setMinimumSize(50,50);
    pbtnlr->setIcon(QIcon(":/icons/resource/leftright.png"));
    pbtnlr->setIconSize(QSize(50,50));
    layout->addWidget(pbtnlr);

    QPushButton* pbtnud = new QPushButton();
    pbtnud->setCheckable(true);
    pbtnud->setMinimumSize(50,50);
    pbtnud->setIcon(QIcon(":/icons/resource/updown.png"));
    pbtnud->setIconSize(QSize(50,50));
    layout->addWidget(pbtnud);

    pbtnRightAngleRuler = new QPushButton();
    pbtnRightAngleRuler->setCheckable(true);
    pbtnRightAngleRuler->setChecked(true);
    pbtnRightAngleRuler->setMinimumSize(50,50);
    pbtnRightAngleRuler->setIcon(QIcon(":/icons/resource/RightAngleRuler.png"));
    pbtnRightAngleRuler->setIconSize(QSize(50,50));
    layout->addWidget(pbtnRightAngleRuler);

    pbtnCenter = new QPushButton();
    pbtnCenter->setCheckable(true);
    pbtnCenter->setChecked(true);
    pbtnCenter->setMinimumSize(50,50);
    pbtnCenter->setIcon(QIcon(":/icons/resource/add.png"));
    pbtnCenter->setIconSize(QSize(50,50));
    layout->addWidget(pbtnCenter);

    pbtnSingleRuler = new QPushButton();
    pbtnSingleRuler->setCheckable(true);
    pbtnSingleRuler->setChecked(true);
    pbtnSingleRuler->setMinimumSize(50,50);
    pbtnSingleRuler->setIcon(QIcon(":/icons/resource/ruleicon.png"));
    pbtnSingleRuler->setIconSize(QSize(50,50));
    layout->addWidget(pbtnSingleRuler);

    pbtnClose = new QPushButton();
    pbtnClose->setMinimumSize(50,50);
    pbtnClose->setIcon(QIcon(":/icons/resource/close.png"));
    pbtnClose->setIconSize(QSize(50,50));
    layout->addWidget(pbtnClose);

    layout->addStretch();
    this->setWindowFlag(Qt::FramelessWindowHint);
}

void TopWidget::initConnection()
{
    connect(pbtnFixed, &QPushButton::clicked, this, [this](){
        setHideAuto(!m_bHideAuto);
        if(m_bHideAuto){
           pbtnFixed->setChecked(false);
        } else {
            pbtnFixed->setChecked(true);
        }
    });
    connect(pbtnClose, &QPushButton::clicked, this, [this](){
        emit sglCloseExe();
    });
    connect(pbtnSingleRuler, &QPushButton::clicked, this, [this](bool checked){
        emit sglSingleRunlerChecked(checked);
    });
    connect(pbtnCenter, &QPushButton::clicked, this, [this](bool checked){
        emit sglCenterChecked(checked);
    });
    connect(pbtnRightAngleRuler, &QPushButton::clicked, this, [this](bool checked){
        emit sglRightAngleRulerChecked(checked);
    });

}
