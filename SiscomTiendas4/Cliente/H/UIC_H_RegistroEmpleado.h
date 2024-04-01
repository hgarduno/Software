/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroEmpleado.ui'
**
** Created: Sun Jan 28 16:00:49 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROEMPLEADO_H
#define REGISTROEMPLEADO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlPerfiles;
class QPushButton;
class QLineEdit;

class RegistroEmpleado : public QWidget
{
    Q_OBJECT

public:
    RegistroEmpleado( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroEmpleado();

    QLabel* textLabel2;
    QCtrlPerfiles* QCtrPerfiles;
    QPushButton* QPBRegistrar;
    QLabel* textLabel3;
    QLineEdit* QLENombre;
    QLabel* textLabel3_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel3_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel3_3;
    QLineEdit* QLEFirma;
    QLabel* textLabel3_3_2;
    QLineEdit* QLEPassword;
    QLabel* textLabel3_3_2_2;
    QLineEdit* QLENPassword;

protected:
    QGridLayout* RegistroEmpleadoLayout;
    QVBoxLayout* layout10;
    QHBoxLayout* layout19;
    QSpacerItem* spacer1;
    QHBoxLayout* layout14;
    QVBoxLayout* layout11;
    QVBoxLayout* layout11_2;
    QVBoxLayout* layout11_2_2;
    QHBoxLayout* layout20;
    QSpacerItem* spacer2;
    QHBoxLayout* layout18;
    QVBoxLayout* layout11_3;
    QVBoxLayout* layout11_3_2;
    QVBoxLayout* layout11_3_2_2;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROEMPLEADO_H
