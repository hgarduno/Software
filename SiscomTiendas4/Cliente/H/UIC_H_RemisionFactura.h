/****************************************************************************
** Form interface generated from reading ui file 'UI/RemisionFactura.ui'
**
** Created: Sun Feb 9 03:08:48 2020
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REMISIONFACTURA_H
#define REMISIONFACTURA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;

class RemisionFactura : public QDialog
{
    Q_OBJECT

public:
    RemisionFactura( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RemisionFactura();

    QLabel* textLabel1;
    QLineEdit* QLERemFactura;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* RemisionFacturaLayout;
    QVBoxLayout* layout3;
    QVBoxLayout* layout1;
    QHBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // REMISIONFACTURA_H
