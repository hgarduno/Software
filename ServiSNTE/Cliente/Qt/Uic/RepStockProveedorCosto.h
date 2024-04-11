/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RepStockProveedorCosto.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPSTOCKPROVEEDORCOSTO_H
#define REPSTOCKPROVEEDORCOSTO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProveedoresSS;
class QTable;
class QPushButton;

class RepStockProveedorCosto : public QWidget
{
    Q_OBJECT

public:
    RepStockProveedorCosto( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RepStockProveedorCosto();

    QLabel* textLabel1;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel2;
    QTable* QTExistenciaProveedor;
    QPushButton* QPBImprimir;
    QPushButton* QPBConsulta;

protected:
    QGridLayout* RepStockProveedorCostoLayout;
    QVBoxLayout* layout5;
    QVBoxLayout* layout6;

protected slots:
    virtual void languageChange();

};

#endif // REPSTOCKPROVEEDORCOSTO_H
