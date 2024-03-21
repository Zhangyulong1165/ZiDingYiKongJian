#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "wbswitchbutton.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->widget->start();
    ui->widget_2->getSwsitch();
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        ui->widget_2->setSwitch(1);
        qDebug()<<ui->widget_2->getEnabled();
        qDebug()<<ui->widget_2->getSwsitch();
    });
    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){
        ui->widget_2->setSwitch(1);
    });
    connect(ui->widget_2,&WBSwitchButton::sigSwitchChanged,this,[=](bool onOroff){
        qDebug()<<onOroff;
    });
}

Widget::~Widget()
{
    delete ui;
}

