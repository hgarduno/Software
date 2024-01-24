/****************************************************************************
** Form interface generated from reading ui file 'UI/AdministradorPedidos.ui'
**
** Created: Thu Dec 21 12:53:40 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ADMINISTRADORPEDIDOS_H
#define ADMINISTRADORPEDIDOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class CQControlFecha;
class QCtrlEstadosPedidosClienteSE;
class QButtonGroup;
class QRadioButton;
class QTable;
class QToolBox;
class QLCDNumber;

class AdministradorPedidos : public QWidget
{
    Q_OBJECT

public:
    AdministradorPedidos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~AdministradorPedidos();

    QPushButton* QPBConsultar;
    QPushButton* QPBActualizaEstado;
    QPushButton* QPBVender;
    QPushButton* QPBImprimir;
    QPushButton* QPBDevolucion;
    QLabel* textLabel4;
    CQControlFecha* QCtrFechaIni;
    QLabel* textLabel4_2;
    CQControlFecha* QCtrFechaFin;
    QLabel* textLabel1;
    QCtrlEstadosPedidosClienteSE* QCtrEstadosPedido;
    QButtonGroup* QBGTipoOrden;
    QRadioButton* QRBVentas;
    QRadioButton* QRBCotizaciones;
    QRadioButton* QRBPedidos;
    QRadioButton* QRBPedidosPorHora;
    QTable* QTOrdenes;
    QToolBox* toolBox1;
    QWidget* page1;
    QLabel* textLabel1_2;
    QLCDNumber* lCDNumber1;
    QLabel* textLabel1_2_2;
    QLCDNumber* lCDNumber1_2;
    QWidget* page2;
    QTable* table3;

protected:
    QGridLayout* AdministradorPedidosLayout;
    QHBoxLayout* layout8;
    QVBoxLayout* layout8_2;
    QHBoxLayout* layout7;
    QHBoxLayout* layout17;
    QHBoxLayout* layout17_2;
    QHBoxLayout* layout7_2;
    QHBoxLayout* layout22;
    QGridLayout* QBGTipoOrdenLayout;
    QVBoxLayout* layout9;
    QVBoxLayout* layout9_2;
    QGridLayout* page2Layout;

protected slots:
    virtual void languageChange();

};

#endif // ADMINISTRADORPEDIDOS_H
