/****************************************************************************
** Form interface generated from reading ui file 'UI/ReporteVentas4.ui'
**
** Created: Wed Apr 10 20:52:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPORTEVENTAS4_H
#define REPORTEVENTAS4_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QTabWidget;
class QLabel;
class QTable;
class QFrame;
class CQControlFecha;
class QLCDNumber;

class ReporteVentas4 : public QWidget
{
    Q_OBJECT

public:
    ReporteVentas4( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ReporteVentas4();

    QPushButton* QPBSeleccionarExpendio;
    QPushButton* QPBConsultar;
    QTabWidget* tabWidget2;
    QWidget* tab;
    QLabel* textLabel2_3;
    QTable* QTVentasTotales;
    QLabel* textLabel2;
    QTable* QTVentaEscuela;
    QLabel* textLabel2_2;
    QTable* QTPedidosEscuela;
    QFrame* frame3;
    QLabel* textLabel3;
    CQControlFecha* QCtrFechaInicio;
    QLabel* textLabel3_2;
    CQControlFecha* QCtrFechaFin;
    QLabel* textLabel1;
    QLCDNumber* QLCDNVentasTotales;
    QLabel* textLabel1_2;
    QLCDNumber* QLCDNVentasApartados;
    QLabel* textLabel1_2_2;
    QLCDNumber* QLCDNVentasPedidos;
    QLabel* textLabel1_2_2_2;
    QLCDNumber* lCDNumber1_2_2_2;
    QTable* QTTotales;
    QTable* QTMaterialEscuela;
    QLabel* textLabel1_2_2_2_2;
    QLCDNumber* QLCDNTotal;
    QWidget* tab_2;

protected:
    QGridLayout* ReporteVentas4Layout;
    QGridLayout* layout14;
    QGridLayout* tabLayout;
    QHBoxLayout* layout18;
    QVBoxLayout* layout8_3;
    QVBoxLayout* layout8;
    QVBoxLayout* layout8_2;
    QGridLayout* frame3Layout;
    QHBoxLayout* layout25;
    QVBoxLayout* layout23;
    QHBoxLayout* layout13;
    QSpacerItem* spacer1;
    QHBoxLayout* layout12;
    QVBoxLayout* layout10;
    QVBoxLayout* layout10_2;
    QHBoxLayout* layout30;
    QVBoxLayout* layout4;
    QVBoxLayout* layout4_2;
    QVBoxLayout* layout4_2_2;
    QVBoxLayout* layout4_2_2_2;
    QHBoxLayout* layout22;
    QVBoxLayout* layout4_2_2_2_2;

protected slots:
    virtual void languageChange();

};

#endif // REPORTEVENTAS4_H
