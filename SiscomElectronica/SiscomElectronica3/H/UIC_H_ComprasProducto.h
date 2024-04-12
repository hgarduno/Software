/****************************************************************************
** Form interface generated from reading ui file 'UI/ComprasProducto.ui'
**
** Created: Thu Apr 11 21:39:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COMPRASPRODUCTO_H
#define COMPRASPRODUCTO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTextEdit;
class QTable;
class QLineEdit;
class QCtrlProdSiscomElectronica;
class CQControlFecha;

class ComprasProducto : public QWidget
{
    Q_OBJECT

public:
    ComprasProducto( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ComprasProducto();

    QPushButton* QPBHCompras;
    QPushButton* QPBRPorcentajes;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel3;
    QTable* QTDatos;
    QLabel* textLabel4;
    QLineEdit* QLEComprasSemAnterior;
    QLabel* textLabel4_2;
    QLineEdit* QTEVentasSemAnterior;
    QLabel* textLabel4_2_2;
    QLineEdit* QLEVentasActuales;
    QLabel* textLabel4_2_2_2;
    QLineEdit* QLEExistenciaA;
    QLabel* textLabel1;
    QCtrlProdSiscomElectronica* QCtrSis3QtProds;
    QLabel* textLabel1_2;
    CQControlFecha* QCtrFechaRefVentas;

protected:
    QGridLayout* ComprasProductoLayout;
    QHBoxLayout* layout4;
    QVBoxLayout* layout2;
    QVBoxLayout* layout9;
    QVBoxLayout* layout6;
    QVBoxLayout* layout6_2;
    QVBoxLayout* layout6_2_2;
    QVBoxLayout* layout6_2_2_2;
    QVBoxLayout* layout1;
    QHBoxLayout* layout10;
    QSpacerItem* spacer1;
    QVBoxLayout* layout9_2;

protected slots:
    virtual void languageChange();

};

#endif // COMPRASPRODUCTO_H
