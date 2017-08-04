#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "androidfiledialog.h"
#include "view_horary.h"

#include <QDebug>
#include <QScreen>
#include <QTime>
#include <QImage>
#include <QPixmap>

#include <QtAndroidExtras/QAndroidJniObject>
#include <QtAndroidExtras/QtAndroid>
#include <QtAndroidExtras/QAndroidActivityResultReceiver>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(static_cast<uint>(QTime::currentTime().msec())); //srand con el tiempo actual convertido a milisegundos y casteado a uint
    //qDebug()<<"Todo Right";

}
void MainWindow::orientCh(const QRect)
{
    multiplesFxs::fixmyScreen(ui->centralwidget);
    //qDebug()<<":::::Funciono???";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAddTask_clicked()
{
    multiplesFxs::whatWindow(this,multiplesFxs::AGREGARUTASK);
}

void MainWindow::on_actionOpenDatabase_triggered()
{
   multiplesFxs::dbConnect(this,"127.0.0.1");
   //multiplesFxs::dbConnect(this,"192.168.1.103");
}

void MainWindow::on_btnModTask_clicked()
{
    multiplesFxs::whatWindow(this,multiplesFxs::MODIFICARUTASK);
}

void MainWindow::on_btnShowTask_clicked()
{
    multiplesFxs::whatWindow(this,multiplesFxs::BUSCARUTASK);

}

void MainWindow::on_btnDelTask_clicked()
{
    multiplesFxs::whatWindow(this,multiplesFxs::ELIMINARUTASK);

}

void MainWindow::on_btnShowWeek_clicked()
{
    multiplesFxs::whatWindow(this,multiplesFxs::BUSCASEMANA);
}


void MainWindow::openFileNameReady(QString fileName)
{
    if(!fileName.isNull())
    {
        qDebug() << "FileName: "<< fileName;
        impath=fileName;
        qDebug()<<"Ruta:: "<<impath;
        /*QImage image(impath);
        QImage image2 = image.scaled(500,500);
        ui->lbPict->setScaledContents(true);
        ui->lbPict->setPixmap(QPixmap::fromImage(image2));
        multiplesFxs::fixmyScreen(ui->centralwidget);*/ //Image embeded
    }
    else
    {
        qDebug() << "User did not choose file...";
    }
}

void MainWindow::on_actionS_intent_triggered()
{
   androidfiledialog * fileDialog = new androidfiledialog();
   connect(fileDialog,SIGNAL(existingFileNameReady(QString)),this,SLOT(openFileNameReady(QString)));
   bool sucess = fileDialog->provideExistingFileName();
   if (!sucess)
   {
       qDebug()<< "Algo anda jodido... JNI probablemente...";
       disconnect(fileDialog, SIGNAL(existingFileNameReady(QString)), this, SLOT(openFileNameReady(QString)));
   }

}

void MainWindow::on_actionH_img_triggered()
{
    view_horary * vH = new view_horary(this);
    vH->show();
}

void MainWindow::on_actionHsIntent_Testing_generic_triggered()
{
    //Intent Test
    QAndroidJniObject ACTION_S_TIMER = QAndroidJniObject::getStaticObjectField<jobject>("android/provider/AlarmClock", "ACTION_SET_TIMER");


    QAndroidJniObject intent("android/content/Intent",
                             "(Ljava/lang/String;)V",
                             ACTION_S_TIMER.object());

    QAndroidJniObject EXTRA_MESSAGE = QAndroidJniObject::getStaticObjectField<jobject>("android/provide/AlarmClock",
                                                                        "EXTRA_MESSAGE");


    QAndroidJniObject messageObject = QAndroidJniObject::fromString("Hs improve v5...");
    intent.callObjectMethod("putExtra",
                            "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;",
                            EXTRA_MESSAGE.object(),
                            messageObject.object());
    QAndroidJniObject EXTRA_LENGTH = QAndroidJniObject::getStaticObjectField<jobject>("android/provider/AlarmClock",
                                                                             "EXTRA_LENGTH");
    intent.callObjectMethod("putExtra",
                            "(Ljava/lang/String;I)Landroid/content/Intent;",
                            EXTRA_LENGTH.object(),
                            jint(100 * 60 ));

    QAndroidJniObject EXTRA_SKIP_UI = QAndroidJniObject::getStaticObjectField<jobject>("android/provider/AlarmClock",
                                                                              "EXTRA_SKIP_UI");
    intent.callObjectMethod("putExtra",
                            "(Ljava/lang/String;Z)Landorid/content/Intent;",
                            EXTRA_SKIP_UI.object(),
                            jboolean(true));


    QAndroidJniObject activity = QtAndroid::androidActivity();
    QAndroidJniObject packegeManager = activity.callObjectMethod("getPackageManager",
                                                                 "()Landroid/content/pm/PackageManager;");

    QAndroidJniObject compName = intent.callObjectMethod("resolveActivity",
                                                         "(Landroid/content/pm/PackageManager;)Landroid/content/ComponentName",
                                                         packegeManager.object());

    if (compName.isValid())
    {
        QtAndroid::startActivity(intent,0);
    }
    else
    {
        qDebug()<<"Unable to find this shit...";
    }

}


