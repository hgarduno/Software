/****************************************************************************
** Form interface generated from reading ui file 'UI/SelAlumno.ui'
**
** Created: lun abr 1 18:57:46 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SELALUMNO_H
#define SELALUMNO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QCtrlEscuelas;
class QTextEdit;
class QPushButton;

class SelAlumno : public QDialog
{
    Q_OBJECT

public:
    SelAlumno( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SelAlumno();

    QLabel* textLabel1;
    QComboBox* QCBAlumnos;
    QLabel* textLabel2;
    QCtrlEscuelas* QCBEscuelas;
    QLabel* textLabel4;
    QTextEdit* QTEAlumno;
    QPushButton* QPBAceptar;
    QPushButton* QPBRegistrarA;
    QPushButton* QPBCancelar;
    QPushButton* QPBCancelarRegRap;

protected:
    QGridLayout* SelAlumnoLayout;
    QHBoxLayout* layout13;
    QVBoxLayout* layout12;
    QSpacerItem* spacer1;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QVBoxLayout* layout9;
    QHBoxLayout* layout8;

protected slots:
    virtual void languageChange();

};

#endif // SELALUMNO_H
