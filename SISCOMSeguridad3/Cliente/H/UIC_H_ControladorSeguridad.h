/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_ControladorSeguridad.ui'
**
** Created: Sat Jan 27 16:42:49 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONTROLADORSEGURIDAD_H
#define CONTROLADORSEGURIDAD_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class QTable;

class ControladorSeguridad : public QWidget
{
    Q_OBJECT

public:
    ControladorSeguridad( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ControladorSeguridad();

    QGroupBox* groupBox12;
    QLabel* textLabel4_2;
    QComboBox* QCBPerfiles;
    QLabel* textLabel6_2;
    QLineEdit* QLEDscPerfil;
    QGroupBox* groupBox4_2;
    QLabel* textLabel4;
    QComboBox* QCBPantallas;
    QLabel* textLabel6;
    QLineEdit* QLEAPantalla;
    QLabel* textLabel5;
    QLineEdit* QLEIdPantalla;
    QPushButton* pushButton21;
    QGroupBox* groupBox5;
    QTable* QTDatosU;
    QGroupBox* groupBox4;
    QLabel* textLabel7;
    QLineEdit* QLEDirIpSvr;
    QLabel* textLabel7_2;
    QLineEdit* QLEUsuario;
    QLabel* textLabel7_2_2;
    QLineEdit* QLEPtoCom;
    QLabel* textLabel7_2_2_2;
    QLineEdit* QLEPassword;
    QGroupBox* groupBox2;
    QPushButton* QPBCapAplicacion;
    QPushButton* QPBCarAplicacion;
    QPushButton* QPBIniCom;
    QPushButton* QPBCreaFirma;
    QPushButton* QPBRegAplicacion;
    QPushButton* QPBCreaPerfil;
    QPushButton* QPBUsuarios;
    QPushButton* QPBActualizaP;
    QPushButton* QPBActAplicacion;
    QPushButton* QPBCopiaP_3;

protected:
    QGridLayout* ControladorSeguridadLayout;
    QGridLayout* groupBox12Layout;
    QVBoxLayout* layout17_2;
    QVBoxLayout* layout20_2;
    QGridLayout* groupBox4_2Layout;
    QHBoxLayout* layout18;
    QSpacerItem* spacer3;
    QVBoxLayout* layout17;
    QVBoxLayout* layout20;
    QHBoxLayout* layout21;
    QSpacerItem* spacer4;
    QVBoxLayout* layout19;
    QGridLayout* groupBox5Layout;
    QGridLayout* groupBox4Layout;
    QVBoxLayout* layout41;
    QVBoxLayout* layout41_2;
    QVBoxLayout* layout41_2_2;
    QVBoxLayout* layout41_2_2_2;
    QGridLayout* groupBox2Layout;
    QHBoxLayout* layout10;

protected slots:
    virtual void languageChange();

};

#endif // CONTROLADORSEGURIDAD_H
