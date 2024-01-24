/****************************************************************************
** Form interface generated from reading ui file 'UI/Facturas.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FACTURAS_H
#define FACTURAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QPushButton;

class Facturas : public QWidget
{
    Q_OBJECT

public:
    Facturas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Facturas();

    QTable* QTFacturas;
    QLabel* textLabel1;
    QTable* QTDFactura;
    QPushButton* QPBFProveedor;
    QPushButton* QPBRangoFechas;
    QPushButton* QPBADatos;
    QPushButton* QPBANumFactura;
    QPushButton* QPBAnexarFactura;
    QPushButton* QPBAContabilidad;
    QPushButton* QPBCopiar;

protected:
    QGridLayout* FacturasLayout;
    QHBoxLayout* layout20;

protected slots:
    virtual void languageChange();

};

#endif // FACTURAS_H
