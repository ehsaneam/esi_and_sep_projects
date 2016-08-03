#ifndef RENDERAREA_H
#define RENDERAREA_H

#define MAX_WIDTH 1370
#define MAX_HEIGHT 700
#define GLmarginWIDTH 30
#define GLmarginHEIGHT 100
#define VECTOR_SIZE (MAX_WIDTH-GLmarginWIDTH)/5

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include <vector>
#include <cstdlib>

using namespace std;

class renderarea
{
public:
    renderarea();
    void paint(QPainter *painter, QPaintEvent *event , int y_new);
    void init_area(QPainter *painter, QPaintEvent *event);
private:
    QBrush background;
    QBrush circleBrush;
    QFont textFont;
    QPen circlePen;
    QPen textPen;
    int index;
    QVector<int> y;
};

#endif // RENDERAREA_H
