/****************************************************************************
** Form interface generated from reading ui file 'UI/ReporteVentas.ui'
**
** Created: lun abr 1 19:11:21 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPORTEVENTAS_H
#define REPORTEVENTAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;
class QPushButton;
class QLCDNumber;
class QTabWidget;
class QTable;

class ReporteVentas : public QWidget
{
    Q_OBJECT

public:
    ReporteVentas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ReporteVentas();

    QLabel* textLabel1;
    CQControlFecha* QCtrFechaIni;
    QLabel* textLabel1_2;
    CQControlFecha* QCtrFechaFin;
    QPushButton* QPBEjecuta;
    QLCDNumber* QLCDNTotal;
    QTabWidget* tabWidget7;
    QWidget* tab;
    QLabel* textLabel2;
    QTable* QTDatos;
    QWidget* tab_2;
    QTable* QTDetalle;

protected:
    QGridLayout* ReporteVentasLayout;
    QHBoxLayout* layout6;
    QSpacerItem* spacer1;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QHBoxLayout* layout4;
    QGridLayout* tabLayout;
    QVBoxLayout* layout3;
    QGridLayout* tabLayout_2;

protected slots:
    virtual void languageChange();

};

#endif // REPORTEVENTAS_H
