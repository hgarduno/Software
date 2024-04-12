/****************************************************************************
** Form interface generated from reading ui file 'UI/AnexarFactura.ui'
**
** Created: Thu Apr 11 21:39:51 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ANEXARFACTURA_H
#define ANEXARFACTURA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTable;

class AnexarFactura : public QDialog
{
    Q_OBJECT

public:
    AnexarFactura( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~AnexarFactura();

    QLabel* textLabel4;
    QLineEdit* QLENumFactura;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QTable* QTFacturas;

protected:
    QGridLayout* AnexarFacturaLayout;
    QVBoxLayout* layout46;
    QHBoxLayout* layout47;

protected slots:
    virtual void languageChange();

};

#endif // ANEXARFACTURA_H
