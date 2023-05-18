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

    QPushButton* pbtnRightAngleRule = new QPushButton();
    pbtnRightAngleRule->setCheckable(true);
    pbtnRightAngleRule->setMinimumSize(50,50);
    pbtnRightAngleRule->setIcon(QIcon(":/icons/resource/RightAngleRuler.png"));
    pbtnRightAngleRule->setIconSize(QSize(50,50));
    layout->addWidget(pbtnRightAngleRule);

    QPushButton* pbtnadd = new QPushButton();
    pbtnadd->setCheckable(true);
    pbtnadd->setMinimumSize(50,50);
    pbtnadd->setIcon(QIcon(":/icons/resource/add.png"));
    pbtnadd->setIconSize(QSize(50,50));
    layout->addWidget(pbtnadd);

    QPushButton* pbtnrule = new QPushButton();
    pbtnrule->setCheckable(true);
    pbtnrule->setMinimumSize(50,50);
    pbtnrule->setIcon(QIcon(":/icons/resource/ruleicon.png"));
    pbtnrule->setIconSize(QSize(50,50));
    layout->addWidget(pbtnrule);

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

}
