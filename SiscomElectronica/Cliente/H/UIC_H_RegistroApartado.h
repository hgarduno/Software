/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroApartado.ui'
**
** Created: Wed Apr 10 20:52:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROAPARTADO_H
#define REGISTROAPARTADO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCtrlFechaHora;
class QTextEdit;
class QPushButton;

class RegistroApartado : public QDialog
{
    Q_OBJECT

public:
    RegistroApartado( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RegistroApartado();

    QLabel* textLabel2;
    QLineEdit* QLENombre;
    QLabel* textLabel2_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel2_3;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel2_4;
    QLineEdit* QLECelular;
    QLabel* textLabel2_4_2;
    QLineEdit* QLEReCelular;
    QLabel* textLabel2_4_3;
    QLineEdit* QLECorreo;
    QLabel* textLabel2_4_3_2;
    QLineEdit* QLEReCorreo;
    QLabel* textLabel2_5;
    QLineEdit* QLEACuenta;
    QLabel* textLabel3_2;
    QCtrlFechaHora* QCtrFechaEntrega;
    QLabel* textLabel1;
    QTextEdit* QTEObservaciones;
    QPushButton* QPBRegistraPersonales;
    QPushButton* QPBRegistraCelular;
    QPushButton* QPBRegistraCorreo;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* RegistroApartadoLayout;
    QHBoxLayout* layout5;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;
    QVBoxLayout* layout2_3;
    QHBoxLayout* layout35;
    QHBoxLayout* layout10;
    QVBoxLayout* layout2_4;
    QVBoxLayout* layout2_4_2;
    QHBoxLayout* layout11;
    QVBoxLayout* layout2_4_3;
    QVBoxLayout* layout2_4_3_2;
    QHBoxLayout* layout44;
    QVBoxLayout* layout43;
    QVBoxLayout* layout41_2;
    QVBoxLayout* layout36;
    QHBoxLayout* layout18;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROAPARTADO_H
