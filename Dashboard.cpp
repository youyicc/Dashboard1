#include "Dashboard.h"

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
{
    setFixedSize(640,480);

    //背景设置成黑色
    QPalette bgpal=palette();
    bgpal.setColor(QPalette::Background,QColor(0,0,0));
    setPalette (bgpal);
}

Dashboard::~Dashboard(){}

void Dashboard::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    int width=this->width();
    int height=this->height();
    int radius=((width>height)?height:width)/2;
    //将画笔移动到中下方
    painter.translate(width>>1,height*0.6);
    //启用反锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);
    //取消画笔
    painter.setPen(Qt::NoPen);
    //设置画刷颜色
    painter.setBrush(QColor(98,246,255));
    //绘制13个小点
    DrawPoint(painter,radius);
    //绘制内测数字
    DrawDigital(painter,radius-10);
    //绘制渐变圆环
    DrawCircle(painter,radius-35);
    //绘制小刻度
    DrawSmallScale(painter,radius-60);
    //绘制大刻度
    DrawBigScale(painter,radius-75);
    //绘制文字
    DrawText(painter,radius/2);
    //绘制指针
    DrawPointer(painter,radius-100);
}

void Dashboard::DrawPoint(QPainter& painter,int radius)
{
    //组装点的路径图
    QPainterPath pointPath;
    pointPath.moveTo(-2,-2);
    pointPath.lineTo(2,-2);
    pointPath.lineTo(2,2);
    pointPath.lineTo(0,4);
    pointPath.lineTo(-2,2);
    //绘制13个小点
    for(int i=0;i<13;++i){
        QPointF point(0,0);
        painter.save();
        //计算并移动绘图对象中心点
        point.setX(radius*qCos(((210-i*20)*M_PI)/180));
        point.setY(radius*qSin(((210-i*20)*M_PI)/180));
        //计算并移动绘图对象的中心点
        painter.translate(point.x(),-point.y());
        //计算并选择绘图对象坐标
        painter.rotate(-120+i*20);
        //绘制路径
        painter.drawPath(pointPath);
        painter.restore();
    }
}

void Dashboard::DrawDigital(QPainter& painter,int radius)
{
    //设置画笔
    painter.setPen(QColor(98,246,255));
    //设置字体
    QFont font;
    font.setFamily("SimHei");
    font.setPointSize(16);
    painter.setFont(font);
    //绘制13个小点
    for(int i=0;i<13;++i){
        QPointF point(0,0);
        painter.save();
        //计算并移动绘图对象中心点
        point.setX(radius*qCos(((210-i*20)*M_PI)/180));
        point.setY(radius*qSin(((210-i*20)*M_PI)/180));
        //计算并移动绘图对象的中心点
        painter.translate(point.x(),-point.y());
        //计算并选择绘图对象坐标
        painter.rotate(-120+i*20);
        //绘制路径
        painter.drawText(-15, 0, 30, 20,Qt::AlignCenter,QString::number(i*20));
        painter.restore();
    }
    //去掉画笔
    painter.setPen(Qt::NoPen);
}

void Dashboard::DrawCircle(QPainter& painter,int radius)
{
    //保存绘图对象
    painter.save();
    //计算大小圆路径
    QPainterPath outRing;
    QPainterPath inRing;
    outRing.moveTo(0,0);
    inRing.moveTo(0,0);
    outRing.arcTo(-radius,-radius, 2*radius,2*radius,-31,242);
    inRing.addEllipse(-radius+20,-radius+20,2*(radius-20),2*(radius-20));
    outRing.closeSubpath();
    //设置渐变色
    QRadialGradient radialGradient(0,0,radius,0,0);
    radialGradient.setColorAt(0.95,QColor(98,246,255));
    radialGradient.setColorAt(1,QColor(0,0,0));
    //设置渐变画刷
    painter.setBrush(radialGradient);
    //大圆减去小圆得到圆环
    painter.drawPath(outRing.subtracted(inRing));
    //恢复绘图对象
    painter.restore();
}

void Dashboard::DrawSmallScale(QPainter& painter,int radius)
{
    //组装点的路径图
    QPainterPath pointPath;
    pointPath.moveTo(-2,-2);
    pointPath.lineTo(-1,-4);
    pointPath.lineTo(1,-4);
    pointPath.lineTo(2,-2);
    pointPath.lineTo(1,8);
    pointPath.lineTo(-1,8);
    //绘制121个小点
    for(int i=0;i<121;++i){
        QPointF point(0,0);
        painter.save();
        //计算并移动绘图对象中心点
        point.setX(radius*qCos(((210-i*2)*M_PI)/180));
        point.setY(radius*qSin(((210-i*2)*M_PI)/180));
        //计算并移动绘图对象的中心点
        painter.translate(point.x(),-point.y());
        //计算并选择绘图对象坐标
        painter.rotate(-120+i*2);
        //绘制路径
        painter.drawPath(pointPath);
        painter.restore();
    }
}

void Dashboard::DrawBigScale(QPainter& painter,int radius)
{
    //组装点的路径图
    QPainterPath pointPath1;
    pointPath1.moveTo(-2,-2);
    pointPath1.lineTo(-1,-4);
    pointPath1.lineTo(1,-4);
    pointPath1.lineTo(2,-2);
    pointPath1.lineTo(1,8);
    pointPath1.lineTo(-1,8);
    QPainterPath pointPath2;
    pointPath2.moveTo(-2,-2);
    pointPath2.lineTo(-1,-4);
    pointPath2.lineTo(1,-4);
    pointPath2.lineTo(2,-2);
    pointPath2.lineTo(1,15);
    pointPath2.lineTo(-1,15);
    //绘制25个刻度
    for(int i=0;i<25;++i){
        QPointF point(0,0);
        painter.save();
        //计算并移动绘图对象中心点
        point.setX(radius*qCos(((210-i*10)*M_PI)/180));
        point.setY(radius*qSin(((210-i*10)*M_PI)/180));
        //计算并移动绘图对象的中心点
        painter.translate(point.x(),-point.y());
        //计算并选择绘图对象坐标
        painter.rotate(-120+i*10);
        //绘制路径
        if(i%2){
            painter.drawPath(pointPath1);
        }
        else{
            painter.drawPath(pointPath2);
        }
        painter.restore();
    }
}

void Dashboard::DrawText(QPainter& painter,int radius)
{
    painter.save();
    //设置画笔
    painter.setPen(QColor(98,246,255));
    //设置字体
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(16);
    painter.setFont(font);
    painter.drawText(-25, -radius, 50, 20,Qt::AlignCenter,QString("km/h"));
    painter.restore();
}

void Dashboard::DrawPointer(QPainter& painter,int radius)
{
    //组装点的路径图
    QPainterPath pointPath;
    pointPath.moveTo(10,0);
    pointPath.lineTo(1,-radius);
    pointPath.lineTo(-1,-radius);
    pointPath.lineTo(-10,0);
    pointPath.arcTo(-10,0,20,20,180,180);
    QPainterPath inRing;
    inRing.addEllipse(-5,-5,10,10);
    painter.save();
    //计算并选择绘图对象坐标
    painter.rotate(-120);
    //设置画刷
    painter.setBrush(QColor(255,0,0,150));
    //绘制路径
    painter.drawPath(pointPath.subtracted(inRing));
    painter.restore();
}
