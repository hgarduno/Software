/****************************************************************************
** Form interface generated from reading ui file 'UI/ExistenciaExpendios.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef EXISTENCIAEXPENDIOS_H
#define EXISTENCIAEXPENDIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTabWidget;
class QLabel;
class QCtrlProductosSE;
class QTable;
class QPushButton;

class ExistenciaExpendios : public QWidget
{
    Q_OBJECT

public:
    ExistenciaExpendios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ExistenciaExpendios();

    QTabWidget* tabWidget2;
    QWidget* tab;
    QLabel* textLabel2;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel2_2;
    QTable* QTExistenciaExpendios;
    QPushButton* QPBAnexar;
    QPushButton* QPBActualizar;
    QWidget* tab_2;

protected:
    QGridLayout* ExistenciaExpendiosLayout;
    QGridLayout* tabLayout;
    QVBoxLayout* layout7;
    QVBoxLayout* layout3;
    QVBoxLayout* layout8;

protected slots:
    virtual void languageChange();

};

#endif // EXISTENCIAEXPENDIOS_H
