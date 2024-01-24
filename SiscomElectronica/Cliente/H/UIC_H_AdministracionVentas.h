/****************************************************************************
** Form interface generated from reading ui file 'UI/AdministracionVentas.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ADMINISTRACIONVENTAS_H
#define ADMINISTRACIONVENTAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCtrlProductosSE;
class QTextEdit;
class QLCDNumber;
class QPushButton;
class QTable;

class AdministracionVentas : public QWidget
{
    Q_OBJECT

public:
    AdministracionVentas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~AdministracionVentas();

    QLabel* textLabel1;
    QLineEdit* QLECantidad;
    QLabel* textLabel2;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel1_3_2;
    QLineEdit* QLEExistencia;
    QLabel* textLabel1_3_2_2;
    QLineEdit* QLEExistenciaBodega;
    QLabel* textLabel3;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel2_3;
    QLCDNumber* QLCDPrecio;
    QPushButton* QPBNuevaOrden;
    QPushButton* QPBNuevaOrden_2;
    QLabel* textLabel1_2;
    QTable* QTOrden;
    QLabel* textLabel2_2;
    QLCDNumber* QLCNImporteOrden;
    QPushButton* QPBAnexarOrden;
    QPushButton* QPBAnexarOrden_2;
    QPushButton* QPBAnexarOrden_3;

protected:
    QGridLayout* AdministracionVentasLayout;
    QVBoxLayout* layout36;
    QHBoxLayout* layout4;
    QVBoxLayout* layout2;
    QVBoxLayout* layout3;
    QHBoxLayout* layout28;
    QVBoxLayout* layout25_2;
    QVBoxLayout* layout25_2_2;
    QVBoxLayout* layout17;
    QVBoxLayout* layout35;
    QHBoxLayout* layout19;
    QHBoxLayout* layout21;
    QVBoxLayout* layout7;
    QVBoxLayout* layout20;
    QVBoxLayout* layout14;
    QVBoxLayout* layout34;
    QHBoxLayout* layout33;

protected slots:
    virtual void languageChange();

};

#endif // ADMINISTRACIONVENTAS_H
