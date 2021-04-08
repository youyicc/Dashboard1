#include "Dashboard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dashboard mainWidget;
    mainWidget.show();
    return a.exec();
}
