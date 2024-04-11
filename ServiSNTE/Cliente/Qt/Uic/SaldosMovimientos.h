/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/SaldosMovimientos.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SALDOSMOVIMIENTOS_H
#define SALDOSMOVIMIENTOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlTiendasEntrega;
class QCtrlProveedoresSS;
class QCtrlProductosSS;
class QPushButton;
class QTabWidget;
class QCtrlStock;
class QLineEdit;
class QCtrlExistenciaProveedor;
class QCtrlSaldosMovimientosMes;
class QCtrlConceptosSaldosMovimientos;

class SaldosMovimientos : public QWidget
{
    Q_OBJECT

public:
    SaldosMovimientos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SaldosMovimientos();

    QLabel* Tienda;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel2;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel1_2_3;
    QCtrlProductosSS* QCtrProductos;
    QPushButton* pushButton4;
    QTabWidget* QTWInformacion;
    QWidget* tab;
    QCtrlStock* QCtrStock;
    QWidget* tab_2;
    QLabel* textLabel2_3;
    QLineEdit* QLEStockTotal;
    QLabel* textLabel2_3_2;
    QLineEdit* QLEExistenciaTotal;
    QCtrlExistenciaProveedor* QCtrExistenciaProveedor;
    QCtrlSaldosMovimientosMes* QCtrSaldosMovimientosMes;
    QLabel* textLabel1;
    QCtrlConceptosSaldosMovimientos* QCtrConceptosSaldosMovimientos;

protected:
    QGridLayout* SaldosMovimientosLayout;
    QHBoxLayout* layout8;
    QVBoxLayout* layout56;
    QVBoxLayout* layout57;
    QVBoxLayout* layout7;
    QGridLayout* tabLayout;
    QGridLayout* tabLayout_2;
    QHBoxLayout* layout9;
    QHBoxLayout* layout9_2;
    QVBoxLayout* layout8_2;

protected slots:
    virtual void languageChange();

};

#endif // SALDOSMOVIMIENTOS_H
