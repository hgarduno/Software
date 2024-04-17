/****************************************************************************
** Form interface generated from reading ui file 'UI/UI_Usuarios.ui'
**
** Created: Fri Apr 12 21:23:57 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef USUARIOS_H
#define USUARIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class Usuarios : public QWidget
{
    Q_OBJECT

public:
    Usuarios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Usuarios();

    QLabel* textLabel5;
    QLineEdit* QLENombre;
    QLabel* textLabel5_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel5_2_2;
    QLineEdit* QLEAMaterno;
    QPushButton* QPBRUsuario;
    QPushButton* pushButton22_2;
    QPushButton* pushButton24;

protected:
    QGridLayout* UsuariosLayout;
    QVBoxLayout* layout36;
    QVBoxLayout* layout33;
    QVBoxLayout* layout33_2;
    QVBoxLayout* layout33_2_2;
    QHBoxLayout* layout37;

protected slots:
    virtual void languageChange();

};

#endif // USUARIOS_H
