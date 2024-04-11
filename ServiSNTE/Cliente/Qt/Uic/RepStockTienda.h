/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RepStockTienda.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPSTOCKTIENDA_H
#define REPSTOCKTIENDA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class QCtrlTiendasEntrega;
class QCtrlProveedoresSS;
class QRadioButton;

class RepStockTienda : public QWidget
{
    Q_OBJECT

public:
    RepStockTienda( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RepStockTienda();

    QLabel* textLabel2;
    QTable* QTListaStock;
    QPushButton* QPBConsulta;
    QPushButton* QPBImprimir;
    QLabel* textLabel1_2;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel2_2;
    QCtrlProveedoresSS* QCtrProveedores;
    QRadioButton* QRBPrecio;
    QRadioButton* QRBImporteVenta;

protected:
    QGridLayout* RepStockTiendaLayout;
    QVBoxLayout* layout4;
    QHBoxLayout* layout48;
    QVBoxLayout* layout1;
    QVBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // REPSTOCKTIENDA_H
