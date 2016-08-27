#include "glwidget.h"
#include <QtSerialPort/QSerialPort>
#include <QPainter>
#include <QDebug>

glwidget::glwidget(renderarea* area,QWidget* parent )
    : QOpenGLWidget(parent),area(area)
{
    setFixedSize(MAX_WIDTH - GLmarginWIDTH, MAX_HEIGHT - GLmarginHEIGHT);
    setAutoFillBackground(false);
    //state = find_hashtag;
    new_y = 0;
    sending_y = 0;
    paintState = INITIALIZE;
    update();
}

void glwidget::animate(){
    char buffer[1];
    while(qobject_cast<QSerialPort*>(sender())->bytesAvailable()){
        QByteArray tmp = qobject_cast<QSerialPort*>(sender())->read(1);
        buffer[0] = tmp.at(0);
        if(buffer[0] == '#'){
            update();
            sending_y = new_y;
            new_y = 0;
            continue;
        }
        else
            new_y = new_y*10 + atoi(buffer);
    }
}

void glwidget::paintEvent(QPaintEvent *event){
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    if(paintState == INITIALIZE){
        area->init_area(&painter, event);
        paintState = false;
    }
    else
        area->paint(&painter, event,sending_y);
    painter.end();
}
