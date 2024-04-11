/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaProductos.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAPRODUCTOS_H
#define CAPTURAPRODUCTOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QFrame;
class QLabel;
class QCtrlProveedoresSS;
class QLineEdit;
class QPushButton;
class QCtrlDepartamentosSS;
class QTable;

class CapturaProductos : public QWidget
{
    Q_OBJECT

public:
    CapturaProductos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CapturaProductos();

    QFrame* frame20;
    QLabel* textLabel2;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel3;
    QLineEdit* lineEdit83;
    QLabel* textLabel8;
    QLineEdit* lineEdit84;
    QPushButton* QPBCrear;
    QPushButton* QPBConsultar;
    QPushButton* QPBActualizar;
    QPushButton* QPBCancelar;
    QFrame* frame21;
    QLabel* textLabel1;
    QLineEdit* QLENumeroProducto;
    QLabel* textLabel4;
    QLineEdit* QLENombre;
    QLabel* textLabel5;
    QLineEdit* QLEModelo;
    QLabel* textLabel7;
    QCtrlDepartamentosSS* QCtrDepartamentos;
    QLabel* textLabel1_2;
    QTable* QTCostoBruto;
    QLabel* textLabel2_2;
    QTable* QTPrecioGeneral;
    QLabel* textLabel3_2;
    QTable* QTPrecioForaneo;
    QPushButton* QPBCCBruto;
    QPushButton* QPBCPGeneral;
    QPushButton* QPBCPForaneo;
    QPushButton* QPBCDescuento;
    QLabel* textLabel9;
    QTable* QTDescuento;

protected:
    QGridLayout* CapturaProductosLayout;
    QGridLayout* frame20Layout;
    QVBoxLayout* layout27;
    QVBoxLayout* layout26;
    QHBoxLayout* layout47;
    QVBoxLayout* layout38;
    QVBoxLayout* layout39;
    QHBoxLayout* layout176;
    QGridLayout* frame21Layout;
    QHBoxLayout* layout49;
    QVBoxLayout* layout40;
    QVBoxLayout* layout41;
    QVBoxLayout* layout42;
    QVBoxLayout* layout25;
    QVBoxLayout* layout59;
    QVBoxLayout* layout96;
    QVBoxLayout* layout98;
    QVBoxLayout* layout97;
    QVBoxLayout* layout35;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAPRODUCTOS_H
