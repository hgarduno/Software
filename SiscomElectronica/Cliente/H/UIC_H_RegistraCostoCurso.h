/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistraCostoCurso.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTRACOSTOCURSO_H
#define REGISTRACOSTOCURSO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QCtrlExplicacionPromocion;
class QPushButton;

class RegistraCostoCurso : public QDialog
{
    Q_OBJECT

public:
    RegistraCostoCurso( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RegistraCostoCurso();

    QLabel* textLabel1;
    QLineEdit* QLEProgramacion;
    QLabel* textLabel2;
    QTable* QTCCurso;
    QLabel* textLabel1_2_2;
    QLineEdit* QLECosto;
    QLabel* textLabel1_2;
    QLineEdit* QLECurso;
    QLabel* textLabel1_3;
    QCtrlExplicacionPromocion* QCtrExPromocion;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegPrecios;
    QPushButton* QPBTerminar;

protected:
    QGridLayout* RegistraCostoCursoLayout;
    QVBoxLayout* layout2;
    QVBoxLayout* layout6;
    QVBoxLayout* layout2_2_2;
    QVBoxLayout* layout2_2;
    QVBoxLayout* layout7;
    QHBoxLayout* layout8;

protected slots:
    virtual void languageChange();

};

#endif // REGISTRACOSTOCURSO_H
