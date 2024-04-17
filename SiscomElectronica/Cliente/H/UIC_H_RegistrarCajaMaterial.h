/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistrarCajaMaterial.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTRARCAJAMATERIAL_H
#define REGISTRARCAJAMATERIAL_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;

class RegistrarCajaMaterial : public QDialog
{
    Q_OBJECT

public:
    RegistrarCajaMaterial( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RegistrarCajaMaterial();

    QLabel* textLabel3;
    QLineEdit* QLECaja;
    QLabel* textLabel4;
    QTextEdit* QTEDescripcion;
    QPushButton* QPBRegistrar;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* RegistrarCajaMaterialLayout;
    QVBoxLayout* layout15;
    QVBoxLayout* layout13;
    QVBoxLayout* layout14;
    QHBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // REGISTRARCAJAMATERIAL_H
