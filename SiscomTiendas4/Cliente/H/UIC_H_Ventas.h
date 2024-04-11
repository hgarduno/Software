/****************************************************************************
** Form interface generated from reading ui file 'UI/Ventas.ui'
**
** Created: Thu Apr 11 20:30:18 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef VENTAS_H
#define VENTAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QCtrlPrecios;
class QCtrlProductos;
class QLineEdit;
class QCtrlClientes;
class QCtrlContactos;
class QCtrlFormaPago;
class QPushButton;
class QGroupBox;
class QTextEdit;
class QLCDNumber;

class Ventas : public QWidget
{
    Q_OBJECT

public:
    Ventas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Ventas();

    QLabel* textLabel2_4;
    QTable* QTDatos;
    QLabel* textLabel2_7;
    QCtrlPrecios* QCtrPrecios;
    QLabel* textLabel2_2;
    QCtrlProductos* QCtrProductos;
    QLabel* textLabel2_2_2;
    QLineEdit* QLECantidad;
    QLabel* textLabel2_2_2_2;
    QLineEdit* QLEImporte;
    QLabel* textLabel2;
    QCtrlClientes* QCtrClientes;
    QLabel* textLabel2_8;
    QCtrlContactos* QCtrContactos;
    QLabel* textLabel2_9;
    QCtrlFormaPago* QCtrFPago;
    QPushButton* QPBAnexar;
    QPushButton* pushButton5_2;
    QPushButton* QPBImprimir;
    QPushButton* QPBRegistra;
    QPushButton* QPBEliminar;
    QGroupBox* groupBox1;
    QLabel* textLabel2_5;
    QLineEdit* QLECliente;
    QLabel* textLabel2_3;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel2_6_2_3;
    QLCDNumber* QLCDNExistencia;
    QLabel* textLabel2_6_2;
    QLCDNumber* QLCDNPrecio;
    QLabel* textLabel2_6_2_2;
    QLCDNumber* QLCDNImporte;
    QLabel* textLabel2_6;
    QLCDNumber* QLCDTotalOrden;

protected:
    QGridLayout* VentasLayout;
    QVBoxLayout* layout44;
    QHBoxLayout* layout24;
    QVBoxLayout* layout19;
    QVBoxLayout* layout41;
    QVBoxLayout* layout42;
    QVBoxLayout* layout42_2;
    QVBoxLayout* layout14;
    QVBoxLayout* layout21;
    QVBoxLayout* layout22;
    QHBoxLayout* layout23;
    QGridLayout* groupBox1Layout;
    QVBoxLayout* layout61;
    QVBoxLayout* layout43;
    QVBoxLayout* layout22_2;
    QVBoxLayout* layout50_2_3;
    QHBoxLayout* layout21_2;
    QVBoxLayout* layout50_2;
    QVBoxLayout* layout50_2_2;
    QVBoxLayout* layout50;

protected slots:
    virtual void languageChange();

};

#endif // VENTAS_H
