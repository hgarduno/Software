/****************************************************************************
** Form interface generated from reading ui file 'UI/OrdenCompra.ui'
**
** Created: Fri Apr 12 21:36:23 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ORDENCOMPRA_H
#define ORDENCOMPRA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class OrdenCompra : public QWidget
{
    Q_OBJECT

public:
    OrdenCompra( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~OrdenCompra();

    QLabel* textLabel2;
    QTable* table2;
    QLabel* textLabel3;
    QTable* table2_2;
    QPushButton* pushButton6;
    QPushButton* pushButton6_2;
    QPushButton* pushButton6_2_2;
    QPushButton* pushButton6_2_2_2;
    QPushButton* pushButton6_3;
    QPushButton* pushButton6_2_3;
    QPushButton* pushButton6_2_2_3;
    QPushButton* pushButton6_2_2_2_2;
    QPushButton* pushButton6_3_2;
    QPushButton* pushButton6_2_3_2;
    QPushButton* pushButton6_2_2_3_2;
    QPushButton* pushButton6_2_2_2_2_2;

protected:
    QGridLayout* OrdenCompraLayout;
    QVBoxLayout* layout10;
    QVBoxLayout* layout11;
    QHBoxLayout* layout14;
    QHBoxLayout* layout14_2;
    QHBoxLayout* layout14_2_2;

protected slots:
    virtual void languageChange();

};

#endif // ORDENCOMPRA_H
