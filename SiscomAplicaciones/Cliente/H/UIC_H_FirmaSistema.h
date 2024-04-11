/****************************************************************************
** Form interface generated from reading ui file 'UI/FirmaSistema.ui'
**
** Created: Sat Jan 27 17:40:27 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FIRMASISTEMA_H
#define FIRMASISTEMA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlServidoresSiscom;
class QCtrlPerfiles;
class QCtrlUsuarios;
class QPushButton;

class FirmaSistema : public QDialog
{
    Q_OBJECT

public:
    FirmaSistema( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~FirmaSistema();

    QLabel* textLabel4;
    QCtrlServidoresSiscom* QCtrServidores;
    QLabel* textLabel5;
    QCtrlPerfiles* QCtrPerfiles;
    QLabel* textLabel6;
    QCtrlUsuarios* QCtrUsuarios;
    QPushButton* QPBCancelar;
    QPushButton* QPBAceptar;
    QPushButton* QPBTipoLetra;

protected:
    QGridLayout* FirmaSistemaLayout;
    QVBoxLayout* layout12;
    QVBoxLayout* layout13;
    QVBoxLayout* layout14;

protected slots:
    virtual void languageChange();

};

#endif // FIRMASISTEMA_H
