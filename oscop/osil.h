#ifndef OSIL_H
#define OSIL_H

#include "settingsdialog.h"
#include "glwidget.h"
#include <QtSerialPort/QSerialPort>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QComboBox>
#include <QTimer>
#include <QDial>
#include <QSlider>

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
    void request_data();
    void stop();
private:
    void ui_init();
    void connections_init();
    void closeSerialPort();

    QSerialPort *serial;
    QTimer *update_req;

    QPushButton *settings_button;
    QPushButton *close_button;
    QPushButton *connect_button;
    QPushButton *pause;
    QLabel *statusBar;
    QComboBox *ADC_sel;
    QDial *lvlSel;
    QSlider *offset;

    settingsdialog *settings;
    glwidget *openGl;

    int state;
};

#endif // OSIL_H
