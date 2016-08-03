#include "glwidget.h"
#include <QtSerialPort/QSerialPort>
#include <QPainter>
#include <QDebug>

glwidget::glwidget(renderarea* area,QWidget* parent )
    : QOpenGLWidget(parent),area(area)
{
    setFixedSize(MAX_WIDTH - GLmarginWIDTH, MAX_HEIGHT - GLmarginHEIGHT);
    setAutoFillBackground(false);
    state = find_space;
    new_y = 0;
    paintState = INITIALIZE;
    update();
}

void glwidget::animate(){
    char buffer[1];
    QByteArray tmp = qobject_cast<QSerialPort*>(sender())->read(1);
    if(buffer[0] != ' ')
        if(atoi(buffer)>10 || atoi(buffer)<0 )
            return;
    buffer[0] = tmp.at(0);
    switch(state){
    case find_space:
        if(buffer[0] == ' ')
            state = get_first_val;
        break;
    case get_first_val:
        if(buffer[0] == ' ')
            state = get_first_val;
        else{
            new_y = atoi(buffer);
            state = get_sec_val;
        }
        break;
    case get_sec_val:
        if(buffer[0] == ' '){
            update();
            new_y = 0;
            state = get_first_val;
        }
        else{
            new_y = new_y*10 + atoi(buffer);;
            state = get_trd_val;
        }
        break;
    case get_trd_val:
        if(buffer[0] == ' '){
            update();
            new_y = 0;
            state = get_first_val;
        }
        else{
            new_y = new_y*10 + atoi(buffer);;
            update();
            state = find_space;
        }
        break;
    default:
        return;
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
        area->paint(&painter, event,new_y);
    painter.end();
}
