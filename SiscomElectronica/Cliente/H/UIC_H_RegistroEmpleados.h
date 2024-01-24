/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroEmpleados.ui'
**
** Created: Thu Dec 21 13:56:28 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROEMPLEADOS_H
#define REGISTROEMPLEADOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;

class RegistroEmpleados : public QWidget
{
    Q_OBJECT

public:
    RegistroEmpleados( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroEmpleados();

    QLabel* textLabel8;
    QComboBox* QCBTelefonos;
    QLabel* textLabel8_2;
    QLineEdit* QLECElectronico;
    QLabel* textLabel8_3;
    QComboBox* QCBPerfiles;
    QLabel* textLabel3_5;
    QLineEdit* QLEFirma;
    QLabel* textLabel3_5_3;
    QLineEdit* QLEPassword;
    QLabel* textLabel3_5_2;
    QLineEdit* QLECPassword;
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
    QLabel* textLabel7;
    QLineEdit* QLERFC;
    QLabel* textLabel3;
    QLineEdit* QLENombre;
    QLabel* textLabel3_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel3_3;
    QLineEdit* QLEAMaterno;
    QPushButton* QPBModificar;
    QPushButton* QPBMDireccion;
    QLabel* textLabel4_3;
    QPushButton* QPBAETelefono;
    QPushButton* QPBMTelefono;
    QPushButton* QPBETelefono;
    QLabel* textLabel4_3_2;
    QPushButton* QPBACorreo;
    QPushButton* QPBMCorreo;
    QPushButton* QPBECorreo;
    QLabel* textLabel5_3;
    QPushButton* QPBSiguiente;
    QPushButton* QPBAnterior;
    QLabel* textLabel6_2;
    QPushButton* QPBERegistro;
    QPushButton* QPBETodo;
    QPushButton* QPBSiguiente_2_3_2;
    QPushButton* QPBSiguiente_2_2;
    QPushButton* QPBSExpendio;
    QPushButton* QPBREmpleado;
    QPushButton* QPBConsultaEmpleados;

protected:
    QGridLayout* RegistroEmpleadosLayout;
    QHBoxLayout* layout29;
    QVBoxLayout* layout27;
    QVBoxLayout* layout21_2;
    QHBoxLayout* layout186;
    QVBoxLayout* layout27_2;
    QVBoxLayout* layout6_5;
    QVBoxLayout* layout6_5_3;
    QVBoxLayout* layout6_5_2;
    QHBoxLayout* layout32;
    QVBoxLayout* layout6_4;
    QVBoxLayout* layout11_2;
    QVBoxLayout* layout11;
    QHBoxLayout* layout187;
    QSpacerItem* spacer18;
    QHBoxLayout* layout18;
    QVBoxLayout* layout14;
    QVBoxLayout* layout14_2;
    QVBoxLayout* layout17;
    QHBoxLayout* layout42;
    QSpacerItem* spacer9;
    QHBoxLayout* layout33;
    QVBoxLayout* layout19;
    QVBoxLayout* layout6;
    QVBoxLayout* layout6_2;
    QVBoxLayout* layout6_3;
    QHBoxLayout* layout108;
    QVBoxLayout* layout88;
    QHBoxLayout* layout87;
    QVBoxLayout* layout88_2;
    QHBoxLayout* layout87_2;
    QVBoxLayout* layout103;
    QHBoxLayout* layout102;
    QVBoxLayout* layout107;
    QHBoxLayout* layout106;
    QHBoxLayout* layout104;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROEMPLEADOS_H
