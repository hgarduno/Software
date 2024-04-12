/****************************************************************************
** Form interface generated from reading ui file 'UI/ManejadorImpresos.ui'
**
** Created: Thu Apr 11 21:39:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MANEJADORIMPRESOS_H
#define MANEJADORIMPRESOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class CQControlFecha;
class QCtrlEstadosImpresosSE;

class ManejadorImpresos : public QWidget
{
    Q_OBJECT

public:
    ManejadorImpresos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ManejadorImpresos();

    QLabel* textLabel2_5;
    QTable* QTDatos;
    QPushButton* QPBConsultar;
    QPushButton* QPBActualiza;
    QLabel* textLabel2;
    CQControlFecha* QCtrFechaInicio;
    QLabel* textLabel2_2;
    CQControlFecha* QCtrFechaFin;
    QLabel* textLabel1;
    QCtrlEstadosImpresosSE* QCtrEdosImpresos;

protected:
    QGridLayout* ManejadorImpresosLayout;
    QSpacerItem* spacer1;
    QVBoxLayout* layout42;
    QHBoxLayout* layout8;
    QVBoxLayout* layout3;
    QVBoxLayout* layout3_2;
    QVBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // MANEJADORIMPRESOS_H
