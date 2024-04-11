/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CapturaInventarioAlmacen.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAPTURAINVENTARIOALMACEN_H
#define CAPTURAINVENTARIOALMACEN_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProveedoresSS;
class QCtrlProductosSS;
class QLineEdit;
class QTable;
class QPushButton;

class CapturaInventarioAlmacen : public QWidget
{
    Q_OBJECT

public:
    CapturaInventarioAlmacen( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CapturaInventarioAlmacen();

    QLabel* textLabel2;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel1;
    QCtrlProductosSS* QCtrProductos;
    QLabel* textLabel3;
    QLineEdit* QLECodigoBarras;
    QLabel* textLabel4;
    QTable* QTProductos;
    QLabel* textLabel1_2;
    QLineEdit* QLECantidad;
    QPushButton* QPBProgramaInventario;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegistrar;

protected:
    QGridLayout* CapturaInventarioAlmacenLayout;
    QHBoxLayout* layout3;
    QVBoxLayout* layout2;
    QVBoxLayout* layout1;
    QVBoxLayout* layout4;
    QVBoxLayout* layout5;
    QHBoxLayout* layout8;
    QSpacerItem* spacer1;
    QVBoxLayout* layout7;
    QHBoxLayout* layout10;

protected slots:
    virtual void languageChange();

};

#endif // CAPTURAINVENTARIOALMACEN_H
