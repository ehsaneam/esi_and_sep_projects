#include <QtWidgets>
#include <QtNetwork>
#include <qdebug.h>
#include "esia.h"

esia::esia(QWidget *parent)
    : QMainWindow(parent)
{
    state = NOT_CONNECTED;
    mode = -1;
    serverStatusLabel = new QLabel(tr("Not connected ...!"));
    QFont a = QFont();
    a.setWeight(70);
    a.setPixelSize(10);
    serverStatusLabel->setFont(a);
    a.setPixelSize(15);
    a.setWeight(12);
    serverStatusLabel->setAlignment(Qt::AlignCenter);
    message = new QLabel("First Choose a name for yourself");
    message->setFont(a);
    message->setAlignment(Qt::AlignLeft);
    message->setFixedSize(this->width()/2 - 2,this->height()/2 - 2);
    scrollArea = new QScrollArea();
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(message);
    txtbox = new QLineEdit();
    txtbox->setAlignment(Qt::AlignLeft);
    txtbox->setFont(a);
    txtbox->setFixedSize(this->width()/2 - 2,this->height()/2 - 2);

    find_friends = new QPushButton(tr("&find friends"));
    find_friends->setMinimumWidth(this->width()/2 -5);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setMinimumWidth(this->width()/2 -5);

    send = new QPushButton("set name");
    send->setMinimumWidth(this->width()/2 -5);
    send->setEnabled(false);
    connect2friend = new QPushButton("connect to a friend");
    connect2friend ->setMinimumWidth(this->width()/2 -5);

    upperbuttonBox = new QDialogButtonBox;
    upperbuttonBox->addButton(send,QDialogButtonBox::AcceptRole);
    upperbuttonBox->addButton(connect2friend,QDialogButtonBox::AcceptRole);
    upperbuttonBox->setMinimumWidth(this->width() - 10);

    buttonBox = new QDialogButtonBox;
    buttonBox->addButton(find_friends, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);
    buttonBox->setMinimumWidth(this->width() - 10);

    connect(find_friends, SIGNAL(clicked()), this, SLOT(start()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    if(send->text() == "set name")
        connect(txtbox,SIGNAL(textChanged(QString)),this,SLOT(enable()));
    connect(&tcpServer, SIGNAL(newConnection()),
        this, SLOT(acceptConnection()));
    connect(send,SIGNAL(clicked()),this,SLOT(send_message()));
    connect(connect2friend,SIGNAL(clicked(bool)),this,SLOT(clientconnect()));

    if(state == CONNECTED && mode == SERVERMODE)
        connect(tcpServerConnection,SIGNAL(readyRead()),this,SLOT(updateServerProgress()));
    if(state == CONNECTED && mode == CLIENTMODE)
        connect(&tcpClientConnection,SIGNAL(readyRead()),this,SLOT(updateClientProgress()));
    find_friends->setEnabled(false);
    connect2friend->setEnabled(false);

    QWidget *mainwidget = new QWidget();
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *chatLayout = new QHBoxLayout;

    mainLayout->addWidget(serverStatusLabel);
    chatLayout->addWidget(scrollArea);
    chatLayout->addWidget(txtbox);
    mainLayout->addLayout(chatLayout);
    mainLayout->addWidget(upperbuttonBox);
    mainLayout->addWidget(buttonBox);

    mainwidget->setLayout(mainLayout);
    mainwidget->showMaximized();
    setCentralWidget(mainwidget);
    setWindowTitle("Esigram");
}

esia::~esia()
{

}


void esia::start()
{
    find_friends->setEnabled(false);
    mode = SERVERMODE;
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    while (!tcpServer.isListening() && !tcpServer.listen(QHostAddress("192.168.1.100") , 7778 )) {
        QMessageBox::StandardButton ret = QMessageBox::critical(this,
                                        tr("Loopback"),
                                        tr("Unable to start the connection: %1.")
                                        .arg(tcpServer.errorString()),
                                        QMessageBox::Retry
                                        | QMessageBox::Cancel);
        if (ret == QMessageBox::Cancel)
            return;
    }
    //serverStatusLabel->setText(tr("%1.").arg(tcpServer.serverPort()));
    connect2friend->setEnabled(false);
    find_friends->setEnabled(false);
    message->clear();
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
    //message->setText(tcpServerConnection->peerAddress().toString());
    QString temp = "#" + accountName + " joined chat";
    tcpServerConnection->write(temp.toUtf8().data());
    state = CONNECTED;
    txtbox->setEnabled(true);
}

void esia::updateServerProgress()
{
    char recievedBytes[1000];
    strcpy(recievedBytes ,tcpServerConnection->readAll().data());
    if(recievedBytes[0] == '#'){
        serverStatusLabel->setText(QString(recievedBytes).remove(0,1));
    }
    else{
        QString temp = QString(recievedBytes);
        if(recievedBytes[0] == '$' && recievedBytes[1] == '#')
            temp = temp.remove(0,1);
        message->setText(message->text() + temp);
    }
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
}

void esia::updateClientProgress(){
    char recievedBytes[1000];
    strcpy(recievedBytes ,tcpClientConnection.readAll().data());
    if(recievedBytes[0] == '#'){
        serverStatusLabel->setText(QString(recievedBytes).remove(0,1));
        QString temp = "#" + accountName + " joined chat";
        tcpClientConnection.write(temp.toUtf8().data());
    }
    else{
        QString temp = QString(recievedBytes);
        if(recievedBytes[0] == '$' && recievedBytes[1] == '#')
            temp = temp.remove(0,1);
        message->setText(message->text() + temp);
    }
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
}

void esia::displayError(QAbstractSocket::SocketError socketError)
{
    if (socketError == QTcpSocket::RemoteHostClosedError)
        return;

    tcpServer.close();
    tcpServerConnection->close();
    serverStatusLabel->setText(tr("Server ready"));
    find_friends->setEnabled(true);
    connect2friend->setEnabled(true);
    mode = -1;
    serverStatusLabel->setText("Not connected ...!");
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
}

void esia::displayErrorClient(QAbstractSocket::SocketError socketError)
{
    if (socketError == QTcpSocket::RemoteHostClosedError)
        return;

    QMessageBox::information(this, tr("Network error"),
                             tr("The following error occurred: %1.")
                             .arg(tcpClientConnection.errorString()));
    tcpClientConnection.close();
    serverStatusLabel->setText(tr("Client ready"));
    connect2friend->setEnabled(true);
    find_friends->setEnabled(true);
    mode = -1;
    serverStatusLabel->setText("Not connected ...!");
    #ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif
}

void esia::send_message(){
    if(send->text() == "set name"){
        accountName = txtbox->text();
        message->setText("now, if you don't have any friend\npress find friend, otherwise\nclick on connect to a friend");
        send->setText("send");
        connect2friend->setEnabled(true);
        find_friends->setEnabled(true);
        send->setEnabled(false);
        txtbox->clear();
        txtbox->setEnabled(false);
    }
    else{
        QString temp = accountName + " : " + txtbox->text() + "\n";
        message->setText(message->text() + temp);
        if(mode == SERVERMODE)
            tcpServerConnection->write(temp.toUtf8().data());
        else if(mode == CLIENTMODE)
            tcpClientConnection.write(temp.toUtf8().data());
        txtbox->clear();
    }
}

void esia::clientconnect(){
    if(message->text() == "now, if you don't have any friend\npress find friend, otherwise\nclick on connect to a friend"){
        message->setText("Enter your friends IPv4");
        connect2friend->setText("Request for Chat");
        mode = CLIENTMODE;
        connect(&tcpClientConnection, SIGNAL(error(QAbstractSocket::SocketError)),
                this, SLOT(displayError(QAbstractSocket::SocketError)));
        txtbox->setEnabled(true);
        connect2friend->setEnabled(false);
    }
    else{
        QString temp = txtbox->text();
        message->setText("");
        send->setText("send");
        connect2friend->setEnabled(false);
        find_friends->setEnabled(false);
        connect2friend->setText("connect to a friend");
        txtbox->clear();
        tcpClientConnection.connectToHost(QHostAddress(temp), 7778 );
        connect(&tcpClientConnection,SIGNAL(readyRead()),this,SLOT(updateClientProgress()));
    }
}

void esia::enable(){
    if(send->text() == "set name")
        send->setEnabled(true);
    if(connect2friend->text() == "Request for Chat")
        connect2friend->setEnabled(true);
    if(serverStatusLabel->text() != "Not connected ...!" && mode == SERVERMODE)
        send->setEnabled(true);
    if(serverStatusLabel->text() != "Not connected ...!" && mode == CLIENTMODE)
        send->setEnabled(true);
}
