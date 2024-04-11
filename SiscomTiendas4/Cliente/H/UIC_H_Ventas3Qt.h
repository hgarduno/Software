/****************************************************************************
** Form interface generated from reading ui file 'UI/Ventas3Qt.ui'
**
** Created: Thu Apr 11 20:30:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef VENTAS3QT_H
#define VENTAS3QT_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlPrecios3Qt;
class QCtrlProductos3Qt;
class QLineEdit;
class QCtrlClientes3Qt;
class QCtrlContactos3Qt;
class QCtrlFormaPago3Qt;
class QTable;
class QPushButton;
class QGroupBox;
class QLCDNumber;
class QButtonGroup;
class QRadioButton;
class QCtrlPreciosProductos;
class QTextEdit;

class Ventas3Qt : public QWidget
{
    Q_OBJECT

public:
    Ventas3Qt( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Ventas3Qt();

    QLabel* textLabel1_5;
    QCtrlPrecios3Qt* QCtrPrecios;
    QLabel* textLabel1;
    QCtrlProductos3Qt* QCtrProductos;
    QLabel* textLabel2_2_2;
    QLineEdit* QLECantidad;
    QLabel* textLabel2_2_2_2;
    QLineEdit* QLEImporte;
    QLabel* textLabel1_2;
    QCtrlClientes3Qt* QCtrClientes;
    QLabel* textLabel1_3;
    QCtrlContactos3Qt* QCtrContactos;
    QLabel* textLabel1_4;
    QCtrlFormaPago3Qt* QCtrFPago;
    QLabel* textLabel2_4;
    QTable* QTDatos;
    QPushButton* QPBAnexar;
    QPushButton* pushButton5_2;
    QPushButton* QPBImprimir;
    QPushButton* QPBRegistra;
    QPushButton* QPBEliminar;
    QGroupBox* groupBox1;
    QLabel* textLabel2_6_2_3;
    QLCDNumber* QLCDNExistencia;
    QButtonGroup* QBGTOrden;
    QRadioButton* QRBRemision;
    QRadioButton* QRBFactura;
    QRadioButton* QRBCotizacion;
    QLabel* textLabel2_6_2;
    QLCDNumber* QLCDNPrecio;
    QLabel* textLabel2_6_2_2;
    QLCDNumber* QLCDNImporte;
    QLabel* textLabel2_6_3_2;
    QLCDNumber* QLCDTotalOrdenSinIva;
    QLabel* textLabel2_6_3;
    QLCDNumber* QLCDIva;
    QLabel* textLabel2_6;
    QLCDNumber* QLCDTotalOrden;
    QLabel* textLabel1_6;
    QCtrlPreciosProductos* QCtrPProducto;
    QLabel* textLabel2_5;
    QLineEdit* QLECliente;
    QLabel* textLabel2_3;
    QTextEdit* QTEDescripcion;

protected:
    QGridLayout* Ventas3QtLayout;
    QHBoxLayout* layout26;
    QVBoxLayout* layout5;
    QVBoxLayout* layout19;
    QVBoxLayout* layout42;
    QVBoxLayout* layout42_2;
    QHBoxLayout* layout28;
    QVBoxLayout* layout2;
    QVBoxLayout* layout3;
    QVBoxLayout* layout22;
    QVBoxLayout* layout44;
    QHBoxLayout* layout23;
    QGridLayout* groupBox1Layout;
    QHBoxLayout* layout32;
    QVBoxLayout* layout50_2_3;
    QGridLayout* QBGTOrdenLayout;
    QVBoxLayout* layout26_2;
    QHBoxLayout* layout27;
    QVBoxLayout* layout50_2;
    QVBoxLayout* layout50_2_2;
    QVBoxLayout* layout28_2;
    QVBoxLayout* layout50_3_2;
    QVBoxLayout* layout50_3;
    QVBoxLayout* layout50;
    QVBoxLayout* layout25;
    QVBoxLayout* layout23_2;
    QVBoxLayout* layout61;
    QVBoxLayout* layout43;

protected slots:
    virtual void languageChange();

};

#endif // VENTAS3QT_H
