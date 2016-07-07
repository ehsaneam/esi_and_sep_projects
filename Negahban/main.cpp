#include "esia.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    esia w;
    w.show();

    return a.exec();
}
