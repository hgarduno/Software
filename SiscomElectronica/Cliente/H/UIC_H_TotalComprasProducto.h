/****************************************************************************
** Form interface generated from reading ui file 'UI/TotalComprasProducto.ui'
**
** Created: Wed Jan 31 10:48:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TOTALCOMPRASPRODUCTO_H
#define TOTALCOMPRASPRODUCTO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLCDNumber;

class TotalComprasProducto : public QWidget
{
    Q_OBJECT

public:
    TotalComprasProducto( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TotalComprasProducto();

    QTable* QTDatos;
    QLabel* textLabel1;
    QLCDNumber* QLCDNCantidad;

protected:
    QGridLayout* TotalComprasProductoLayout;
    QHBoxLayout* layout32;
    QVBoxLayout* layout30;

protected slots:
    virtual void languageChange();

};

#endif // TOTALCOMPRASPRODUCTO_H
