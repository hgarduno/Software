/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaDatosEmpleo.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADATOSEMPLEO_H
#define CAPTURADATOSEMPLEO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QLineEdit;
class QCtrlFrecuenciaPagosSS;
class QPushButton;

class CapturaDatosEmpleo : public QDialog
{
    Q_OBJECT

public:
    CapturaDatosEmpleo( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDatosEmpleo();

    QGroupBox* groupBox1_2;
    QLabel* textLabel6_4;
    QLineEdit* QLECalle;
    QLabel* textLabel5_4;
    QLineEdit* QLENoExterior;
    QLabel* textLabel5_2_4;
    QLineEdit* QLENoInterior;
    QLabel* textLabel6_2_4;
    QLineEdit* QLEColonia;
    QLabel* textLabel6_2_2_3;
    QLineEdit* QLEDelegacionMunicipio;
    QLabel* textLabel5_2_2_4;
    QLineEdit* QLEEstado;
    QLabel* textLabel5_2_2_2_3;
    QLineEdit* QLECodigoPostal;
    QLabel* textLabel1_2_5;
    QLineEdit* QLEPais;
    QLabel* textLabel1_2_5_2;
    QLineEdit* QLETelefono;
    QLabel* textLabel1_2_5_3;
    QLineEdit* QLEExtension;
    QLabel* textLabel1_2_5_4;
    QLineEdit* QLECorreoElectronico;
    QGroupBox* groupBox1_2_2;
    QLabel* textLabel1_2_5_5_3;
    QLineEdit* QLEOtrosIngresos;
    QLabel* textLabel1_2_5_5_3_2;
    QLineEdit* QLEEspecificacionIngresos;
    QLabel* textLabel1_2_5_5_3_3;
    QLineEdit* QLETotalIngresos;
    QLabel* textLabel1_2_5_5;
    QLineEdit* QLESueldo;
    QLabel* textLabel1_2_5_5_2;
    QCtrlFrecuenciaPagosSS* QCtrFrecuenciaPago;
    QGroupBox* groupBox1;
    QLabel* textLabel1;
    QLineEdit* QLENombreEmpresa;
    QLabel* textLabel1_2;
    QLineEdit* QLEAntiguedad;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEPuesto;
    QLabel* textLabel1_2_3;
    QLineEdit* QLEActGiroEmpresa;
    QGroupBox* groupBox6;
    QLabel* textLabel1_2_4;
    QLineEdit* QLENombre;
    QLabel* textLabel1_2_4_3;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel1_2_4_2;
    QLineEdit* QLEAMaterno;
    QPushButton* QPBRegistrar;
    QPushButton* QPBActualizar;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* CapturaDatosEmpleoLayout;
    QGridLayout* groupBox1_2Layout;
    QHBoxLayout* layout25;
    QVBoxLayout* layout22_4;
    QVBoxLayout* layout16_4;
    QVBoxLayout* layout16_2_4;
    QHBoxLayout* layout36;
    QVBoxLayout* layout22_2_4;
    QVBoxLayout* layout22_2_2_3;
    QVBoxLayout* layout16_2_2_4;
    QVBoxLayout* layout16_2_2_2_3;
    QHBoxLayout* layout22;
    QVBoxLayout* layout2_2_5;
    QVBoxLayout* layout2_2_5_2;
    QVBoxLayout* layout2_2_5_3;
    QVBoxLayout* layout2_2_5_4;
    QGridLayout* groupBox1_2_2Layout;
    QHBoxLayout* layout31;
    QVBoxLayout* layout2_2_5_5_2;
    QVBoxLayout* layout2_2_5_5_2_2;
    QVBoxLayout* layout2_2_5_5_2_3;
    QVBoxLayout* layout2_2_5_5;
    QVBoxLayout* layout30;
    QGridLayout* groupBox1Layout;
    QHBoxLayout* layout6;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;
    QVBoxLayout* layout2_2_2;
    QVBoxLayout* layout2_2_3;
    QGridLayout* groupBox6Layout;
    QVBoxLayout* layout96;
    QVBoxLayout* layout96_3;
    QVBoxLayout* layout96_2;
    QHBoxLayout* layout30_2;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADATOSEMPLEO_H
