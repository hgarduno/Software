/****************************************************************************
** Form interface generated from reading ui file 'UI/Compras.ui'
**
** Created: Thu Dec 21 13:55:44 2023
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
class QPushButton;
class QGroupBox;
class QLabel;
class QLineEdit;
class QTextEdit;
class QCtrlOrigenCompra;
class CQControlFecha;
class QComboBox;
class QCtrlCmbBodegas;
class QTable;

class Compras : public QWidget
{
    Q_OBJECT

public:
    Compras( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Compras();

    QPushButton* QPBAnexar;
    QPushButton* QPBRegistrar;
    QPushButton* QPBECompra;
    QGroupBox* QGBUCompra;
    QLabel* textLabel2_2;
    QLineEdit* QLEFechaCompra;
    QLabel* textLabel17_2_3;
    QLineEdit* QLECantidadUC;
    QLabel* textLabel17_2_2_2;
    QLineEdit* QLEPCompraUC;
    QLabel* textLabel17_2_2_2_2;
    QLineEdit* QLEPCompraUC_2;
    QLabel* textLabel17_3_4;
    QLineEdit* QLENumFacturaUC;
    QLabel* textLabel6_2;
    QLineEdit* QLERSUltimaCompra;
    QLabel* textLabel17_3_3;
    QLineEdit* QLEUnidades;
    QLabel* textLabel6;
    QTextEdit* QLEDescripcion;
    QGroupBox* groupBox2;
    QLabel* textLabel1_3_2_2;
    QCtrlOrigenCompra* QCtrOrigenCompra;
    QLabel* textLabel17;
    CQControlFecha* QCFCompra;
    QLabel* textLabel5;
    QComboBox* QCBProductos;
    QLabel* textLabel1_2;
    QCtrlCmbBodegas* QCtrCmbBodegas;
    QLabel* textLabel5_2;
    QComboBox* QCBProveedores;
    QLabel* textLabel5_2_2;
    QComboBox* QCBFormaPago;
    QLabel* textLabel17_2;
    QLineEdit* QLECantidad;
    QLabel* textLabel17_2_4;
    QLineEdit* QLECantidadATransferirZacatenco;
    QLabel* textLabel17_2_2;
    QLineEdit* QLEPCompra;
    QLabel* textLabel1;
    QLineEdit* QLEPVenta;
    QLabel* textLabel2;
    QComboBox* QCBTipoPrecio;
    QLabel* textLabel17_3;
    QLineEdit* QLENumFactura;
    QLabel* textLabel17_3_2;
    CQControlFecha* QCFPago;
    QTable* QTDatos;

protected:
    QGridLayout* ComprasLayout;
    QHBoxLayout* layout29;
    QGridLayout* QGBUCompraLayout;
    QVBoxLayout* layout18;
    QVBoxLayout* layout110_2_3;
    QVBoxLayout* layout110_2_2_2;
    QVBoxLayout* layout110_2_2_2_2;
    QVBoxLayout* layout110_3_3;
    QHBoxLayout* layout83;
    QVBoxLayout* layout48_2;
    QVBoxLayout* layout110_3_2;
    QVBoxLayout* layout24;
    QGridLayout* groupBox2Layout;
    QHBoxLayout* layout36;
    QVBoxLayout* layout28_2_2;
    QVBoxLayout* layout10;
    QVBoxLayout* layout46;
    QVBoxLayout* layout26;
    QVBoxLayout* layout46_2;
    QVBoxLayout* layout46_2_2;
    QHBoxLayout* layout27;
    QSpacerItem* spacer1;
    QVBoxLayout* layout110_2;
    QVBoxLayout* layout110_2_4;
    QVBoxLayout* layout110_2_2;
    QVBoxLayout* layout14;
    QVBoxLayout* layout16;
    QVBoxLayout* layout110_3;
    QVBoxLayout* layout11;

protected slots:
    virtual void languageChange();

};

#endif // COMPRAS_H
