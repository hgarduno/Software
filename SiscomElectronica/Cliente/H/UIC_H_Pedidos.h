/****************************************************************************
** Form interface generated from reading ui file 'UI/Pedidos.ui'
**
** Created: Thu Dec 21 12:53:40 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PEDIDOS_H
#define PEDIDOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QCtrlProductosSE;
class QTable;
class QLCDNumber;
class QTextEdit;

class Pedidos : public QWidget
{
    Q_OBJECT

public:
    Pedidos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Pedidos();

    QPushButton* QPBDatosCliente;
    QPushButton* pushButton3_2;
    QPushButton* QPBAnexarOrden;
    QLabel* textLabel3;
    QLineEdit* QLECantidad;
    QLabel* textLabel4;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel3_3;
    QLineEdit* QLEExistencia;
    QLabel* textLabel3_2;
    QLineEdit* QLEExiBodega;
    QLabel* textLabel2;
    QTable* QTOrden;
    QPushButton* QPBRegistrar;
    QLabel* textLabel5;
    QLCDNumber* QLCDNumPrecio;
    QLabel* textLabel5_2;
    QLCDNumber* QLCDNumTotalOrden;
    QLabel* textLabel1;
    QTextEdit* QTECliente;
    QLabel* textLabel1_2;
    QTextEdit* textEdit2_2;
    QLabel* textLabel1_3;
    QTextEdit* QTEDescripcion;

protected:
    QGridLayout* PedidosLayout;
    QVBoxLayout* layout20;
    QHBoxLayout* layout24;
    QVBoxLayout* layout8;
    QVBoxLayout* layout9;
    QVBoxLayout* layout8_3;
    QVBoxLayout* layout8_2;
    QVBoxLayout* layout7;
    QVBoxLayout* layout22;
    QHBoxLayout* layout16;
    QVBoxLayout* layout12;
    QVBoxLayout* layout12_2;
    QVBoxLayout* layout19;
    QVBoxLayout* layout5_2;
    QVBoxLayout* layout5_3;

protected slots:
    virtual void languageChange();

};

#endif // PEDIDOS_H