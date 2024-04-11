/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RepExistenciaTiendaProveedor.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPEXISTENCIATIENDAPROVEEDOR_H
#define REPEXISTENCIATIENDAPROVEEDOR_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QCtrlTiendasEntrega;
class QCtrlProveedoresSS;
class QCtrlProductosSS;
class QPushButton;

class RepExistenciaTiendaProveedor : public QWidget
{
    Q_OBJECT

public:
    RepExistenciaTiendaProveedor( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RepExistenciaTiendaProveedor();

    QLabel* textLabel4;
    QTable* table4;
    QLabel* textLabel3;
    QCtrlTiendasEntrega* ctrlTiendasEntrega1;
    QLabel* textLabel2_2;
    QCtrlProveedoresSS* ctrlProveedoresSS1_2;
    QLabel* textLabel1;
    QCtrlProductosSS* ctrlProductosSS1;
    QPushButton* pushButton7;
    QPushButton* QPBImprimir;

protected:
    QGridLayout* RepExistenciaTiendaProveedorLayout;
    QHBoxLayout* layout43;
    QVBoxLayout* layout42;
    QVBoxLayout* layout3_2;
    QVBoxLayout* layout36;
    QHBoxLayout* layout38;

protected slots:
    virtual void languageChange();

};

#endif // REPEXISTENCIATIENDAPROVEEDOR_H
