/****************************************************************************
** Form interface generated from reading ui file 'UI/ProgramandoCurso.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PROGRAMANDOCURSO_H
#define PROGRAMANDOCURSO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QPushButton;
class QCtrlProgramacionCursos;
class QCtrlCursos;
class CQControlFecha;
class QCtrlRangoHora;
class QTextEdit;

class ProgramandoCurso : public QWidget
{
    Q_OBJECT

public:
    ProgramandoCurso( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ProgramandoCurso();

    QTable* QTCursos;
    QLabel* textLabel1_2;
    QTable* table2;
    QPushButton* QPBHabilitaProgCursos;
    QPushButton* QPBHabilitaCursos;
    QPushButton* QPBRegistraProgCursos;
    QPushButton* QPRegistraFecha;
    QPushButton* QPEliminaHorariosSeleccionados;
    QPushButton* QPRegistraFecha_2_2;
    QPushButton* QPBCCPorFecha;
    QPushButton* QPRegistraFecha_2_2_2;
    QLabel* textLabel1;
    QCtrlProgramacionCursos* QCtrProgramacionC;
    QPushButton* QPBAgregaProgramacion;
    QLabel* textLabel2;
    QCtrlCursos* QCtrCursos;
    QPushButton* pushButton1;
    QLabel* textLabel3;
    CQControlFecha* QCtrFechaInicio;
    QLabel* textLabel1_3;
    QCtrlRangoHora* QCtrRangoHora;
    QPushButton* pushButton1_2;
    QLabel* textLabel1_4;
    QTextEdit* textEdit2;

protected:
    QGridLayout* ProgramandoCursoLayout;
    QVBoxLayout* layout11;
    QVBoxLayout* layout19;
    QVBoxLayout* layout16;
    QHBoxLayout* layout14;
    QHBoxLayout* layout15;
    QVBoxLayout* layout20;
    QHBoxLayout* layout40;
    QVBoxLayout* layout36;
    QHBoxLayout* layout8;
    QVBoxLayout* layout7;
    QHBoxLayout* layout33;
    QVBoxLayout* layout4;
    QHBoxLayout* layout34;
    QHBoxLayout* layout11_2;
    QVBoxLayout* layout11_3;
    QVBoxLayout* layout10;
    QVBoxLayout* layout38;

protected slots:
    virtual void languageChange();

};

#endif // PROGRAMANDOCURSO_H
