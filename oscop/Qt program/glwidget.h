#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "renderarea.h"
#include <QOpenGLWidget>
#include <QtSerialPort/QSerialPort>
#include <QPainter>
#include <vector>

#define INITIALIZE true

class glwidget:public QOpenGLWidget
{
    Q_OBJECT
public:
    glwidget(QWidget* parent );
    oscop_data *Oscope_data;
    vector<oscop_data> ADC;
public slots:
    void animate();
    void change_ADC(int number);
    void adjust_mag(int position);
    void adjust_offset(int position);
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    int cal_mean(QByteArray new_val);
    QByteArray new_y;
    renderarea* area;
    int state;
    bool paintState;
    int ADC_number;
    int counter;
};

#endif // GLWIDGET_H
