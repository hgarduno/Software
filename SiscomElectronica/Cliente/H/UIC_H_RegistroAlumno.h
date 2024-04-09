/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroAlumno.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROALUMNO_H
#define REGISTROALUMNO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;
class QCtrlEscuelas;

class RegistroAlumno : public QWidget
{
    Q_OBJECT

public:
    RegistroAlumno( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroAlumno();

    QPushButton* QPBRegistrar;
    QPushButton* pushButton6_2;
    QLabel* textLabel3;
    QLineEdit* QLENombre;
    QLabel* textLabel3_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel3_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel1;
    QCtrlEscuelas* QCtrEscuelas;
    QLabel* textLabel2;
    QLineEdit* QLEGrupo;
    QLabel* textLabel2_2;
    QLineEdit* QLEBoleta;
    QLabel* textLabel2_3;
    QLineEdit* QLECorreo;
    QLabel* textLabel2_3_3;
    QLineEdit* QLEReCorreo;
    QLabel* textLabel2_3_2;
    QLineEdit* QLECelular;
    QLabel* textLabel2_3_2_2;
    QLineEdit* QLETCasa;
    QLabel* textLabel1_2;
    QLineEdit* QLENoCredencial;

protected:
    QGridLayout* RegistroAlumnoLayout;
    QHBoxLayout* layout63;
    QHBoxLayout* layout12;
    QVBoxLayout* layout5;
    QVBoxLayout* layout5_2;
    QVBoxLayout* layout5_2_2;
    QHBoxLayout* layout37;
    QVBoxLayout* layout10;
    QVBoxLayout* layout11;
    QVBoxLayout* layout11_2;
    QHBoxLayout* layout17;
    QVBoxLayout* layout11_3;
    QVBoxLayout* layout11_3_3;
    QVBoxLayout* layout11_3_2;
    QVBoxLayout* layout11_3_2_2;
    QVBoxLayout* layout30;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROALUMNO_H
