/****************************************************************************
** Form interface generated from reading ui file 'UI/ActualizaDatosAlumno.ui'
**
** Created: Wed Apr 10 20:52:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZADATOSALUMNO_H
#define ACTUALIZADATOSALUMNO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlAlumnos;
class QLineEdit;
class QCtrlEscuelas;
class QPushButton;

class ActualizaDatosAlumno : public QWidget
{
    Q_OBJECT

public:
    ActualizaDatosAlumno( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ActualizaDatosAlumno();

    QLabel* textLabel1;
    QCtrlAlumnos* QCtrAlumnos;
    QLabel* textLabel2;
    QLineEdit* QLENombre;
    QLabel* textLabel2_3;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel2_2;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel3;
    QCtrlEscuelas* QCtrEscuelas;
    QLabel* textLabel2_4;
    QLineEdit* QLEGrupo;
    QLabel* textLabel2_5;
    QLineEdit* QLEBoleta;
    QLabel* textLabel2_4_4;
    QLineEdit* QLECorreoE;
    QLabel* textLabel2_4_3;
    QLineEdit* QLECelular;
    QLabel* textLabel2_4_2;
    QLineEdit* QLETelefonoCasa;
    QPushButton* QPBActualiza;
    QPushButton* QPBCambiaEscuela;
    QPushButton* QPBSelAlumno;

protected:
    QGridLayout* ActualizaDatosAlumnoLayout;
    QVBoxLayout* layout17;
    QVBoxLayout* layout1;
    QHBoxLayout* layout8;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_3;
    QVBoxLayout* layout2_2;
    QHBoxLayout* layout16;
    QVBoxLayout* layout9;
    QVBoxLayout* layout2_4;
    QVBoxLayout* layout2_5;
    QHBoxLayout* layout15;
    QVBoxLayout* layout2_4_4;
    QVBoxLayout* layout2_4_3;
    QVBoxLayout* layout2_4_2;
    QHBoxLayout* layout20;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZADATOSALUMNO_H
