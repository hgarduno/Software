/****************************************************************************
** Form interface generated from reading ui file 'UI/ManejadorOrden.ui'
**
** Created: Wed Jan 31 10:48:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MANEJADORORDEN_H
#define MANEJADORORDEN_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLCDNumber;
class QTextEdit;
class QLineEdit;
class QCtrlProductosSE;
class QTable;
class QPushButton;

class ManejadorOrden : public QWidget
{
    Q_OBJECT

public:
    ManejadorOrden( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ManejadorOrden();

    QLabel* textLabel5;
    QLCDNumber* QLCDNumPrecio;
    QLabel* textLabel5_2;
    QLCDNumber* QLCDNumTotalOrden;
    QLabel* textLabel1;
    QTextEdit* QTECliente;
    QLabel* textLabel1_3;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel3;
    QLineEdit* QLECantidad;
    QLabel* textLabel4;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel3_3;
    QLineEdit* QLEExistencia;
    QLabel* textLabel3_2;
    QLineEdit* QLEExiBodega;
    QTable* QTOrden;
    QLabel* textLabel2;
    QLabel* textLabel2_2;
    QLineEdit* QLEUbicacion;
    QPushButton* QPBNuevaOrden;
    QPushButton* QPBCargaCotizacion;
    QPushButton* QPBExExpendios;
    QPushButton* QPBDatosPedido;
    QPushButton* QPBAnexarOrden;
    QPushButton* QPBFaltante;
    QPushButton* QPBImprimePdf;
    QPushButton* QPBImprime;
    QPushButton* QPBRegistrar;

protected:
    QGridLayout* ManejadorOrdenLayout;
    QVBoxLayout* layout26;
    QHBoxLayout* layout16;
    QVBoxLayout* layout12;
    QVBoxLayout* layout12_2;
    QVBoxLayout* layout25;
    QVBoxLayout* layout19;
    QVBoxLayout* layout5_3;
    QHBoxLayout* layout28;
    QVBoxLayout* layout8;
    QVBoxLayout* layout26_2;
    QVBoxLayout* layout8_3;
    QVBoxLayout* layout8_2;
    QHBoxLayout* layout31;
    QHBoxLayout* LayoutBotones;

protected slots:
    virtual void languageChange();

};

#endif // MANEJADORORDEN_H
