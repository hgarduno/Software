/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RepStockDepartamentoProveedor.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPSTOCKDEPARTAMENTOPROVEEDOR_H
#define REPSTOCKDEPARTAMENTOPROVEEDOR_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlTiendasEntrega;
class QTable;
class QCtrlProveedoresSS;
class QPushButton;

class RepStockDepartamentoProveedor : public QWidget
{
    Q_OBJECT

public:
    RepStockDepartamentoProveedor( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RepStockDepartamentoProveedor();

    QLabel* textLabel1;
    QCtrlTiendasEntrega* QCtrTiendas;
    QTable* QTReporte;
    QLabel* textLabel2;
    QCtrlProveedoresSS* QCtrProveedor;
    QPushButton* QPBConsulta;
    QPushButton* QPBImprimir;

protected:
    QGridLayout* RepStockDepartamentoProveedorLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout4;

protected slots:
    virtual void languageChange();

};

#endif // REPSTOCKDEPARTAMENTOPROVEEDOR_H
