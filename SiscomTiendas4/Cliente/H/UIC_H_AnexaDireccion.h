/****************************************************************************
** Form interface generated from reading ui file 'UI/AnexaDireccion.ui'
**
** Created: Thu Apr 11 20:30:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ANEXADIRECCION_H
#define ANEXADIRECCION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QSisSepomex;
class QPushButton;

class AnexaDireccion : public QDialog
{
    Q_OBJECT

public:
    AnexaDireccion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~AnexaDireccion();

    QSisSepomex* QCtrSepomex;
    QPushButton* QPBRegistrar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* AnexaDireccionLayout;
    QHBoxLayout* layout19;

protected slots:
    virtual void languageChange();

};

#endif // ANEXADIRECCION_H
