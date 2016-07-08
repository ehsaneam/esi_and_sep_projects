#ifndef ESIA_H
#define ESIA_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QLineEdit>
#include <cstring>

#define NOT_CONNECTED 0
#define CONNECTED 1

#define CLIENTMODE 0
#define SERVERMODE 1

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QProgressBar;
class QPushButton;
class QTcpServer;
class QTcpSocket;
class QAction;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

class esia : public QMainWindow
{
    Q_OBJECT
public:
    esia(QWidget *parent = 0);
    ~esia();
public slots:
    void start();
    void acceptConnection();
    void updateServerProgress();
    void updateClientProgress();
    void displayError(QAbstractSocket::SocketError socketError);
    void displayErrorClient(QAbstractSocket::SocketError socketError);
    void send_message();
    void clientconnect();
    void enable();
private:
    QString accountName;
    QTcpServer tcpServer;
    QTcpSocket *tcpServerConnection;
    QTcpSocket tcpClientConnection;
    bool state;
    QLabel *serverStatusLabel;
    QLabel *message;
    QPushButton* send;
    QPushButton* connect2friend;
    QLineEdit *txtbox;
    QPushButton *find_friends;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QDialogButtonBox *upperbuttonBox;
    QScrollArea *scrollArea;
    int mode;
};

#endif // ESIA_H
