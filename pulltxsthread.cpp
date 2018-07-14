#include "pulltxsthread.h"

PullTXsThread::PullTXsThread(const QString& _address) :
    address(_address),
    API_KEY("KMUQF21Z97Y1RI98HTYX5YESXAQCA22XN7")
{}

PullTXsThread::~PullTXsThread() {
    wait();
}

void PullTXsThread::run() {
    int page_number = 1;
    QJsonObject req_result;

    while (true) {
        req_result = request_page(page_number++);
        if (!req_result.contains("result"))
            break;
        QVariantMap json_map = req_result.toVariantMap();
        QVariantList arr = json_map["result"].toList();
        if (arr.isEmpty())
            break;
        for (int i = 0; i < arr.count(); ++i) {
            qDebug() << arr[i].toMap()["value"];
        }
    }
}

QJsonObject PullTXsThread::request_page(int page_number) {
    QNetworkAccessManager manager;
    QEventLoop ql;
    QTimer t;
    t.setSingleShot(true);
    connect(&t, SIGNAL(timeout()), &ql, SLOT(quit()));
    connect(&manager, SIGNAL(finished(QNetworkReply*)), &ql, SLOT(quit()));
    QString url = QString("https://api.etherscan.io/api?module=account&action=txlist&address=%1&"
                          "startblock=0&endblock=blockNo&page=%2&offset=100&"
                          "sort=asc&apikey=%3").arg(address, QString::number(page_number), API_KEY);
    QNetworkReply *reply = manager.get(QNetworkRequest(QUrl(url)));
    t.start(10000);
    ql.exec();

    if(t.isActive()){
        // download complete
        t.stop();
    } else {
        // timeout
    }

    QByteArray byte_arr = reply->readAll();
    QString result = QString::fromUtf8(byte_arr.data(), byte_arr.size());
    return json_from_str(result);
}

QJsonObject PullTXsThread::json_from_str(const QString& in)
{
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());

    if (!doc.isNull()) {
        if (doc.isObject())
            obj = doc.object();
        else
            qDebug() << "Document is not an object" << endl;
    }
    else {
        qDebug() << "Invalid JSON...\n" << in << endl;
    }

    return obj;
}
