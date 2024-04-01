/****************************************************************************
** Form interface generated from reading ui file 'UI/OrdenElectronica.ui'
**
** Created: Wed Jan 31 10:47:55 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENELECTRONICA_H
#define ORDENELECTRONICA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QTabWidget;
class QPushButton;
class QLCDNumber;

class OrdenElectronica : public QWidget
{
    Q_OBJECT

public:
    OrdenElectronica( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~OrdenElectronica();

    QTable* QTDatos;
    QTabWidget* tabWidget6;
    QWidget* tab;
    QPushButton* QPBRealizaVenta;
    QPushButton* QPBOrdenCaja;
    QPushButton* QPBImprimeTicket;
    QWidget* tab_2;
    QPushButton* QPBImprimeCotizacion;
    QPushButton* QPBRCotizacion;
    QWidget* TabPage;
    QPushButton* QPBVOrden;
    QPushButton* QPBVCotizacion;
    QPushButton* pushButton11;
    QLCDNumber* QLCNTotal;

protected:
    QGridLayout* OrdenElectronicaLayout;
    QHBoxLayout* layout8;
    QVBoxLayout* layout7;
    QGridLayout* tabLayout;
    QVBoxLayout* layout6;
    QGridLayout* tabLayout_2;
    QVBoxLayout* layout47;
    QGridLayout* TabPageLayout;
    QVBoxLayout* layout48;

protected slots:
    virtual void languageChange();

};

#endif // ORDENELECTRONICA_H
