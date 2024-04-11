/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/MantenimientoProductos.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MANTENIMIENTOPRODUCTOS_H
#define MANTENIMIENTOPRODUCTOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProveedoresSS;
class QLineEdit;
class QCtrlDepartamentosSS;
class QPushButton;
class QCtrlProductosSS;

class MantenimientoProductos : public QWidget
{
    Q_OBJECT

public:
    MantenimientoProductos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~MantenimientoProductos();

    QLabel* textLabel2;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel8;
    QLineEdit* QLERazonSocial;
    QLabel* textLabel5;
    QLineEdit* QLEModelo;
    QLabel* textLabel5_2_2;
    QLineEdit* QLEIva;
    QLabel* textLabel7;
    QCtrlDepartamentosSS* QCtrDepartamentos;
    QLabel* textLabel5_2;
    QLineEdit* QLECosto;
    QLabel* textLabel5_2_4;
    QLineEdit* QLECostoNeto;
    QPushButton* QPBRegistrar;
    QLabel* textLabel1_3;
    QLineEdit* QLEDescuento1;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEDescuento2;
    QLabel* textLabel1_3_2;
    QLineEdit* QLEDescuento3;
    QLabel* textLabel1_2_2_2;
    QLineEdit* QLEDescuento4;
    QLabel* textLabel4_2;
    QLineEdit* QLENombre;
    QLabel* textLabel1_2;
    QCtrlProductosSS* QCtrProductos;
    QLabel* textLabel5_2_3_2;
    QLineEdit* QLEPrecio;
    QLabel* textLabel5_2_3;
    QLineEdit* QLEPorUtilidadPrecio;
    QLabel* textLabel5_2_3_2_2;
    QLineEdit* QLEPrecioForaneo;
    QLabel* textLabel5_2_3_3;
    QLineEdit* QLEPorUtilidadForaneo;

protected:
    QGridLayout* MantenimientoProductosLayout;
    QHBoxLayout* layout65;
    QVBoxLayout* layout26;
    QHBoxLayout* layout47;
    QVBoxLayout* layout39;
    QVBoxLayout* layout42;
    QVBoxLayout* layout42_2_2;
    QVBoxLayout* layout25;
    QVBoxLayout* layout42_2;
    QVBoxLayout* layout42_2_4;
    QHBoxLayout* layout33;
    QVBoxLayout* layout28;
    QVBoxLayout* layout28_2;
    QVBoxLayout* layout28_3;
    QVBoxLayout* layout28_2_2;
    QVBoxLayout* layout41_2;
    QVBoxLayout* layout23;
    QHBoxLayout* layout29;
    QSpacerItem* spacer1;
    QVBoxLayout* layout42_2_3_2;
    QVBoxLayout* layout42_2_3;
    QVBoxLayout* layout42_2_3_2_2;
    QVBoxLayout* layout42_2_3_3;

protected slots:
    virtual void languageChange();

};

#endif // MANTENIMIENTOPRODUCTOS_H
