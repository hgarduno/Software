/****************************************************************************
** Form interface generated from reading ui file 'UI/CapturaContacto.ui'
**
** Created: Thu Apr 11 21:52:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURACONTACTO_H
#define CAPTURACONTACTO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLineEdit;

class CapturaContacto : public QDialog
{
    Q_OBJECT

public:
    CapturaContacto( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~CapturaContacto();

    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel3;
    QLineEdit* QLENombre;
    QLabel* textLabel3_2;
    QLineEdit* QLEAPaterno;
    QLabel* textLabel3_3;
    QLineEdit* QLEAMaterno;
    QLabel* textLabel1;
    QLineEdit* QLEDescripcion;

protected:
    QGridLayout* CapturaContactoLayout;
    QHBoxLayout* layout50;
    QVBoxLayout* layout42;
    QHBoxLayout* layout33;
    QVBoxLayout* layout6;
    QVBoxLayout* layout6_2;
    QVBoxLayout* layout6_3;
    QVBoxLayout* layout41;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURACONTACTO_H
