#ifndef ESIA_H
#define ESIA_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QLineEdit>

#define NOT_CONNECTED 0
#define CONNECTED 1
QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QLabel;
class QProgressBar;
class QPushButton;
class QTcpServer;
class QTcpSocket;
class QAction;
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
    void displayError(QAbstractSocket::SocketError socketError);
    void acceptuser();
    void rejectuser();
private:
    QTcpServer tcpServer;
    QTcpSocket *tcpServerConnection;
    QTabWidget *tabs;
    bool state;
    QLabel *serverStatusLabel;
    QLabel *name;
    QLabel *pass;
    QPushButton* accept;
    QPushButton* reject;
    QPushButton *startButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QDialogButtonBox *upperbuttonBox;
    QVector<QString> usernames;
    QVector<QString> passwords;
};

#endif // ESIA_H
