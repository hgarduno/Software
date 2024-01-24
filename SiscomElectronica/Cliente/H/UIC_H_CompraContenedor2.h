/****************************************************************************
** Form interface generated from reading ui file 'UI/CompraContenedor2.ui'
**
** Created: Thu Dec 21 12:53:40 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COMPRACONTENEDOR2_H
#define COMPRACONTENEDOR2_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class QTextEdit;
class QLineEdit;
class QLCDNumber;

class CompraContenedor2 : public QWidget
{
    Q_OBJECT

public:
    CompraContenedor2( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CompraContenedor2();

    QLabel* textLabel2;
    QTable* QTProductos;
    QPushButton* pushButton5;
    QPushButton* QPBAgregaFactura;
    QLabel* textLabel3;
    QTextEdit* textEdit3;
    QLabel* textLabel3_2;
    QLineEdit* QLECostoEnvio;
    QLabel* textLabel3_2_2;
    QLineEdit* QLECostoDolar;
    QLabel* textLabel3_2_2_2;
    QLineEdit* QLECostoAdministrativo;
    QLabel* textLabel1_5;
    QLCDNumber* QLCNPesoCompra;
    QLabel* textLabel1_5_2;
    QLCDNumber* QLCDNImporteFactura;
    QLabel* textLabel1_5_3_2;
    QLCDNumber* QLCNCostoGrEnvio_2;

protected:
    QGridLayout* CompraContenedor2Layout;
    QVBoxLayout* layout8;
    QHBoxLayout* layout54;
    QHBoxLayout* layout60;
    QHBoxLayout* layout59;
    QVBoxLayout* layout58;
    QVBoxLayout* layout50;
    QVBoxLayout* layout40_2;
    QVBoxLayout* layout40_2_2;
    QVBoxLayout* layout52;
    QSpacerItem* spacer3;
    QVBoxLayout* layout40_2_2_2;
    QHBoxLayout* layout57;
    QVBoxLayout* layout21;
    QVBoxLayout* layout21_2;
    QVBoxLayout* layout21_3;

protected slots:
    virtual void languageChange();

};

#endif // COMPRACONTENEDOR2_H
