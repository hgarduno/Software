/****************************************************************************
** Form interface generated from reading ui file 'UI/DisponibilidadCursos.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DISPONIBILIDADCURSOS_H
#define DISPONIBILIDADCURSOS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlFechasCursos;
class QTable;
class QPushButton;

class DisponibilidadCursos : public QDialog
{
    Q_OBJECT

public:
    DisponibilidadCursos( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~DisponibilidadCursos();

    QLabel* textLabel1;
    QCtrlFechasCursos* QCtrFechasCurso;
    QTable* QTHorariosCurso;
    QPushButton* pushButton5;
    QPushButton* pushButton5_2;

protected:
    QGridLayout* DisponibilidadCursosLayout;
    QVBoxLayout* layout18;
    QHBoxLayout* layout28;

protected slots:
    virtual void languageChange();

};

#endif // DISPONIBILIDADCURSOS_H
