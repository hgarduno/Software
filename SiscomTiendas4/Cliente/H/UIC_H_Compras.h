/****************************************************************************
** Form interface generated from reading ui file 'UI/Compras.ui'
**
** Created: Sun Jan 28 16:00:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COMPRAS_H
#define COMPRAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;
class QCtrlProductos;
class QCtrlEmpresas;
class QCtrlContactos;
class QCtrlFormaPago;
class QGroupBox;

class Compras : public QWidget
{
    Q_OBJECT

public:
    Compras( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Compras();

    QLabel* textLabel2_2;
    QLineEdit* QLECantidad;
    QLabel* textLabel2_2_2;
    QLineEdit* QLEPrecio;
    QLabel* textLabel2_2_2_2;
    QLineEdit* QLENFactura;
    QLabel* textLabel5;
    QTable* QTDatos;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegistra;
    QPushButton* pushButton1_2_2;
    QLabel* textLabel1;
    QCtrlProductos* QCtrProductos;
    QLabel* textLabel2;
    QCtrlEmpresas* QCtrProveedores;
    QLabel* textLabel1_2;
    QCtrlContactos* QCtrContactos;
    QLabel* textLabel1_3;
    QCtrlFormaPago* QCtrFPago;
    QGroupBox* groupBox1;
    QLabel* textLabel4;
    QLineEdit* QLEUCProducto;
    QLabel* textLabel4_3;
    QLineEdit* QLEUCCantidad;
    QLabel* textLabel4_4;
    QLineEdit* QLEUCPrecio;
    QLabel* textLabel4_2;
    QLineEdit* QLEUCProveedor;
    QLabel* textLabel4_3_2;
    QLineEdit* QLEUCContacto;
    QLabel* textLabel4_3_2_2;
    QLineEdit* QLEUCFactura;
    QLabel* textLabel4_3_2_2_2;
    QLineEdit* QLEUCFecha;

protected:
    QGridLayout* ComprasLayout;
    QHBoxLayout* layout13;
    QVBoxLayout* layout6;
    QVBoxLayout* layout6_2;
    QVBoxLayout* layout6_2_2;
    QVBoxLayout* layout14;
    QHBoxLayout* layout24;
    QHBoxLayout* layout22;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QVBoxLayout* layout3;
    QVBoxLayout* layout21;
    QGridLayout* groupBox1Layout;
    QHBoxLayout* layout36;
    QSpacerItem* spacer1;
    QHBoxLayout* layout35;
    QVBoxLayout* layout8;
    QVBoxLayout* layout8_3;
    QVBoxLayout* layout8_4;
    QHBoxLayout* layout38;
    QHBoxLayout* layout37;
    QVBoxLayout* layout8_2;
    QVBoxLayout* layout8_3_2;
    QVBoxLayout* layout8_3_2_2;
    QVBoxLayout* layout8_3_2_2_2;

protected slots:
    virtual void languageChange();

};

#endif // COMPRAS_H
