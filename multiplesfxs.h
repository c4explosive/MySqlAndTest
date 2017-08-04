#ifndef MULTIPLESFXS_H
#define MULTIPLESFXS_H
#include <QSqlDatabase>
#include <QWidget>
#include <QComboBox>
#include <QTableView>
#include <QString>


class multiplesFxs
{
public:
    enum ventanas {AGREGARUTASK,MODIFICARUTASK,BUSCARUTASK,ELIMINARUTASK,ASIGFOLDER,BUSCASEMANA};
    multiplesFxs();
    static void whatWindow(QWidget *,int);
    static void dbConnect(QWidget *, QString IPaddr);
    static void updateDB(QComboBox * cbo,QString Table,QString column);
    static void updateDB(QComboBox * cbo,QString Table,QString column,QString filter);
    static QString getID(QString Table, QString id_col, QString col, QString qVal);
    //static void getResults(QTableView *widget,QString obj);
    static QString getAtribute(QString Table, QString col, QString id_col, QString id);
    static void updateDB(QComboBox *cbo, QString Table, QString column, QString column2, QString filter);
    static void fixmyScreen(QWidget *widget);
    static QDate get_monday(QDate);
    static QList<QString> getStrings(QDate);
};

#endif // MULTIPLESFXS_H
