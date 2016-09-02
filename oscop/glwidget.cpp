#include "glwidget.h"
#include <QByteArray>

glwidget::glwidget(QWidget* parent )
    : QOpenGLWidget(parent)
{
    oscop_data tmp;
    tmp.data = vector<int> (VECTOR_SIZE,0);
    tmp.index = 0;
    ADC = vector<oscop_data>(VECTOR_SIZE,tmp);
    Oscope_data = &ADC[0];
    area = new renderarea(Oscope_data);
    setFixedSize(MAX_WIDTH - GLmarginWIDTH, MAX_HEIGHT - GLmarginHEIGHT);
    setAutoFillBackground(false);
    new_y.clear();
    ADC_number = 0;
    counter = 1;
    paintState = INITIALIZE;
    update();
}

void glwidget::animate(){
    char buffer[1];
    while(qobject_cast<QSerialPort*>(sender())->bytesAvailable()){
        QByteArray tmp = qobject_cast<QSerialPort*>(sender())->read(1);
        buffer[0] = tmp.at(0);
        if(counter%4 == 0){
            new_y += buffer[0];
            if(ADC[ADC_number].index < VECTOR_SIZE){
                ADC[ADC_number].data[ADC[ADC_number].index] = cal_mean(new_y);
                ADC[ADC_number].index++;
            }
            else{
                ADC[ADC_number].index = 0;
                ADC[ADC_number].data[ADC[ADC_number].index] = cal_mean(new_y);
                ADC[ADC_number].index++;
            }
            new_y.clear();
            ADC_number++;
            counter++;
            continue;
        }
        else{
            new_y += buffer[0];
            counter++;
        }
        if(counter == 24){
            update();
            ADC_number = 0;
            counter = 0;
        }
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
        area->paint(&painter, event);
    painter.end();
}

void glwidget::change_ADC(int number){
    Oscope_data = &ADC[number];
}

int glwidget::cal_mean(QByteArray new_val){
    int mean=0;
    for(int i=1;i<5;i++){
        if(ADC[ADC_number].index - i< 0 )
            mean += ADC[ADC_number].data[ADC[ADC_number].index - i+VECTOR_SIZE];
        else
            mean += ADC[ADC_number].data[ADC[ADC_number].index - i];
    }
    mean += new_val.toHex().toInt();
    return mean/5;
}

void glwidget:: adjust_mag(int position){
    switch (position) {
    case 1:
        area->division_factor = 500;
        break;
    case 2:
        area->division_factor = 200;
        break;
    case 3:
        area->division_factor = 100;
        break;
    case 4:
        area->division_factor = 50;
        break;
    case 5:
        area->division_factor = 20;
        break;
    case 6:
        area->division_factor = 10;
        break;
    default:
        area->division_factor = 500;
        break;
    }
    update();
}

void glwidget::adjust_offset(int position){
    area->offset = MAX_HEIGHT - GLmarginHEIGHT - 20 - 10*position;
    update();
}


/*
void glwidget::animate(){
    char buffer[1];
    while(qobject_cast<QSerialPort*>(sender())->bytesAvailable()){
        QByteArray tmp = qobject_cast<QSerialPort*>(sender())->read(1);
        buffer[0] = tmp.at(0);
        if(buffer[0] == '#'){
            if(ADC[ADC_number].index < VECTOR_SIZE){
                ADC[ADC_number].data[ADC[ADC_number].index] = cal_mean(new_y);
                ADC[ADC_number].index++;
            }
            else{
                ADC[ADC_number].index = 0;
                ADC[ADC_number].data[ADC[ADC_number].index] = new_y;
            }
            new_y = 0;
            ADC_number++;
            continue;
        }
        else if(buffer[0] == '$'){
            update();
            ADC_number = 0;
        }
        else
            new_y = new_y*10 + atoi(buffer);
    }
}
*/
