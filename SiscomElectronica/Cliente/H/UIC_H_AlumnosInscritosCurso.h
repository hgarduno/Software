/****************************************************************************
** Form interface generated from reading ui file 'UI/AlumnosInscritosCurso.ui'
**
** Created: Wed Apr 10 20:52:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ALUMNOSINSCRITOSCURSO_H
#define ALUMNOSINSCRITOSCURSO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlCursos;
class QCtrlFechasCursos;
class QTable;
class QPushButton;

class AlumnosInscritosCurso : public QWidget
{
    Q_OBJECT

public:
    AlumnosInscritosCurso( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~AlumnosInscritosCurso();

    QLabel* textLabel1_2;
    QCtrlCursos* QCtrCursos;
    QLabel* textLabel1;
    QCtrlFechasCursos* QCtrFechasCurso;
    QTable* QTAlumnos;
    QPushButton* pushButton2;
    QPushButton* pushButton3;

protected:
    QGridLayout* AlumnosInscritosCursoLayout;
    QHBoxLayout* layout19;
    QVBoxLayout* layout12;
    QVBoxLayout* layout18;
    QHBoxLayout* layout20;

protected slots:
    virtual void languageChange();

};

#endif // ALUMNOSINSCRITOSCURSO_H
