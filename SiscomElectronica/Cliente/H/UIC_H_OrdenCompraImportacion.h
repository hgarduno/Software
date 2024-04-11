/****************************************************************************
** Form interface generated from reading ui file 'UI/OrdenCompraImportacion.ui'
**
** Created: Wed Apr 10 20:52:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENCOMPRAIMPORTACION_H
#define ORDENCOMPRAIMPORTACION_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QCtrlProveedoresSE;
class QCtrlProductosSE;
class QLineEdit;
class QTextEdit;
class QLCDNumber;
class QPushButton;
class QTable;

class OrdenCompraImportacion : public QWidget
{
    Q_OBJECT

public:
    OrdenCompraImportacion( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~OrdenCompraImportacion();

    QGroupBox* groupBox1;
    QLabel* textLabel1;
    QCtrlProveedoresSE* QCtrProveedores;
    QLabel* textLabel2;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel1_2_2_3_3_2;
    QLineEdit* QLECantidadC;
    QLabel* textLabel1_2_2_3_3_2_2;
    QLineEdit* QLEPrecio;
    QLabel* textLabel1_2_2_3_3;
    QLineEdit* QLECveProductoProveedor;
    QLabel* textLabel1_2_2_3_2;
    QLineEdit* QLEPeso;
    QTextEdit* QTEDescripcionP;
    QLabel* textLabel4_3_2;
    QLCDNumber* QLCDImporte;
    QLabel* textLabel4_3;
    QLCDNumber* QLCDPeso;
    QGroupBox* groupBox2;
    QPushButton* pushButton4;
    QLabel* textLabel1_2;
    QLineEdit* QLEFecha;
    QLabel* textLabel1_2_2;
    QLineEdit* QLECantidad;
    QLabel* textLabel1_2_2_2;
    QLineEdit* QLECosto;
    QLabel* textLabel1_2_2_2_2;
    QLineEdit* QLECostoTotal;
    QTable* table4;
    QPushButton* QPBAnexar;
    QPushButton* QPBEliminar;
    QPushButton* pushButton5_2_2;
    QPushButton* pushButton5_2_3;
    QPushButton* pushButton5_2_3_2;
    QLabel* textLabel3;
    QTable* table2;
    QLabel* textLabel4_2;
    QLCDNumber* QLCDImportTotal;
    QLabel* textLabel4;
    QLCDNumber* QLCDPesoTotal;

protected:
    QGridLayout* OrdenCompraImportacionLayout;
    QGridLayout* groupBox1Layout;
    QVBoxLayout* layout55;
    QVBoxLayout* layout9;
    QVBoxLayout* layout15;
    QHBoxLayout* layout54;
    QVBoxLayout* layout19_2_3_3_2;
    QVBoxLayout* layout19_2_3_3_2_2;
    QHBoxLayout* layout53;
    QVBoxLayout* layout19_2_3_3;
    QVBoxLayout* layout19_2_3_2;
    QVBoxLayout* layout58;
    QVBoxLayout* layout56_2;
    QVBoxLayout* layout56;
    QGridLayout* groupBox2Layout;
    QHBoxLayout* layout34;
    QVBoxLayout* layout19;
    QVBoxLayout* layout19_2;
    QVBoxLayout* layout19_2_2;
    QVBoxLayout* layout19_2_2_2;
    QHBoxLayout* layout30;
    QHBoxLayout* layout32;
    QVBoxLayout* layout27;
    QVBoxLayout* layout33;
    QVBoxLayout* layout31_2;
    QVBoxLayout* layout31;

protected slots:
    virtual void languageChange();

};

#endif // ORDENCOMPRAIMPORTACION_H
