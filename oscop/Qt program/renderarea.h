#ifndef RENDERAREA_H
#define RENDERAREA_H

#define MAX_WIDTH 1370
#define MAX_HEIGHT 700
#define GLmarginWIDTH 100
#define GLmarginHEIGHT 150
#define VECTOR_SIZE (MAX_WIDTH-GLmarginWIDTH)/5

#include <oscop_data.h>
#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include <vector>
#include <cstdlib>
#include <QPainter>
#include <QPaintEvent>
#include <QVector>
#include <QDebug>

using namespace std;

class renderarea
{
public:
    renderarea(oscop_data* &Data);
    void paint(QPainter *painter, QPaintEvent *event );
    void init_area(QPainter *painter, QPaintEvent *event);
    int division_factor;
    int offset;
private:
    QBrush background;
    QBrush circleBrush;
    oscop_data* data;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
    int index;
    QVector<int> y;
};

#endif // RENDERAREA_H
