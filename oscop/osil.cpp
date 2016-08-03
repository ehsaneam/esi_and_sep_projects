#include "osil.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>

osil::osil(QWidget *parent)
    : QWidget(parent)
{
    ui_init();
    setFixedSize(MAX_WIDTH,MAX_HEIGHT);
    setWindowTitle(tr("Oscilloscop"));
    QVBoxLayout* vbox = new QVBoxLayout();
    QHBoxLayout* buttonBox = new QHBoxLayout();
    vbox->addWidget(openGl);
    vbox->addWidget(statusBar);
    buttonBox->addWidget(settings_button);
    buttonBox->addWidget(connect_button);
    buttonBox->addWidget(close_button);
    vbox->addLayout(buttonBox);
    setLayout(vbox);
    connections_init();
    state = DISCONNECTED;
}

osil::~osil(){
}

void osil::openSerialPort()
{
    settingsdialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
            statusBar->setText(tr("Connected to %1 : %2, %3, %4, %5, %6")
                                       .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                       .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
            state = CONNECTED;
            connect(serial, SIGNAL(readyRead()), openGl, SLOT(animate()));
            connect_button->setEnabled(false);
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());
        statusBar->setText(tr("Open error"));
    }
}

void osil::ui_init(){
    serial = new QSerialPort(this);
    openGl = new glwidget(&area,this);
    settings_button = new QPushButton("Settings");
    statusBar = new QLabel("");
    close_button = new QPushButton("close");
    connect_button = new QPushButton("connect");
    settings = new settingsdialog;
}

void osil::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void osil::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
    connect_button->setEnabled(true);
}

void osil::connections_init(){
    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this,
            SLOT(handleError(QSerialPort::SerialPortError)));
    connect(close_button,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(settings_button,SIGNAL(clicked(bool)),settings,SLOT(show()));
    connect(connect_button,SIGNAL(clicked(bool)),this,SLOT(openSerialPort()));
    if(state == CONNECTED)
        connect(serial, SIGNAL(readyRead()), openGl, SLOT(animate()));
}
