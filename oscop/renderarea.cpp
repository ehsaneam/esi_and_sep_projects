#include "renderarea.h"
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QVector>

renderarea::renderarea()
{
    background = QBrush(QColor(64, 32, 64));
    circlePen = QPen(Qt::white);
    circlePen.setWidth(1);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(20);
    y = QVector<int>(VECTOR_SIZE,0);
    index = 0;
}

void renderarea::paint(QPainter *painter,QPaintEvent* event , int y_new){
    y[index] = y_new;
    QRect a(index*5,event->rect().top(),5,event->rect().height());
    painter->fillRect(a,background);
    painter->save();
    painter->setPen(circlePen);
    if(index!=0)
        painter->drawLine(5*(index-1),440 - ((400*y[index-1])/4095) , 5*index , 440 - ((400*y[index])/4095));
    painter->restore();
    index++;
    if(index>=VECTOR_SIZE)
        index = 0;
}

void renderarea::init_area(QPainter *painter, QPaintEvent *event){
    painter->fillRect(event->rect(), background);
    painter->save();
    painter->setPen(circlePen);
    for(int i=0 ; i < VECTOR_SIZE ; i++){
        if(i==0)
            painter->drawPoint(5*i, 440 - ((400*y[i])/255) );
        else
            painter->drawLine(5*(i-1),440 - ((400*y[i-1])/255) , 5*i , 440 - ((400*y[i])/255));
    }
    painter->restore();
}
