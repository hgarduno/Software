/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/ActualizaStock.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZASTOCK_H
#define ACTUALIZASTOCK_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QCtrlTiendasEntrega;
class QCtrlProveedoresSS;
class QCtrlProductosSS;
class QCtrlStock;

class ActualizaStock : public QWidget
{
    Q_OBJECT

public:
    ActualizaStock( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ActualizaStock();

    QLabel* textLabel3;
    QLineEdit* QLEStock;
    QPushButton* QPBConsulta;
    QPushButton* QPBActualizar;
    QLabel* Tienda;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel2;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel1_2_3;
    QCtrlProductosSS* QCtrProductos;
    QLabel* textLabel4;
    QCtrlStock* QCtrStock;

protected:
    QGridLayout* ActualizaStockLayout;
    QVBoxLayout* layout59;
    QHBoxLayout* layout61;
    QHBoxLayout* layout8;
    QVBoxLayout* layout56;
    QVBoxLayout* layout57;
    QVBoxLayout* layout7;
    QVBoxLayout* layout7_2;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZASTOCK_H
