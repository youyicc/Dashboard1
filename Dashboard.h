#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDebug>

#include <QtMath>
#include <QDialog>
#include <QPainter>
#include <QPaintEvent>
#include <QPainterPath>
#include <QRadialGradient>

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

protected:
    void paintEvent(QPaintEvent*);

private:
    void DrawPoint(QPainter&,int);
    void DrawDigital(QPainter&,int);
    void DrawCircle(QPainter&,int);
    void DrawSmallScale(QPainter&,int);
    void DrawBigScale(QPainter&,int);
    void DrawText(QPainter&,int);
    void DrawPointer(QPainter&,int);
};
#endif
