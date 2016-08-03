#include "osil.h"
#include <QApplication>
#include <QSurfaceFormat>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat fmt;
    fmt.setSamples(4);
    QSurfaceFormat::setDefaultFormat(fmt);

    osil w;
    w.show();

    return a.exec();
}
