/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaDatosComplementarios.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURADATOSCOMPLEMENTARIOS_H
#define CAPTURADATOSCOMPLEMENTARIOS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QTabWidget;
class QWidget;
class QButtonGroup;
class QLabel;
class QRadioButton;
class QLineEdit;
class QTable;

class CapturaDatosComplementarios : public QDialog
{
    Q_OBJECT

public:
    CapturaDatosComplementarios( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaDatosComplementarios();

    QPushButton* QPBAceptar;
    QPushButton* QPBRegistrar;
    QPushButton* QPBCancelar;
    QTabWidget* QTWComplementarios;
    QWidget* tab;
    QButtonGroup* QGBCargoPublico;
    QLabel* textLabel2_2;
    QRadioButton* QRBCPublicoSi;
    QRadioButton* QRBCPublicoNo;
    QLabel* textLabel1_4_6;
    QLineEdit* QLEEspecifica;
    QLabel* textLabel1_4_4_5;
    QLineEdit* QLEDependencia;
    QLabel* textLabel1_4_4_2_2;
    QLineEdit* QLEPuesto;
    QLabel* textLabel1_4_4_3_2;
    QLineEdit* QLEFunciones;
    QLabel* textLabel1_4_4_4_2;
    QLineEdit* QLEPeriodo;
    QWidget* TabPage;
    QButtonGroup* QGBBeneficios;
    QLabel* textLabel2_2_2;
    QRadioButton* radioButton2_3_2_2;
    QRadioButton* radioButton2_2_2_2_2;
    QLabel* textLabel3_2;
    QLineEdit* QLENombreBeneficiado;
    QButtonGroup* QGBAportaTercero;
    QLabel* textLabel2_2_2_2;
    QRadioButton* radioButton2_3_2_2_2;
    QRadioButton* radioButton2_2_2_2_2_2;
    QLabel* textLabel3_2_2;
    QLineEdit* QLEAportaTercero;
    QWidget* TabPage_2;
    QTable* QTReferencias;
    QLabel* textLabel6;
    QLineEdit* QLECalle;
    QLabel* textLabel5;
    QLineEdit* QLENoExterior;
    QLabel* textLabel5_2;
    QLineEdit* QLENoInterior;
    QLabel* textLabel3;
    QLineEdit* QLEApellidoPaterno;
    QLabel* textLabel3_2_3;
    QLineEdit* QLEApellidoMaterno;
    QLabel* textLabel4;
    QLineEdit* QLENombres;
    QLabel* textLabel6_2;
    QLineEdit* QLEColonia;
    QLabel* textLabel6_2_2;
    QLineEdit* QLEDelegacionMunicipio;
    QLabel* textLabel5_2_2;
    QLineEdit* QLEEstado;
    QLabel* textLabel5_2_2_2;
    QLineEdit* QLECodigoPostal;
    QPushButton* QPBAgregaReferencia;
    QLabel* textLabel3_3_2;
    QLineEdit* QLETelefono;
    QLabel* textLabel3_3;
    QLineEdit* QLEParentesco;

protected:
    QGridLayout* CapturaDatosComplementariosLayout;
    QHBoxLayout* layout12;
    QGridLayout* tabLayout;
    QSpacerItem* spacer1;
    QVBoxLayout* layout71;
    QHBoxLayout* QGBCargoPublicoLayout;
    QVBoxLayout* layout6;
    QHBoxLayout* layout17;
    QVBoxLayout* layout6_3_5;
    QVBoxLayout* layout6_3_2_2;
    QHBoxLayout* layout18;
    QVBoxLayout* layout6_3_3_2;
    QVBoxLayout* layout6_3_4_2;
    QGridLayout* TabPageLayout;
    QSpacerItem* spacer2;
    QVBoxLayout* layout72;
    QHBoxLayout* QGBBeneficiosLayout;
    QVBoxLayout* layout30_2;
    QHBoxLayout* QGBAportaTerceroLayout;
    QVBoxLayout* layout30_2_2;
    QGridLayout* TabPageLayout_2;
    QHBoxLayout* layout25;
    QVBoxLayout* layout22;
    QVBoxLayout* layout16;
    QVBoxLayout* layout16_2;
    QHBoxLayout* layout87;
    QVBoxLayout* layout81;
    QVBoxLayout* layout83;
    QVBoxLayout* layout84;
    QHBoxLayout* layout36;
    QVBoxLayout* layout22_2;
    QVBoxLayout* layout22_2_2;
    QVBoxLayout* layout16_2_2;
    QVBoxLayout* layout16_2_2_2;
    QVBoxLayout* layout81_2_2;
    QVBoxLayout* layout92;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURADATOSCOMPLEMENTARIOS_H
