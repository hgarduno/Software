/****************************************************************************
** Form interface generated from reading ui file 'UI/CNSClientes.ui'
**
** Created: Fri Apr 12 21:34:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CNSCLIENTES_H
#define CNSCLIENTES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class QCtrlEscuelas;

class CNSClientes : public QDialog
{
    Q_OBJECT

public:
    CNSClientes( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CNSClientes();

    QLabel* textLabel1;
    QComboBox* QCBRFC;
    QLabel* textLabel4_2;
    QLineEdit* QLECliente;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel4;
    QLineEdit* lineEdit10;
    QLabel* textLabel2;
    QLineEdit* QLENombre;
    QLabel* textLabel2_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel2_3;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel1_2;
    QCtrlEscuelas* QCtrEscuelas;

protected:
    QGridLayout* CNSClientesLayout;
    QSpacerItem* spacer2;
    QVBoxLayout* layout11;
    QVBoxLayout* layout18;
    QVBoxLayout* layout15_2;
    QHBoxLayout* layout16;
    QVBoxLayout* layout15;
    QHBoxLayout* layout9;
    QVBoxLayout* layout12;
    QVBoxLayout* layout12_2;
    QVBoxLayout* layout12_3;
    QVBoxLayout* layout10;

protected slots:
    virtual void languageChange();

};

#endif // CNSCLIENTES_H
