#ifndef ANDROIDFILEDIALOG_H
#define ANDROIDFILEDIALOG_H

#include <QObject>
#include <QtAndroidExtras/QAndroidJniObject>
#include <QtAndroidExtras/QtAndroid>
#include <QtAndroidExtras/QAndroidActivityResultReceiver>


class androidfiledialog : public QObject
{
    Q_OBJECT
public:
    explicit androidfiledialog(QObject *parent = 0);
    virtual ~androidfiledialog();
    bool provideExistingFileName();

private:
    class ResultReceiver: public QAndroidActivityResultReceiver {
        androidfiledialog *_dialog;
    public:
        ResultReceiver(androidfiledialog * dialog);
        virtual ~ResultReceiver();
        void handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject &data);
        QString uriToPath(QAndroidJniObject uri);
    };

    static const int EXISTING_FILE_REQUEST = 1;
    ResultReceiver *receiver;
    void emitExistingFileNameReady(QString result);

signals:
    void existingFileNameReady(QString result);

public slots:
};

#endif // ANDROIDFILEDIALOG_H
