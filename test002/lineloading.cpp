#include "lineLoading.h"
#include "qmath.h"
#include <QDebug>

LineLoading::LineLoading(QWidget *parent) : QWidget(parent),
    _maxDiameter(18),
    _minDiameter(15),
    _interval(200),
    _index(0),
    _count(4),
    _dotColor(QColor(36, 167, 255))
{
    //设置背景透明
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    connect(&timer,&QTimer::timeout,this,&LineLoading::refresh);
}


void LineLoading::setDotCount(int count)    //设置点的个数
{
    _count=count;
}


void LineLoading::setDotColor(const QColor & color) //设置点的颜色
{
    _dotColor=color;
}


void LineLoading::start()   //开始动画
{
    timer.setInterval(_interval);
    timer.start();
}

void LineLoading::pause()   //开始动画
{
    timer.stop();
}

void LineLoading::setMaxDiameter(float max)     //设置大圆直径
{
    _maxDiameter=max;
}

void LineLoading::setMinDiameter(float min)     //设置小圆直径
{
    _minDiameter=min;
}

void LineLoading::refresh() //刷新界面
{
    repaint();
}

void LineLoading::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    caculate();
}

void LineLoading::caculate()
{
    locationList.clear();
    radiiList.clear();
    int width = this->width()/_count;
    for(int i=0;i<_count;i++)
    {
        if(i == 0)
            radiiList<<_maxDiameter;
        else
            radiiList<<_minDiameter;
        locationList.append(QPoint((i + 0.5)*width ,this->height()/2));
    }
}

void LineLoading::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(_dotColor);
    painter.setBrush(_dotColor);
    for(int i=0;i<_count;i++)
    {
        painter.setPen(_dotColor);
        float radii=radiiList.at((_index+_count-i)%_count); //半径
        painter.drawEllipse(QPointF(locationList.at(i).x(),locationList.at(i).y()),radii,radii);  //绘制圆点
    }
    _index++;
}

