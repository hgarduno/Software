/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroRapidoAlumno.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTRORAPIDOALUMNO_H
#define REGISTRORAPIDOALUMNO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCtrlEscuelas;
class QPushButton;

class RegistroRapidoAlumno : public QWidget
{
    Q_OBJECT

public:
    RegistroRapidoAlumno( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroRapidoAlumno();

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
    QPushButton* QPBRegistrar;
    QLabel* textLabel2_3;
    QLineEdit* QLECorreo;
    QLabel* textLabel2_3_2;
    QLineEdit* QLECelular;
    QLabel* textLabel2_3_2_2;
    QLineEdit* QLETCasa;

protected:
    QGridLayout* RegistroRapidoAlumnoLayout;
    QHBoxLayout* layout12;
    QVBoxLayout* layout5;
    QVBoxLayout* layout5_2;
    QVBoxLayout* layout5_2_2;
    QHBoxLayout* layout37;
    QVBoxLayout* layout10;
    QVBoxLayout* layout11;
    QVBoxLayout* layout11_2;
    QVBoxLayout* layout11_3;
    QVBoxLayout* layout11_3_2;
    QVBoxLayout* layout11_3_2_2;

protected slots:
    virtual void languageChange();

};

#endif // REGISTRORAPIDOALUMNO_H
