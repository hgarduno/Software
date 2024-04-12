/****************************************************************************
** Form interface generated from reading ui file 'UI/SeleccionaCliente.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SELECCIONACLIENTE_H
#define SELECCIONACLIENTE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlClientes3Qt;
class QCtrlContactos3Qt;
class QPushButton;
class QGroupBox;
class QLineEdit;
class QTextEdit;
class QTabWidget;
class QWidget;
class QTable;

class SeleccionaCliente : public QDialog
{
    Q_OBJECT

public:
    SeleccionaCliente( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SeleccionaCliente();

    QLabel* textLabel1_2;
    QCtrlClientes3Qt* QCtrClientes;
    QLabel* textLabel1_3;
    QCtrlContactos3Qt* QCtrContactos;
    QPushButton* QPBSCliente;
    QGroupBox* groupBox3;
    QLabel* textLabel6;
    QLineEdit* QLENombre;
    QLabel* textLabel6_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel6_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel8;
    QTextEdit* QTEDscContacto;
    QGroupBox* groupBox5;
    QLabel* textLabel2;
    QLineEdit* lineEdit14;
    QTabWidget* tabWidget2;
    QWidget* tab;
    QLabel* textLabel3;
    QTable* table4;
    QPushButton* QPBSCliente_2;
    QWidget* tab_2;
    QLabel* textLabel3_2;
    QTable* table4_2;
    QPushButton* QPBSCliente_2_2;

protected:
    QGridLayout* SeleccionaClienteLayout;
    QHBoxLayout* layout37;
    QVBoxLayout* layout2;
    QVBoxLayout* layout3;
    QGridLayout* groupBox3Layout;
    QHBoxLayout* layout23;
    QVBoxLayout* layout20;
    QVBoxLayout* layout20_2;
    QVBoxLayout* layout20_2_2;
    QVBoxLayout* layout26;
    QGridLayout* groupBox5Layout;
    QVBoxLayout* layout43;
    QGridLayout* tabLayout;
    QGridLayout* tabLayout_2;
    QVBoxLayout* layout44_2;

protected slots:
    virtual void languageChange();

};

#endif // SELECCIONACLIENTE_H
