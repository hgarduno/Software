/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroEmpresas2.ui'
**
** Created: Thu Apr 11 22:09:36 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROEMPRESAS2_H
#define REGISTROEMPRESAS2_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;
class QLineEdit;
class QButtonGroup;
class QRadioButton;

class RegistroEmpresas2 : public QWidget
{
    Q_OBJECT

public:
    RegistroEmpresas2( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroEmpresas2();

    QPushButton* QPBADireccion;
    QPushButton* QPBAMedComunicacion;
    QPushButton* QPBAContacto;
    QPushButton* QPBRegistra;
    QLabel* textLabel4;
    QTable* QTDirecciones;
    QLabel* textLabel4_2;
    QTable* QTMedComunicacion;
    QLabel* textLabel4_3;
    QTable* QTContactos;
    QLabel* textLabel2;
    QLineEdit* QLERSocial;
    QButtonGroup* QBGTEmpresa;
    QRadioButton* radioButton1;
    QRadioButton* radioButton2;

protected:
    QGridLayout* RegistroEmpresas2Layout;
    QHBoxLayout* layout8;
    QHBoxLayout* layout9;
    QVBoxLayout* layout7;
    QVBoxLayout* layout7_2;
    QVBoxLayout* layout7_3;
    QHBoxLayout* layout11;
    QVBoxLayout* layout2;
    QGridLayout* QBGTEmpresaLayout;
    QHBoxLayout* layout10;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROEMPRESAS2_H
