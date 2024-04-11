/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RepPreciosProducto.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPPRECIOSPRODUCTO_H
#define REPPRECIOSPRODUCTO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlTiendasEntrega;
class QCtrlProveedoresSS;
class QCtrlDepartamentosSS;
class QTable;
class QPushButton;

class RepPreciosProducto : public QWidget
{
    Q_OBJECT

public:
    RepPreciosProducto( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RepPreciosProducto();

    QLabel* textLabel1;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel1_2;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel1_3;
    QCtrlDepartamentosSS* QCtrDepartamentos;
    QTable* QTListaPrecios;
    QPushButton* QPBImprimir;
    QPushButton* QPBConsulta;

protected:
    QGridLayout* RepPreciosProductoLayout;
    QVBoxLayout* layout2;
    QVBoxLayout* layout3;
    QVBoxLayout* layout5;

protected slots:
    virtual void languageChange();

};

#endif // REPPRECIOSPRODUCTO_H
