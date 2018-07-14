#ifndef PULLTXSTHREAD_H
#define PULLTXSTHREAD_H

#include <QThread>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QDebug>
#include <QEventLoop>
#include <QTimer>
#include <QJsonObject>
#include <QJsonDocument>

class PullTXsThread : public QThread
{
public:
    PullTXsThread(const QString& address);

    ~PullTXsThread();

    void run();

private:
    QString address;
    QString API_KEY;

    QJsonObject request_page(int page_number);

    QJsonObject json_from_str(const QString&);
};

#endif // PULLTXSTHREAD_H
