/****************************************************************************
** Form interface generated from reading ui file 'UI/Facturacion.ui'
**
** Created: Wed Apr 10 21:10:11 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FACTURACION_H
#define FACTURACION_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QTabWidget;
class QWidget;
class QPushButton;
class QLCDNumber;

class Facturacion : public QDialog
{
    Q_OBJECT

public:
    Facturacion( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Facturacion();

    QLabel* textLabel2;
    QLineEdit* QLECliente;
    QLabel* textLabel2_2;
    QLineEdit* lineEdit1_2;
    QLabel* textLabel2_2_2;
    QLineEdit* QLERFC;
    QTable* QTDatos;
    QTabWidget* tabWidget2;
    QWidget* tab;
    QPushButton* pushButton1_2;
    QPushButton* QPBImprime;
    QWidget* tab_2;
    QTable* QTDOrden;
    QWidget* TabPage;
    QLabel* textLabel1;
    QLCDNumber* QLCDImpTotal;
    QLabel* textLabel1_2;
    QLCDNumber* QLCImpMIVA;

protected:
    QGridLayout* FacturacionLayout;
    QVBoxLayout* layout3;
    QVBoxLayout* layout3_2;
    QVBoxLayout* layout3_2_2;
    QHBoxLayout* layout7;
    QGridLayout* tabLayout;
    QHBoxLayout* layout5;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // FACTURACION_H
