/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroEmpresa.ui'
**
** Created: Sun Feb 9 03:08:48 2020
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROEMPRESA_H
#define REGISTROEMPRESA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QButtonGroup;
class QRadioButton;
class QPushButton;
class QToolBox;
class QTabWidget;
class QSisSepomex;
class QGroupBox;
class QTextEdit;
class QCtrlMedComunicacion;
class QTable;

class RegistroEmpresa : public QWidget
{
    Q_OBJECT

public:
    RegistroEmpresa( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroEmpresa();

    QLabel* textLabel5;
    QLineEdit* QLERSocial;
    QButtonGroup* QBGTipo;
    QRadioButton* radioButton2;
    QRadioButton* radioButton1;
    QRadioButton* radioButton3;
    QPushButton* QPBRegistrar;
    QToolBox* QTBEmpresas;
    QWidget* page1;
    QTabWidget* tabWidget2;
    QWidget* tab;
    QSisSepomex* QCtrSepomex;
    QWidget* tab_2;
    QGroupBox* groupBox3;
    QLabel* textLabel6;
    QLineEdit* QLENombre;
    QLabel* textLabel6_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel6_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel8;
    QTextEdit* QTEDscContacto;
    QWidget* TabPage;
    QGroupBox* groupBox4;
    QLabel* textLabel1_3;
    QCtrlMedComunicacion* QCtrMedCom;
    QLabel* textLabel1;
    QLineEdit* QLEMedio;
    QLabel* textLabel8_2;
    QTextEdit* QTEDscTelefono;
    QWidget* page2;
    QLabel* textLabel3;
    QTable* QTDirecciones;
    QLabel* textLabel3_2;
    QTable* QTContactos;
    QLabel* textLabel3_2_2;
    QTable* QTMedCom;
    QWidget* page;
    QWidget* page_2;
    QWidget* page_3;

protected:
    QGridLayout* RegistroEmpresaLayout;
    QVBoxLayout* layout19;
    QHBoxLayout* layout12;
    QGridLayout* QBGTipoLayout;
    QHBoxLayout* layout33;
    QGridLayout* page1Layout;
    QGridLayout* tabLayout;
    QSpacerItem* spacer4;
    QGridLayout* tabLayout_2;
    QGridLayout* groupBox3Layout;
    QHBoxLayout* layout23;
    QVBoxLayout* layout20;
    QVBoxLayout* layout20_2;
    QVBoxLayout* layout20_2_2;
    QVBoxLayout* layout26;
    QGridLayout* TabPageLayout;
    QGridLayout* groupBox4Layout;
    QHBoxLayout* layout20_3;
    QVBoxLayout* layout11;
    QVBoxLayout* layout19_2;
    QSpacerItem* spacer2;
    QVBoxLayout* layout10;
    QVBoxLayout* layout26_2;
    QGridLayout* page2Layout;
    QVBoxLayout* layout28;
    QVBoxLayout* layout24;
    QHBoxLayout* layout27;
    QVBoxLayout* layout24_2;
    QVBoxLayout* layout24_2_2;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROEMPRESA_H
