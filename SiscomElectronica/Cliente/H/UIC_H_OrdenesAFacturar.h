/****************************************************************************
** Form interface generated from reading ui file 'UI/OrdenesAFacturar.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENESAFACTURAR_H
#define ORDENESAFACTURAR_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QLCDNumber;
class QLineEdit;
class QTable;

class OrdenesAFacturar : public QDialog
{
    Q_OBJECT

public:
    OrdenesAFacturar( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~OrdenesAFacturar();

    QPushButton* QPBAnexarO;
    QPushButton* QPBAceptar;
    QPushButton* pushButton9_2;
    QLabel* textLabel2_4;
    QLCDNumber* QLCNTotal;
    QLabel* textLabel2_4_2;
    QLCDNumber* QLCNIVA;
    QLabel* textLabel2_2_2;
    QLCDNumber* QLCDNTotalMIVA;
    QLabel* textLabel2;
    QLineEdit* QLEOrden;
    QLabel* textLabel3;
    QTable* QTDatos;
    QLabel* textLabel1;
    QTable* QTOrdenes;
    QLabel* textLabel3_2;
    QTable* QTProdOrden;

protected:
    QGridLayout* OrdenesAFacturarLayout;
    QHBoxLayout* layout51;
    QHBoxLayout* layout57;
    QVBoxLayout* layout23;
    QVBoxLayout* layout23_3;
    QVBoxLayout* layout23_2;
    QVBoxLayout* layout45;
    QVBoxLayout* layout36;
    QHBoxLayout* layout9;
    QVBoxLayout* layout46;
    QVBoxLayout* layout8;
    QVBoxLayout* layout46_2;

protected slots:
    virtual void languageChange();

};

#endif // ORDENESAFACTURAR_H
