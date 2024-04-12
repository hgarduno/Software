/****************************************************************************
** Form interface generated from reading ui file 'UI/Facturando3.ui'
**
** Created: Thu Apr 11 21:39:51 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FACTURANDO3_H
#define FACTURANDO3_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTabWidget;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;
class QLCDNumber;

class Facturando3 : public QWidget
{
    Q_OBJECT

public:
    Facturando3( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Facturando3();

    QTabWidget* QTWTipoCliente;
    QWidget* tab;
    QLabel* textLabel1_2;
    QLineEdit* QLENombre;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel1_2_2_2;
    QLineEdit* QLEAMaterno;
    QWidget* tab_2;
    QLabel* textLabel1_2_5;
    QLineEdit* QLERazonSocial;
    QLabel* textLabel1_2_2_2_3;
    QLineEdit* QLERFC;
    QLabel* textLabel1;
    QTable* QTDatos;
    QLabel* textLabel1_2_3;
    QLineEdit* QLECalle;
    QLabel* textLabel1_2_3_2;
    QLineEdit* QLENumero;
    QLabel* textLabel1_2_3_2_2;
    QLineEdit* QLEColonia;
    QLabel* textLabel1_2_3_2_2_3;
    QLineEdit* QLECP;
    QLabel* textLabel1_2_3_2_2_2;
    QLineEdit* QLEDelMun;
    QLabel* textLabel1_2_3_2_2_2_2;
    QLineEdit* QLEEstado;
    QPushButton* QPBAnexarFactura_2;
    QPushButton* QPBAnexarOrden;
    QPushButton* QPBCliente;
    QPushButton* QPBImpFactura;
    QLabel* textLabel2;
    QLCDNumber* QLCNTotal;
    QLabel* textLabel2_2;
    QLCDNumber* QLCDNTotalMIVA;
    QLabel* textLabel2_3;
    QLCDNumber* QLCNIVA;
    QLabel* textLabel1_3;
    QLineEdit* QLETelefono;
    QLabel* textLabel1_3_2;
    QLineEdit* QLECorreo;

protected:
    QGridLayout* Facturando3Layout;
    QHBoxLayout* layout46;
    QGridLayout* tabLayout;
    QHBoxLayout* layout20;
    QVBoxLayout* layout6;
    QVBoxLayout* layout6_2;
    QVBoxLayout* layout6_2_2;
    QHBoxLayout* tabLayout_2;
    QVBoxLayout* layout6_5;
    QVBoxLayout* layout44;
    QSpacerItem* spacer1;
    QVBoxLayout* layout6_2_2_3;
    QVBoxLayout* layout41;
    QVBoxLayout* layout42;
    QHBoxLayout* layout21;
    QVBoxLayout* layout6_3;
    QVBoxLayout* layout6_3_2;
    QVBoxLayout* layout6_3_2_2;
    QVBoxLayout* layout6_3_2_2_3;
    QHBoxLayout* layout22;
    QVBoxLayout* layout6_3_2_2_2;
    QVBoxLayout* layout6_3_2_2_2_2;
    QHBoxLayout* layout41_2;
    QGridLayout* layout25;
    QHBoxLayout* layout39;
    QVBoxLayout* layout23;
    QVBoxLayout* layout23_2;
    QVBoxLayout* layout23_3;
    QVBoxLayout* layout19;
    QVBoxLayout* layout19_2;

protected slots:
    virtual void languageChange();

};

#endif // FACTURANDO3_H
