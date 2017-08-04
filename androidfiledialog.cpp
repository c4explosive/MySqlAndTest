#include "androidfiledialog.h"


androidfiledialog::ResultReceiver::ResultReceiver(androidfiledialog * dialog) : _dialog(dialog) {}
androidfiledialog::ResultReceiver::~ResultReceiver() {}

void androidfiledialog::ResultReceiver::handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject &data)
{
    jint RESULT_OK = QAndroidJniObject::getStaticField<jint>("android/app/Activity","RESULT_OK");
    if (receiverRequestCode == EXISTING_FILE_REQUEST && resultCode == RESULT_OK)
    {
        QAndroidJniObject uri = data.callObjectMethod("getData","()Landroid/net/Uri;");
        QString path = uriToPath(uri);
        _dialog->emitExistingFileNameReady(path);
    }
    else
    {
        _dialog->emitExistingFileNameReady(QString());
    }
}

QString androidfiledialog::ResultReceiver::uriToPath(QAndroidJniObject uri)
{
    if (uri.toString().startsWith("file",Qt::CaseInsensitive))
    {
        return uri.callObjectMethod("getPath","()Ljava/lang/String;").toString();
    }
    else
    {
        QAndroidJniObject contentResolver = QtAndroid::androidActivity().callObjectMethod("getContentResolver","()Landroid/content/ContentResolver;");
        QAndroidJniObject cursor = contentResolver.callObjectMethod("query","(Landroid/net/Uri;[Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;)Landroid/database/Cursor;", uri.object<jobject>(),0,0,0,0);
        QAndroidJniObject DATA = QAndroidJniObject::fromString("_data");
        jint columnIndex = cursor.callMethod<jint>("getColumnIndexOrThrow","(Ljava/lang/String;)I",DATA.object<jstring>());
        cursor.callMethod<jboolean>("moveToFirst","()Z");
        QAndroidJniObject result = cursor.callObjectMethod("getString","(I)Ljava/lang/String",columnIndex);
        return result.isValid() ? result.toString() : QString();
    }
}

androidfiledialog::androidfiledialog(QObject *parent) : QObject(parent)
{
    receiver = new ResultReceiver(this);
}


androidfiledialog::~androidfiledialog()
{
    delete receiver;
}

bool androidfiledialog::provideExistingFileName()
{
    QAndroidJniObject ACTION_GET_CONTENT = QAndroidJniObject::fromString("android.intent.action.GET_CONTENT");
    QAndroidJniObject intent("android/content/Intent");
    if (ACTION_GET_CONTENT.isValid() && intent.isValid())
    {
        intent.callObjectMethod("setAction","(Ljava/lang/String;)Landroid/content/Intent;", ACTION_GET_CONTENT.object<jstring>());
        intent.callObjectMethod("setType","(Ljava/lang/String;)Landroid/content/Intent;",QAndroidJniObject::fromString("file/*").object<jstring>());
        QtAndroid::startActivity(intent.object<jobject>(), EXISTING_FILE_REQUEST,receiver);
        return true;
    }
    else
    {
        return false;
    }
}

void androidfiledialog::emitExistingFileNameReady(QString result)
{
    emit existingFileNameReady(result);
}

