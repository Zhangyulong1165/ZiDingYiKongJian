#ifndef LINELOADING_H
#define LINELOADING_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QMap>
#include <QColor>
#include <QPoint>

class LineLoading : public QWidget
{
    Q_OBJECT
public:
    explicit LineLoading(QWidget *parent = nullptr);
    void setDotCount(int);              //设置圆点个数
    void setDotColor(const QColor&);    //设置点颜色
    void setMaxDiameter(float);         //设置圆点最大直径
    void setMinDiameter(float);         //设置圆点最小直径
    void start();   //开始
    void pause();   //停止
protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
public slots:
    void refresh();
private:
    int _index;                 //刷新计数
    QColor _dotColor;           //点的颜色
    int _count;                 //点的个数
    float _minDiameter;         //圆点小直径
    float _maxDiameter;         //圆点大直径
    int _interval;              //时间间隔 单位：毫秒(ms)
    QTimer timer;               //定时器
    QList<float> radiiList;     //直径列表
    QList<QPoint> locationList; //圆点坐标列表
    void caculate();            //计算
};
#endif // LINELOADING_H
