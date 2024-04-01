/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaClientes.ui'
**
** Created: Wed Jan 31 10:48:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURACLIENTES_H
#define CAPTURACLIENTES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QTabWidget;
class QWidget;
class QLineEdit;
class QPushButton;

class CapturaClientes : public QDialog
{
    Q_OBJECT

public:
    CapturaClientes( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaClientes();

    QLabel* textLabel2;
    QComboBox* QCBRFC;
    QTabWidget* QTWTipoCliente;
    QWidget* tab;
    QLabel* textLabel6;
    QLineEdit* QLENombre;
    QLabel* textLabel6_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel6_2_2;
    QLineEdit* QLEAMaterno;
    QWidget* tab_2;
    QLabel* textLabel5;
    QLineEdit* QLERazonSocial;
    QLabel* textLabel1_2_2_2_3;
    QLineEdit* QLERFC;
    QPushButton* QPBAceptar;
    QPushButton* QPBNCliente;
    QPushButton* QPBRCliente;
    QPushButton* pushButton7_2_2;
    QLabel* textLabel1_2_3_2_2_2;
    QLineEdit* QLEDelMun;
    QLabel* textLabel1_2_3_2_2_2_2;
    QLineEdit* QLEEstado;
    QLabel* textLabel1_2_3_2;
    QLineEdit* QLECalle;
    QLabel* textLabel1_2_3_2_2;
    QLineEdit* QLENumero;
    QLabel* textLabel1_2_3_2_2_3;
    QLineEdit* QLEColonia;
    QLabel* textLabel1_2_3_2_2_3_2;
    QLineEdit* QLECP;
    QLabel* textLabel1;
    QLineEdit* QLETelefono;
    QLabel* textLabel1_2;
    QLineEdit* QLECorreoE;

protected:
    QGridLayout* CapturaClientesLayout;
    QVBoxLayout* layout48;
    QHBoxLayout* layout98;
    QGridLayout* tabLayout;
    QVBoxLayout* layout95;
    QVBoxLayout* layout95_2;
    QVBoxLayout* layout95_2_2;
    QGridLayout* tabLayout_2;
    QVBoxLayout* layout94;
    QVBoxLayout* layout44;
    QSpacerItem* spacer1;
    QVBoxLayout* layout6_2_2_3;
    QHBoxLayout* layout18;
    QHBoxLayout* layout22;
    QVBoxLayout* layout6_3_2_2_2;
    QVBoxLayout* layout6_3_2_2_2_2;
    QHBoxLayout* layout21;
    QVBoxLayout* layout6_3_2;
    QVBoxLayout* layout6_3_2_2;
    QVBoxLayout* layout6_3_2_2_3;
    QVBoxLayout* layout6_3_2_2_3_2;
    QVBoxLayout* layout19;
    QVBoxLayout* layout19_2;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURACLIENTES_H
