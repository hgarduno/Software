/****************************************************************************
** Form interface generated from reading ui file 'UI/ComprasImportaciones.ui'
**
** Created: Thu Dec 21 12:53:40 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COMPRASIMPORTACIONES_H
#define COMPRASIMPORTACIONES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProveedoresSE;
class QLineEdit;
class QCtrlProductosSE;
class QTable;
class QGroupBox;
class QLCDNumber;
class QPushButton;

class ComprasImportaciones : public QWidget
{
    Q_OBJECT

public:
    ComprasImportaciones( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ComprasImportaciones();

    QLabel* textLabel1_3;
    QCtrlProveedoresSE* QCtrProveedores;
    QLabel* textLabel1_6;
    QLineEdit* QLENumFactura;
    QLabel* textLabel1;
    QLineEdit* QLECostoEnvio;
    QLabel* textLabel1_2;
    QLineEdit* QLECostoDolar;
    QLabel* textLabel1_2_2;
    QLineEdit* QLECostoAdministrativo;
    QLabel* textLabel1_2_2_2;
    QLineEdit* QLENumPartidas;
    QLabel* textLabel3;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel1_7;
    QLineEdit* QLEFiltro;
    QLabel* textLabel1_4;
    QLineEdit* QLECantidad;
    QLabel* textLabel1_4_2;
    QLineEdit* QLECostoUnitario;
    QLabel* textLabel1_4_2_2;
    QLineEdit* QLEPeso;
    QLabel* textLabel1_4_3;
    QLineEdit* QLECostoGrEnvio;
    QLabel* textLabel1_8;
    QLineEdit* QLEDscCompra;
    QLabel* textLabel2;
    QTable* QTProductos;
    QGroupBox* groupBox2;
    QLabel* textLabel1_9;
    QLineEdit* QLEProveedor;
    QLabel* textLabel1_9_2;
    QLineEdit* QLECveProveedor;
    QGroupBox* groupBox1;
    QLabel* textLabel1_10;
    QLineEdit* QLECantidadUC;
    QLabel* textLabel1_10_2;
    QLineEdit* QLECostoUC;
    QLabel* textLabel2_2;
    QLineEdit* QLEFechaUC;
    QGroupBox* groupBox3;
    QLabel* textLabel1_11;
    QLineEdit* QLEBodega;
    QLabel* textLabel1_5;
    QLCDNumber* QLCNPesoCompra;
    QLabel* textLabel1_5_2;
    QLCDNumber* QLCDNImporteFactura;
    QLabel* textLabel1_5_3;
    QLCDNumber* QLCNCostoGrEnvio;
    QPushButton* QPBAnexar;
    QPushButton* QPBEliminar;
    QPushButton* QPBCargaCompraAProveedor;
    QPushButton* QPBCargaCompra;
    QPushButton* QPBGuardaCompra;
    QPushButton* QPBGuardaCompraComo;
    QPushButton* QPBActualizar;
    QPushButton* QPBProveedores;
    QPushButton* QPBOtroProveedor;
    QPushButton* QPBRegParProductos;
    QPushButton* QPBRegistraCompra;
    QPushButton* QPBBodegas;

protected:
    QGridLayout* ComprasImportacionesLayout;
    QVBoxLayout* layout63;
    QHBoxLayout* layout61;
    QVBoxLayout* layout25;
    QHBoxLayout* layout29;
    QVBoxLayout* layout1_4;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout1_2_2;
    QVBoxLayout* layout1_2_2_2;
    QHBoxLayout* layout62;
    QVBoxLayout* layout5;
    QHBoxLayout* layout30;
    QVBoxLayout* layout48;
    QVBoxLayout* layout1_3;
    QVBoxLayout* layout1_3_2;
    QVBoxLayout* layout1_3_2_2;
    QVBoxLayout* layout1_3_3;
    QVBoxLayout* layout27;
    QVBoxLayout* layout8;
    QGridLayout* groupBox2Layout;
    QHBoxLayout* layout30_2;
    QVBoxLayout* layout27_2;
    QVBoxLayout* layout27_2_2;
    QGridLayout* groupBox1Layout;
    QVBoxLayout* layout28;
    QVBoxLayout* layout28_2;
    QVBoxLayout* layout32;
    QGridLayout* groupBox3Layout;
    QVBoxLayout* layout32_2;
    QVBoxLayout* layout56;
    QVBoxLayout* layout21;
    QVBoxLayout* layout21_2;
    QVBoxLayout* layout21_3;
    QHBoxLayout* layout32_3;

protected slots:
    virtual void languageChange();

};

#endif // COMPRASIMPORTACIONES_H
