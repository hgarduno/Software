/****************************************************************************
** Form interface generated from reading ui file 'UI/OrdenesRegistradas.ui'
**
** Created: Thu Dec 21 12:53:40 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENESREGISTRADAS_H
#define ORDENESREGISTRADAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QButtonGroup;
class QRadioButton;
class QTable;
class QTabWidget;
class QLabel;
class CQControlFecha;
class QPushButton;

class OrdenesRegistradas : public QWidget
{
    Q_OBJECT

public:
    OrdenesRegistradas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~OrdenesRegistradas();

    QButtonGroup* QBGTipoOrden;
    QRadioButton* QRBVentas;
    QRadioButton* QRBCotizaciones;
    QRadioButton* QRBPedidos;
    QRadioButton* radioButton15;
    QRadioButton* radioButton5;
    QTable* QTOrdenes;
    QTabWidget* QTWDatosOrden;
    QWidget* tab;
    QTable* QTOrden;
    QWidget* tab_2;
    QLabel* textLabel2;
    QLabel* textLabel4;
    CQControlFecha* QCtrFechaIni;
    QLabel* textLabel4_2;
    CQControlFecha* QCtrFechaFin;
    QPushButton* QPBDetalleOrden;
    QPushButton* QPBConsultar;
    QPushButton* QPBVender;
    QPushButton* QPBSeReflejo;
    QPushButton* QPBImprimir;
    QPushButton* QPBDevolucion;

protected:
    QGridLayout* OrdenesRegistradasLayout;
    QHBoxLayout* QTLPrincipal;
    QVBoxLayout* QBGTipoOrdenLayout;
    QGridLayout* tabLayout;
    QHBoxLayout* layout7;
    QSpacerItem* spacer1;
    QHBoxLayout* layout6;
    QHBoxLayout* layout17;
    QHBoxLayout* layout17_2;
    QHBoxLayout* layout13;

protected slots:
    virtual void languageChange();

};

#endif // ORDENESREGISTRADAS_H
