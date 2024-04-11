/****************************************************************************
** Form interface generated from reading ui file 'UI/ReportesVentas.ui'
**
** Created: Wed Apr 10 20:52:26 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPORTESVENTAS_H
#define REPORTESVENTAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTabWidget;
class QLabel;
class QTable;
class QLCDNumber;
class QPushButton;

class ReportesVentas : public QWidget
{
    Q_OBJECT

public:
    ReportesVentas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ReportesVentas();

    QTabWidget* QTWDatos;
    QWidget* tab;
    QLabel* textLabel2;
    QTable* QTVentas;
    QLabel* textLabel2_2;
    QTable* QTOrdenes;
    QLabel* textLabel1;
    QTable* QTDatos;
    QLabel* textLabel1_2;
    QTable* QTOrdenesE;
    QLabel* textLabel1_2_2;
    QTable* QTOrdenesETotales;
    QLCDNumber* QLCDNTotal;
    QPushButton* QPBRefrescar;
    QPushButton* QPBFReporte;
    QPushButton* QPBSExpendio;

protected:
    QGridLayout* ReportesVentasLayout;
    QGridLayout* tabLayout;
    QHBoxLayout* layout92;
    QVBoxLayout* layout90;
    QVBoxLayout* layout90_2;
    QHBoxLayout* layout9;
    QVBoxLayout* layout93;
    QVBoxLayout* layout93_2;
    QVBoxLayout* layout93_2_2;

protected slots:
    virtual void languageChange();

};

#endif // REPORTESVENTAS_H
