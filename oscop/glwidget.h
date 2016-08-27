#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "renderarea.h"
#include <QOpenGLWidget>

#define find_hashtag 0
#define get_first_val 1
#define get_sec_val 2
#define get_trd_val 3

#define INITIALIZE true

class glwidget:public QOpenGLWidget
{
    Q_OBJECT
public:
    glwidget(renderarea* area,QWidget* parent );
public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    int new_y,sending_y;
    renderarea* area;
    int state;
    bool paintState;
};

#endif // GLWIDGET_H
