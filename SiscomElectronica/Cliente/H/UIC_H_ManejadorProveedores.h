/****************************************************************************
** Form interface generated from reading ui file 'UI/ManejadorProveedores.ui'
**
** Created: Fri Apr 12 21:35:43 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MANEJADORPROVEEDORES_H
#define MANEJADORPROVEEDORES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;
class QComboBox;

class ManejadorProveedores : public QWidget
{
    Q_OBJECT

public:
    ManejadorProveedores( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ManejadorProveedores();

    QLabel* textLabel18;
    QLineEdit* QLERazonSocial;
    QLabel* textLabel7;
    QLineEdit* QLERFC;
    QLabel* textLabel19;
    QLabel* textLabel19_2;
    QTable* QTDirecciones;
    QLabel* textLabel20_2;
    QTable* QTTelefonos;
    QLabel* textLabel20;
    QTable* QTContactos;
    QPushButton* QPBAnexarDireccion;
    QPushButton* QPBAnexarTelefono;
    QPushButton* QPBAnexarContacto;
    QLabel* textLabel3_4;
    QLineEdit* QLECalle;
    QLabel* textLabel4_2;
    QLineEdit* QLENumero;
    QLabel* textLabel4;
    QLineEdit* QLECP;
    QLabel* textLabel5;
    QLineEdit* QLEColonia;
    QLabel* textLabel5_2;
    QLineEdit* QLEMunicipio;
    QLabel* textLabel6;
    QComboBox* QCBEstados;
    QPushButton* QPBRProveedor;
    QPushButton* QPBCnsProveedor;
    QPushButton* QPBMDatos;
    QPushButton* QPBCnsProveedor_2_2;

protected:
    QGridLayout* ManejadorProveedoresLayout;
    QSpacerItem* spacer15;
    QVBoxLayout* layout121;
    QVBoxLayout* layout19;
    QVBoxLayout* layout138;
    QHBoxLayout* layout140;
    QVBoxLayout* layout136;
    QVBoxLayout* layout137;
    QVBoxLayout* layout146;
    QSpacerItem* spacer8_3;
    QVBoxLayout* layout141;
    QVBoxLayout* layout36;
    QHBoxLayout* layout32;
    QVBoxLayout* layout6_4;
    QVBoxLayout* layout11_2;
    QVBoxLayout* layout11;
    QHBoxLayout* layout18;
    QVBoxLayout* layout14;
    QVBoxLayout* layout14_2;
    QVBoxLayout* layout17;
    QVBoxLayout* layout27;
    QSpacerItem* spacer12;
    QHBoxLayout* layout25;
    QHBoxLayout* layout26;

protected slots:
    virtual void languageChange();

};

#endif // MANEJADORPROVEEDORES_H
