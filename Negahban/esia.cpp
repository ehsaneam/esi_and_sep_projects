#include <QtWidgets>
#include <QtNetwork>
#include <qdebug.h>
#include "esia.h"

esia::esia(QWidget *parent)
    : QMainWindow(parent)
{
    state = NOT_CONNECTED;
    serverStatusLabel = new QLabel(tr("Server ready"));
    QFont a = QFont();
    a.setWeight(72);
    a.setPixelSize(72);
    serverStatusLabel->setFont(a);
    a.setPixelSize(54);
    a.setWeight(20);
    serverStatusLabel->setAlignment(Qt::AlignCenter);
    name = new QLabel("press start to seach devices");
    name->setFont(a);
    name->setAlignment(Qt::AlignCenter);
    pass = new QLabel("welcome");
    pass->setAlignment(Qt::AlignCenter);
    pass->setFont(a);

    startButton = new QPushButton(tr("&Start"));
    startButton->setMinimumWidth(this->width()/2 -5);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setMinimumWidth(this->width()/2 -5);
    reject = new QPushButton("reject");
    reject->setMinimumWidth(this->width()/2 -5);
    accept = new QPushButton("accept");
    accept->setMinimumWidth(this->width()/2 -5);

    upperbuttonBox = new QDialogButtonBox;
    upperbuttonBox->addButton(accept,QDialogButtonBox::AcceptRole);
    upperbuttonBox->addButton(reject, QDialogButtonBox::RejectRole);
    upperbuttonBox->setMinimumWidth(this->width() - 10);

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(startButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);
    buttonBox->setMinimumWidth(this->width() - 10);

    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(&tcpServer, SIGNAL(newConnection()),
            this, SLOT(acceptConnection()));
    connect(accept,SIGNAL(clicked()),this,SLOT(acceptuser()));
    connect(reject,SIGNAL(clicked(bool)),this,SLOT(rejectuser()));

    if(state == CONNECTED)
        connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(updateServerProgress()));

    accept->setEnabled(false);
    reject->setEnabled(false);

    QWidget *mainwidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->addWidget(serverStatusLabel);
    mainLayout->addWidget(name);
    mainLayout->addWidget(pass);
    mainLayout->addWidget(upperbuttonBox);
    mainLayout->addWidget(buttonBox);

    mainwidget->setLayout(mainLayout);
    mainwidget->showMaximized();
    setCentralWidget(mainwidget);
    setWindowTitle("Negahban");
}

esia::~esia()
{

}


void esia::start()
{
    startButton->setEnabled(false);

#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    while (!tcpServer.isListening() && !tcpServer.listen(QHostAddress("192.168.43.99") , 7778 )) {
        QMessageBox::StandardButton ret = QMessageBox::critical(this,
                                        tr("Loopback"),
                                        tr("Unable to start the connection: %1.")
                                        .arg(tcpServer.errorString()),
                                        QMessageBox::Retry
                                        | QMessageBox::Cancel);
        if (ret == QMessageBox::Cancel)
            return;
    }
    serverStatusLabel->setText(tr("%1.").arg(tcpServer.serverPort()));
}

void esia::acceptConnection()
{
    tcpServerConnection = tcpServer.nextPendingConnection();
    connect(tcpServerConnection, SIGNAL(readyRead()),
            this, SLOT(updateServerProgress()));
    connect(tcpServerConnection, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    serverStatusLabel->setText(tr("Accepted connection"));
    tcpServer.close();
    pass->setText(tcpServerConnection->peerAddress().toString());
    state = CONNECTED;
}

void esia::updateServerProgress()
{
    char recievedBytes[100];
    strcpy(recievedBytes ,tcpServerConnection->readAll().data());
    QString temp = tr(recievedBytes);
    QString temp2 = temp;
    int a = temp.indexOf('#');

    temp2.remove(0,a+1);
    temp.truncate(a);
    name->setText(temp);
    pass->setText(temp2);
    startButton->setEnabled(true);
    accept->setEnabled(true);
    reject->setEnabled(true);
    if(usernames.indexOf(temp)>=0)
        if(passwords[usernames.indexOf(temp)] == temp2)
            acceptuser();
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
}

void esia::displayError(QAbstractSocket::SocketError socketError)
{
    if (socketError == QTcpSocket::RemoteHostClosedError)
        return;

    tcpServer.close();
    serverStatusLabel->setText(tr("Server ready"));
    startButton->setEnabled(true);
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
}

void esia::acceptuser(){
    tcpServerConnection->write("accepted");
    usernames.push_back(name->text());
    passwords.push_back(pass->text());
    accept->setEnabled(false);
    reject->setEnabled(false);
}

void esia::rejectuser(){
    tcpServerConnection->write("rejected");
    accept->setEnabled(false);
    reject->setEnabled(false);
}
