/****************************************************************************
** Form interface generated from reading ui file 'UI/RastreoProducto.ui'
**
** Created: Wed Jan 31 10:48:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef RASTREOPRODUCTO_H
#define RASTREOPRODUCTO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;
class QCtrlProdSiscomElectronica;
class QLineEdit;
class QTable;
class QPushButton;

class RastreoProducto : public QWidget
{
    Q_OBJECT

public:
    RastreoProducto( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RastreoProducto();

    QLabel* textLabel3;
    CQControlFecha* QCtrFechaIni;
    QLabel* textLabel3_3;
    CQControlFecha* QCtrFechaFin;
    QLabel* textLabel1;
    QCtrlProdSiscomElectronica* QCtrProductos;
    QLabel* textLabel4;
    QLineEdit* QLEEExpendio;
    QLabel* textLabel4_2;
    QLineEdit* QLEEBodegas;
    QTable* QTDatos;
    QPushButton* QPBPCDesajuste;

protected:
    QGridLayout* RastreoProductoLayout;
    QVBoxLayout* layout13;
    QVBoxLayout* layout13_2;
    QVBoxLayout* layout1;
    QHBoxLayout* layout23;
    QVBoxLayout* layout18;
    QVBoxLayout* layout18_2;

protected slots:
    virtual void languageChange();

};

#endif // RASTREOPRODUCTO_H
