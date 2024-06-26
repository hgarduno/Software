/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RegistroUsuarios.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROUSUARIOS_H
#define REGISTROUSUARIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCtrlPerfilesSS;
class QPushButton;

class RegistroUsuarios : public QWidget
{
    Q_OBJECT

public:
    RegistroUsuarios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroUsuarios();

    QLabel* textLabel1;
    QLineEdit* QLENombre;
    QLabel* textLabel1_2;
    QLineEdit* QLEApellidoPaterno;
    QLabel* textLabel1_2_2;
    QLineEdit* QLEApellidoMaterno;
    QLabel* textLabel2;
    QCtrlPerfilesSS* QCtrPerfiles;
    QLabel* textLabel3_2_2;
    QLineEdit* QLEFirma;
    QLabel* textLabel3;
    QLineEdit* QLEContrasena;
    QLabel* textLabel3_2;
    QLineEdit* QLERepetirContrasena;
    QPushButton* QPBRegistrar;

protected:
    QGridLayout* RegistroUsuariosLayout;
    QVBoxLayout* layout17;
    QHBoxLayout* layout74;
    QHBoxLayout* layout73;
    QVBoxLayout* layout64;
    QVBoxLayout* layout72;
    QVBoxLayout* layout66;
    QHBoxLayout* layout16;
    QVBoxLayout* layout11;
    QVBoxLayout* layout13;
    QVBoxLayout* layout14;
    QVBoxLayout* layout15;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROUSUARIOS_H
