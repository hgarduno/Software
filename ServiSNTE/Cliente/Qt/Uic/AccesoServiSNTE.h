/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/AccesoServiSNTE.ui'
**
** Created: Thu Apr 11 21:10:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACCESOSERVISNTE_H
#define ACCESOSERVISNTE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class AccesoServiSNTE : public QDialog
{
    Q_OBJECT

public:
    AccesoServiSNTE( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~AccesoServiSNTE();

    QLabel* textLabel2;
    QLineEdit* QLEUsuario;
    QLabel* textLabel3;
    QLineEdit* QLEPassword;
    QPushButton* QPBAceptar;
    QPushButton* QPBTipoLetra;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* AccesoServiSNTELayout;
    QVBoxLayout* layout59;
    QVBoxLayout* layout60;
    QHBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // ACCESOSERVISNTE_H
