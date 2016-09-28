#include "renderarea.h"

renderarea::renderarea(oscop_data* &Data)
{
    data = Data;
    background = QBrush(QColor(64, 32, 64));
    circlePen = QPen(Qt::white);
    circlePen.setWidth(1);
    textPen = QPen(Qt::white);
    textFont.setPixelSize(20);
    y = QVector<int>(VECTOR_SIZE,0);
    division_factor = 1;
    offset = MAX_HEIGHT - GLmarginHEIGHT - 20;
}

void renderarea::paint(QPainter *painter,QPaintEvent* event){
    QRect a(event->rect().left(),event->rect().top(),event->rect().width(),event->rect().height());
    QBrush red(QColor(255,0,0));
    QPen redPen(Qt::red);
    QPen bluePen(Qt::blue);
    painter->fillRect(a,background);
    painter->save();
    painter->setPen(bluePen);
    for(int i=100;i<event->rect().width() ; i+=100)
        painter->drawLine(i,event->rect().top(),i,event->rect().bottom());
    for(int i=100;i<event->rect().height() ; i+= 100)
        painter->drawLine(event->rect().left(),i,event->rect().right(),i);
    painter->setPen(circlePen);
    for(int i=0 ; i<VECTOR_SIZE ; i++){
        if(i == data->index)
            painter->drawLine(5*(i-1),offset - ((300* data->data[i-1])/4095) , 5*i , offset - ((300*data->data[i-1])/4095));
        else if(i!=0)
            painter->drawLine(5*(i-1),offset - ((300* data->data[i-1])/4095) , 5*i , offset - ((300*data->data[i])/4095));
    }
    painter->setPen(redPen);
    painter->drawText(event->rect().left(),event->rect().top(),42,20,0,QString::number(data->data[data->index - 1] * 3.1 / 4095.));
    painter->drawText(event->rect().left(),event->rect().bottom()-20,142,20,0,"VoltSel : " + QString::number(division_factor));
    painter->setBrush(red);
    painter->drawEllipse(5*(data->index-1),440 - ((400*data->data[data->index-1])/4095), 5 , 5);
    painter->restore();
}

void renderarea::init_area(QPainter *painter, QPaintEvent *event){
    QPen redPen(Qt::red);
    painter->fillRect(event->rect(), background);
    painter->save();
    for(int i=100;i<event->rect().width() ; i+=100)
        painter->drawLine(i,event->rect().top(),i,event->rect().bottom());
    for(int i=100;i<event->rect().height() ; i+= 100)
        painter->drawLine(event->rect().left(),i,event->rect().right(),i);
    painter->setPen(circlePen);
    for(int i=0 ; i<VECTOR_SIZE ; i++){
        if(i == data->index)
            painter->drawLine(5*(i-1),offset - ((300* data->data[i-1])/4095) , 5*i , offset - ((300*data->data[i-1])/4095));
        else if(i!=0)
            painter->drawLine(5*(i-1),offset - ((300* data->data[i-1])/4095) , 5*i , offset - ((300*data->data[i])/4095));
    }
    painter->setPen(redPen);
    painter->drawText(event->rect().left(),event->rect().top(),42,20,0,QString::number(1024 * 3.1 / 4095.));
    painter->restore();
}
