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
#include <QCoreApplication>
#include <QtConcurrent/QtConcurrent>
#include <cassert>

class PullTXsThread : public QObject
{
    Q_OBJECT
public:
    bool is_terminated;

    PullTXsThread() = default;

    PullTXsThread(const QString& address);

    PullTXsThread(const QString& address, bool _ign_int_txs,
                                          bool _ign_coms,
                                          bool _ign_zv_txs,
                                          bool _inc_adr);

    ~PullTXsThread();

    void run();

signals:
    void upd_gui_signal(const QString&, const double&);
    void pass_error(const QString&);

private:
    QString address;
    QString API_KEY;

    bool ign_int_txs;
    bool ign_coms;
    bool ign_zv_txs;
    bool inc_adr;

    enum request_mode { NORMAL, INTERNAL };

    void request(request_mode);

    QJsonObject request_page(int page_number, request_mode mode);

    QJsonObject json_from_str(const QString&);

    QString build_by_map(double&, QMap<QString, QVariant> const&);

    QString wei_str_to_eth(QString);
};

#endif // PULLTXSTHREAD_H
