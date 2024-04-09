/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistraProgramaCurso.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTRAPROGRAMACURSO_H
#define REGISTRAPROGRAMACURSO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class RegistraProgramaCurso : public QDialog
{
    Q_OBJECT

public:
    RegistraProgramaCurso( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RegistraProgramaCurso();

    QLabel* textLabel1;
    QLineEdit* QLEDscProgramacion;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* RegistraProgramaCursoLayout;
    QVBoxLayout* layout8;
    QVBoxLayout* layout6;
    QHBoxLayout* layout7;

protected slots:
    virtual void languageChange();

};

#endif // REGISTRAPROGRAMACURSO_H
