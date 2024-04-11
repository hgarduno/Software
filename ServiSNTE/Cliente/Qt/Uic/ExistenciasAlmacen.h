/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/ExistenciasAlmacen.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef EXISTENCIASALMACEN_H
#define EXISTENCIASALMACEN_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProveedoresSS;
class QTable;
class QTextEdit;
class QPushButton;

class ExistenciasAlmacen : public QWidget
{
    Q_OBJECT

public:
    ExistenciasAlmacen( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ExistenciasAlmacen();

    QLabel* textLabel2;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel1;
    QTable* QTExistencias;
    QLabel* textLabel3;
    QTextEdit* QTEListaProductos;
    QPushButton* QPBExistenciasProveedor;
    QPushButton* QPBPorProducto;
    QPushButton* QPBExistenciasListaProductos;

protected:
    QGridLayout* ExistenciasAlmacenLayout;
    QHBoxLayout* layout11;
    QVBoxLayout* layout10;
    QVBoxLayout* layout33;
    QVBoxLayout* layout1;
    QVBoxLayout* layout13;
    QHBoxLayout* layout12;

protected slots:
    virtual void languageChange();

};

#endif // EXISTENCIASALMACEN_H
