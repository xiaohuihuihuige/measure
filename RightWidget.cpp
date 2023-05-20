#include "RightWidget.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QTabWidget>
#include <QGroupBox>
#include <QComboBox>
#include <QTableWidget>
#include <QHeaderView>

RightWidget::RightWidget(QWidget *parent) : FloatWidget(parent)
{
    setupUI();
    initConnection();
}

void RightWidget::setupUI()
{
    QVBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);
    //添加控制页面固定控件
    {
        QHBoxLayout* hLayout = new QHBoxLayout();
        layout->addLayout(hLayout);

        pbtnFixed = new QPushButton();
        pbtnFixed->setCheckable(true);
        pbtnFixed->setChecked(true);
        pbtnFixed->setMinimumSize(15,15);
        hLayout->addWidget(pbtnFixed);

        QPushButton* pbtnKnow = new QPushButton();
        pbtnKnow->setMinimumSize(15,15);
        hLayout->addWidget(pbtnKnow);

        hLayout->addStretch();
    }

    {
        QTabWidget* tabwgt = new QTabWidget();
        layout->addWidget(tabwgt);
        {
            QWidget* wgt = new QWidget();
            tabwgt->addTab(wgt,"");
            tabwgt->setTabIcon(0,QIcon(":/icons/resource/Caliper.png"));
            tabwgt->setIconSize(QSize(40,40));

            QVBoxLayout* vLayout = new QVBoxLayout();
            wgt->setLayout(vLayout);
            //添加标定内的控件
            {
                QGroupBox* grpbox = new QGroupBox("Scale");
                QHBoxLayout* hLayout = new QHBoxLayout();
                grpbox->setLayout(hLayout);
                vLayout->addWidget(grpbox);

                QPushButton* pbtnNew = new QPushButton("New");
                hLayout->addWidget(pbtnNew);

                QComboBox* cbbox = new QComboBox();
                hLayout->addWidget(cbbox);

                QComboBox* cbboxDanwei = new QComboBox();
                cbboxDanwei->addItems(QStringList() << "pixel" << "mm");
                hLayout->addWidget(cbboxDanwei);
            }
            //添加绘图按钮
            {
                QGroupBox* grpbox1 = new QGroupBox("measure tool");
                QGridLayout* gLayout = new QGridLayout();
                grpbox1->setLayout(gLayout);
                vLayout->addWidget(grpbox1);
                for(int i = 0; i < 16; ++i){
                    QPushButton* pbtn1 = new QPushButton();
                    pbtn1->setCheckable(true);
                    pbtn1->setMinimumSize(40,40);
                    pbtn1->setIcon(QIcon(QString(":/icons/resource/%1.png").arg(i)));
                    pbtn1->setIconSize(QSize(40,40));
                    gLayout->addWidget(pbtn1, i / 4, i % 4);
                    lstBtn << pbtn1;
                }
            }
            //田间assist tool内的控件
            {
                QGroupBox* grpbox2 = new QGroupBox("assist tool");
                QHBoxLayout* hLayout1 = new QHBoxLayout();
                grpbox2->setLayout(hLayout1);
                vLayout->addWidget(grpbox2);

                QPushButton* btn = new QPushButton("save");
                QPushButton* btn1 = new QPushButton("load");
                QPushButton* btn2 = new QPushButton();
                QPushButton* btn3 = new QPushButton();

                btn->setMaximumSize(40,40);
                btn1->setMaximumSize(40,40);
                btn2->setMaximumSize(40,40);
                btn3->setMaximumSize(40,40);

                hLayout1->addWidget(btn);
                hLayout1->addWidget(btn1);
                hLayout1->addWidget(btn2);
                hLayout1->addWidget(btn3);

                QComboBox* box = new QComboBox();
                box->setMinimumWidth(40);
                hLayout1->addWidget(box);
            }
            //添加表格
            {
                QTableWidget* tblwgt = new QTableWidget();
                vLayout->addWidget(tblwgt);
                tblwgt->setMinimumSize(200,400);
                tblwgt->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
                QStringList lisHeader = QStringList() << "show" << "item" << "info";
                for(int i = 0; i < lisHeader.size(); ++i){
                    tblwgt->insertColumn(i);
                }
                tblwgt->setHorizontalHeaderLabels(lisHeader);
            }
        }
    }
    layout->addStretch();
    this->setWindowFlag(Qt::FramelessWindowHint);
}


void RightWidget::initConnection()
{
    //固定还是隐藏按钮槽
    connect(pbtnFixed, &QPushButton::clicked, this, [this](){
        setHideAuto(!m_bHideAuto);
        if(m_bHideAuto){
           pbtnFixed->setChecked(false);
        } else {
            pbtnFixed->setChecked(true);
        }
    });

}
