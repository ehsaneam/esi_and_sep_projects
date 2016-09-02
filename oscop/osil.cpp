#include "osil.h"

osil::osil(QWidget *parent)
    : QWidget(parent)
{
    ui_init();
    setFixedSize(MAX_WIDTH,MAX_HEIGHT);
    setWindowTitle(tr("Oscilloscop"));
    QVBoxLayout* vbox = new QVBoxLayout();
    QHBoxLayout* buttonBox = new QHBoxLayout();
    QHBoxLayout* oscop_layout = new QHBoxLayout();
    QLabel* channel_sel = new QLabel("Channel : ");
    channel_sel->setMaximumSize(100,30);
    QLabel* Amplitude_sel = new QLabel("VOL. : ");
    Amplitude_sel->setMaximumSize(100,30);
    oscop_layout->addWidget(openGl);
    oscop_layout->addWidget(offset);
    vbox->addLayout(oscop_layout);
    vbox->addWidget(statusBar);
    buttonBox->addWidget(Amplitude_sel);
    buttonBox->addWidget(lvlSel);
    buttonBox->addWidget(channel_sel);
    buttonBox->addWidget(ADC_sel);
    buttonBox->addSpacing(450);
    buttonBox->addWidget(pause);
    buttonBox->addWidget(settings_button);
    buttonBox->addWidget(connect_button);
    buttonBox->addWidget(close_button);
    vbox->addLayout(buttonBox);
    setLayout(vbox);
    update_req = new QTimer();
    update_req->start(20);
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
    openGl = new glwidget(this);
    pause = new QPushButton("pause");
    pause->setMaximumSize(100,30);
    settings_button = new QPushButton("Settings");
    settings_button->setMaximumSize(100,30);
    statusBar = new QLabel("");
    close_button = new QPushButton("close");
    close_button->setMaximumSize(100,30);
    connect_button = new QPushButton("connect");
    connect_button->setMaximumSize(100,30);
    ADC_sel = new QComboBox();
    ADC_sel->addItem("ADC1");
    ADC_sel->addItem("ADC2");
    ADC_sel->addItem("ADC3");
    ADC_sel->addItem("ADC4");
    ADC_sel->addItem("ADC5");
    ADC_sel->addItem("ADC6");
    ADC_sel->setMaximumSize(80,30);
    lvlSel = new QDial();
    lvlSel->setNotchesVisible(true);
    lvlSel->setRange(1,6);
    lvlSel->setMaximumSize(50,50);
    offset = new QSlider(Qt::Vertical);
    offset->setRange(0,50);
    offset->setFixedSize(70,MAX_HEIGHT-GLmarginHEIGHT);
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
    connect(ADC_sel,SIGNAL(currentIndexChanged(int)),openGl,SLOT(change_ADC(int)));
    connect(update_req,SIGNAL(timeout()),this,SLOT(request_data()));
    connect(lvlSel,SIGNAL(sliderMoved(int)),openGl,SLOT(adjust_mag(int)));
    connect(pause,SIGNAL(clicked(bool)),this,SLOT(stop()));
    connect(offset,SIGNAL(sliderMoved(int)),openGl,SLOT(adjust_offset(int)));
}

void osil::request_data(){
    if(serial->isOpen())
        serial->write("1");
}

void osil::stop(){
    pause->setText("run");
}
