/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroAlumnoCurso.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROALUMNOCURSO_H
#define REGISTROALUMNOCURSO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QFrame;
class QLabel;
class QLineEdit;
class QCtrlEscuelas;
class QTable;
class QCtrlCursos;
class QPushButton;

class RegistroAlumnoCurso : public QWidget
{
    Q_OBJECT

public:
    RegistroAlumnoCurso( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroAlumnoCurso();

    QFrame* QFDatosAlumno;
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
    QTable* QTHorariosCurso;
    QLabel* textLabel1_2;
    QCtrlCursos* QCtrCursos;
    QPushButton* QPBDisponibilidadC;
    QTable* QTCostos;
    QPushButton* QPBRegistrar;
    QPushButton* QPBImpComprobante;
    QPushButton* QPBInscribeOAlumno;

protected:
    QGridLayout* RegistroAlumnoCursoLayout;
    QGridLayout* QFDatosAlumnoLayout;
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
    QHBoxLayout* layout25;
    QVBoxLayout* layout24;
    QHBoxLayout* layout23;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROALUMNOCURSO_H
