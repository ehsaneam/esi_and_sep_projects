#ifndef OSIL_H
#define OSIL_H

#include "renderarea.h"
#include "settingsdialog.h"
#include "glwidget.h"
#include <QtSerialPort/QSerialPort>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

#define CONNECTED 1
#define DISCONNECTED 0

class osil : public QWidget
{
    Q_OBJECT

public:
    osil(QWidget *parent = 0);
    ~osil();
private slots:
    void handleError(QSerialPort::SerialPortError error);
    void openSerialPort();
private:
    void ui_init();
    void connections_init();
    void closeSerialPort();
    renderarea area;
    QSerialPort *serial;
    QPushButton *settings_button;
    QPushButton *close_button;
    QPushButton *connect_button;
    QLabel *statusBar;
    settingsdialog *settings;
    glwidget *openGl;
    int state;
};

#endif // OSIL_H
