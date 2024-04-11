/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/ExistenciasTienda.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef EXISTENCIASTIENDA_H
#define EXISTENCIASTIENDA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlTiendasEntrega;
class QCtrlProveedoresSS;
class QTable;
class QTextEdit;
class QPushButton;

class ExistenciasTienda : public QWidget
{
    Q_OBJECT

public:
    ExistenciasTienda( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ExistenciasTienda();

    QLabel* textLabel2_2;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel2;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel1;
    QTable* QTExistencias;
    QLabel* textLabel3;
    QTextEdit* QTEListaProductos;
    QPushButton* QPBTodosLosProductos;
    QPushButton* QPBExistenciasProveedor;
    QPushButton* QPBExistenciasProducto;
    QPushButton* QPBExistenciasListaProductos;

protected:
    QGridLayout* ExistenciasTiendaLayout;
    QHBoxLayout* layout13;
    QVBoxLayout* layout17;
    QVBoxLayout* layout16;
    QVBoxLayout* layout2;
    QVBoxLayout* layout14;
    QVBoxLayout* layout1;
    QVBoxLayout* layout13_2;
    QHBoxLayout* layout17_2;

protected slots:
    virtual void languageChange();

};

#endif // EXISTENCIASTIENDA_H
