/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroAlumnoServicio.ui'
**
** Created: Thu Apr 11 21:39:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROALUMNOSERVICIO_H
#define REGISTROALUMNOSERVICIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QCtrlServiciosSiscom;
class QCtrlAlumnos;
class QTextEdit;
class QTable;

class RegistroAlumnoServicio : public QWidget
{
    Q_OBJECT

public:
    RegistroAlumnoServicio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroAlumnoServicio();

    QPushButton* QPBRegHEntrada;
    QPushButton* QPBRHSalida;
    QPushButton* pushButton1_3;
    QLabel* textLabel1;
    QCtrlServiciosSiscom* QCtrServicios;
    QLabel* textLabel3;
    QCtrlAlumnos* QCtrAlumnos;
    QLabel* textLabel5;
    QTextEdit* QTEComentarios;
    QLabel* textLabel6;
    QTable* QTAlumnosEnTaller;

protected:
    QGridLayout* RegistroAlumnoServicioLayout;
    QHBoxLayout* layout11;
    QHBoxLayout* layout17;
    QHBoxLayout* layout4;
    QVBoxLayout* layout1;
    QVBoxLayout* layout3;
    QVBoxLayout* layout19;
    QVBoxLayout* layout20;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROALUMNOSERVICIO_H
