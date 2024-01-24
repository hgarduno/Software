/****************************************************************************
** Form interface generated from reading ui file 'UI/OrdenCompras.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENCOMPRAS_H
#define ORDENCOMPRAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QGroupBox;
class QPushButton;
class QTextEdit;
class QTable;

class OrdenCompras : public QWidget
{
    Q_OBJECT

public:
    OrdenCompras( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~OrdenCompras();

    QLabel* textLabel1;
    QComboBox* QCBProductos;
    QLabel* textLabel4_2_3_2;
    QLineEdit* QLEPrecioVenta;
    QGroupBox* groupBox1;
    QLabel* textLabel4;
    QLineEdit* QLEComSemAnterior;
    QLabel* textLabel4_2;
    QLineEdit* QLEVenSemAnterior;
    QGroupBox* groupBox1_2;
    QLabel* textLabel4_3;
    QLineEdit* QLEComSemActual;
    QLabel* textLabel4_2_2;
    QLineEdit* QLEVenSemActual;
    QGroupBox* groupBox1_3;
    QLabel* textLabel4_4;
    QLineEdit* QLEExistencia;
    QLabel* textLabel4_2_3;
    QLineEdit* QLEExBodega;
    QLabel* textLabel4_2_3_3;
    QLineEdit* QLETransferencias;
    QPushButton* QPBProductosFaltantes;
    QPushButton* pushButton1_2;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel5;
    QTable* QTOrdenCompra;
    QLabel* textLabel3;
    QTable* QTDatos;
    QLabel* textLabel3_2;
    QTable* QTTransferencias;

protected:
    QGridLayout* OrdenComprasLayout;
    QHBoxLayout* layout29;
    QVBoxLayout* layout1;
    QVBoxLayout* layout3_2_3_2;
    QGridLayout* groupBox1Layout;
    QHBoxLayout* layout5;
    QVBoxLayout* layout3;
    QVBoxLayout* layout3_2;
    QGridLayout* groupBox1_2Layout;
    QHBoxLayout* layout5_2;
    QVBoxLayout* layout3_3;
    QVBoxLayout* layout3_2_2;
    QGridLayout* groupBox1_3Layout;
    QVBoxLayout* layout3_4;
    QVBoxLayout* layout3_2_3;
    QVBoxLayout* layout3_2_3_3;
    QHBoxLayout* layout19;
    QVBoxLayout* layout2;
    QVBoxLayout* layout32;
    QHBoxLayout* layout34;
    QVBoxLayout* layout12;
    QVBoxLayout* layout12_2;

protected slots:
    virtual void languageChange();

};

#endif // ORDENCOMPRAS_H
