/****************************************************************************
** Form interface generated from reading ui file 'UI/TotalVentasProducto.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TOTALVENTASPRODUCTO_H
#define TOTALVENTASPRODUCTO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLCDNumber;

class TotalVentasProducto : public QWidget
{
    Q_OBJECT

public:
    TotalVentasProducto( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TotalVentasProducto();

    QTable* QTDatos;
    QLabel* textLabel1;
    QLCDNumber* QLCDNCantidad;

protected:
    QGridLayout* TotalVentasProductoLayout;
    QHBoxLayout* layout32;
    QVBoxLayout* layout30;

protected slots:
    virtual void languageChange();

};

#endif // TOTALVENTASPRODUCTO_H
