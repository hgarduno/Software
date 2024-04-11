/****************************************************************************
** Form interface generated from reading ui file 'UI/AlumnoRegistrado.ui'
**
** Created: Wed Apr 10 20:52:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ALUMNOREGISTRADO_H
#define ALUMNOREGISTRADO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCtrlEscuelas;
class QPushButton;

class AlumnoRegistrado : public QDialog
{
    Q_OBJECT

public:
    AlumnoRegistrado( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~AlumnoRegistrado();

    QLabel* textLabel3;
    QLineEdit* QLENombre;
    QLabel* textLabel3_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel3_2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel2_3;
    QLineEdit* QLECorreo;
    QLabel* textLabel2_3_3;
    QLineEdit* QLEReCorreo;
    QLabel* textLabel2_3_2;
    QLineEdit* QLECelular;
    QLabel* textLabel2_3_2_2;
    QLineEdit* QLETCasa;
    QLabel* textLabel2_2;
    QLineEdit* QLEBoleta;
    QLabel* textLabel1;
    QCtrlEscuelas* QCtrEscuelas;
    QLabel* textLabel2;
    QLineEdit* QLEGrupo;
    QLabel* textLabel2_5;
    QLineEdit* QLEEscuela;
    QPushButton* QPBInscribirCliente;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* AlumnoRegistradoLayout;
    QHBoxLayout* layout12;
    QVBoxLayout* layout5;
    QVBoxLayout* layout5_2;
    QVBoxLayout* layout5_2_2;
    QHBoxLayout* layout17;
    QVBoxLayout* layout11_3;
    QVBoxLayout* layout11_3_3;
    QVBoxLayout* layout11_3_2;
    QVBoxLayout* layout11_3_2_2;
    QVBoxLayout* layout11_2;
    QVBoxLayout* layout10;
    QVBoxLayout* layout11;
    QVBoxLayout* layout11_4;
    QHBoxLayout* layout43;

protected slots:
    virtual void languageChange();

};

#endif // ALUMNOREGISTRADO_H
