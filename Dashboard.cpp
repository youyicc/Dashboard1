#include "Dashboard.h"

Dashboard::Dashboard(QWidget *parent)
    : QDialog(parent)
{
    setFixedSize(640,480);

    //�������óɺ�ɫ
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
    //�������ƶ������·�
    painter.translate(width>>1,height*0.6);
    //���÷����
    painter.setRenderHint(QPainter::Antialiasing, true);
    //ȡ������
    painter.setPen(Qt::NoPen);
    //���û�ˢ��ɫ
    painter.setBrush(QColor(98,246,255));
    //����13��С��
    DrawPoint(painter,radius);
    //�����ڲ�����
    DrawDigital(painter,radius-10);
    //���ƽ���Բ��
    DrawCircle(painter,radius-35);
    //����С�̶�
    DrawSmallScale(painter,radius-60);
    //���ƴ�̶�
    DrawBigScale(painter,radius-75);
    //��������
    DrawText(painter,radius/2);
    //����ָ��
    DrawPointer(painter,radius-100);
}

void Dashboard::DrawPoint(QPainter& painter,int radius)
{
    //��װ���·��ͼ
    QPainterPath pointPath;
    pointPath.moveTo(-2,-2);
    pointPath.lineTo(2,-2);
    pointPath.lineTo(2,2);
    pointPath.lineTo(0,4);
    pointPath.lineTo(-2,2);
    //����13��С��
    for(int i=0;i<13;++i){
        QPointF point(0,0);
        painter.save();
        //���㲢�ƶ���ͼ�������ĵ�
        point.setX(radius*qCos(((210-i*20)*M_PI)/180));
        point.setY(radius*qSin(((210-i*20)*M_PI)/180));
        //���㲢�ƶ���ͼ��������ĵ�
        painter.translate(point.x(),-point.y());
        //���㲢ѡ���ͼ��������
        painter.rotate(-120+i*20);
        //����·��
        painter.drawPath(pointPath);
        painter.restore();
    }
}

void Dashboard::DrawDigital(QPainter& painter,int radius)
{
    //���û���
    painter.setPen(QColor(98,246,255));
    //��������
    QFont font;
    font.setFamily("SimHei");
    font.setPointSize(16);
    painter.setFont(font);
    //����13��С��
    for(int i=0;i<13;++i){
        QPointF point(0,0);
        painter.save();
        //���㲢�ƶ���ͼ�������ĵ�
        point.setX(radius*qCos(((210-i*20)*M_PI)/180));
        point.setY(radius*qSin(((210-i*20)*M_PI)/180));
        //���㲢�ƶ���ͼ��������ĵ�
        painter.translate(point.x(),-point.y());
        //���㲢ѡ���ͼ��������
        painter.rotate(-120+i*20);
        //����·��
        painter.drawText(-15, 0, 30, 20,Qt::AlignCenter,QString::number(i*20));
        painter.restore();
    }
    //ȥ������
    painter.setPen(Qt::NoPen);
}

void Dashboard::DrawCircle(QPainter& painter,int radius)
{
    //�����ͼ����
    painter.save();
    //�����СԲ·��
    QPainterPath outRing;
    QPainterPath inRing;
    outRing.moveTo(0,0);
    inRing.moveTo(0,0);
    outRing.arcTo(-radius,-radius, 2*radius,2*radius,-31,242);
    inRing.addEllipse(-radius+20,-radius+20,2*(radius-20),2*(radius-20));
    outRing.closeSubpath();
    //���ý���ɫ
    QRadialGradient radialGradient(0,0,radius,0,0);
    radialGradient.setColorAt(0.95,QColor(98,246,255));
    radialGradient.setColorAt(1,QColor(0,0,0));
    //���ý��仭ˢ
    painter.setBrush(radialGradient);
    //��Բ��ȥСԲ�õ�Բ��
    painter.drawPath(outRing.subtracted(inRing));
    //�ָ���ͼ����
    painter.restore();
}

void Dashboard::DrawSmallScale(QPainter& painter,int radius)
{
    //��װ���·��ͼ
    QPainterPath pointPath;
    pointPath.moveTo(-2,-2);
    pointPath.lineTo(-1,-4);
    pointPath.lineTo(1,-4);
    pointPath.lineTo(2,-2);
    pointPath.lineTo(1,8);
    pointPath.lineTo(-1,8);
    //����121��С��
    for(int i=0;i<121;++i){
        QPointF point(0,0);
        painter.save();
        //���㲢�ƶ���ͼ�������ĵ�
        point.setX(radius*qCos(((210-i*2)*M_PI)/180));
        point.setY(radius*qSin(((210-i*2)*M_PI)/180));
        //���㲢�ƶ���ͼ��������ĵ�
        painter.translate(point.x(),-point.y());
        //���㲢ѡ���ͼ��������
        painter.rotate(-120+i*2);
        //����·��
        painter.drawPath(pointPath);
        painter.restore();
    }
}

void Dashboard::DrawBigScale(QPainter& painter,int radius)
{
    //��װ���·��ͼ
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
    //����25���̶�
    for(int i=0;i<25;++i){
        QPointF point(0,0);
        painter.save();
        //���㲢�ƶ���ͼ�������ĵ�
        point.setX(radius*qCos(((210-i*10)*M_PI)/180));
        point.setY(radius*qSin(((210-i*10)*M_PI)/180));
        //���㲢�ƶ���ͼ��������ĵ�
        painter.translate(point.x(),-point.y());
        //���㲢ѡ���ͼ��������
        painter.rotate(-120+i*10);
        //����·��
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
    //���û���
    painter.setPen(QColor(98,246,255));
    //��������
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(16);
    painter.setFont(font);
    painter.drawText(-25, -radius, 50, 20,Qt::AlignCenter,QString("km/h"));
    painter.restore();
}

void Dashboard::DrawPointer(QPainter& painter,int radius)
{
    //��װ���·��ͼ
    QPainterPath pointPath;
    pointPath.moveTo(10,0);
    pointPath.lineTo(1,-radius);
    pointPath.lineTo(-1,-radius);
    pointPath.lineTo(-10,0);
    pointPath.arcTo(-10,0,20,20,180,180);
    QPainterPath inRing;
    inRing.addEllipse(-5,-5,10,10);
    painter.save();
    //���㲢ѡ���ͼ��������
    painter.rotate(-120);
    //���û�ˢ
    painter.setBrush(QColor(255,0,0,150));
    //����·��
    painter.drawPath(pointPath.subtracted(inRing));
    painter.restore();
}
