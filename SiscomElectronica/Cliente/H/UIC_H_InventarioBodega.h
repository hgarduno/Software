/****************************************************************************
** Form interface generated from reading ui file 'UI/InventarioBodega.ui'
**
** Created: Fri Apr 12 21:25:57 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef INVENTARIOBODEGA_H
#define INVENTARIOBODEGA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlBodegas;
class QCtrlProdSiscomElectronica;
class QLineEdit;
class QTextEdit;
class QPushButton;

class InventarioBodega : public QWidget
{
    Q_OBJECT

public:
    InventarioBodega( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~InventarioBodega();

    QLabel* textLabel1_4;
    QCtrlBodegas* QCtrBodegas;
    QLabel* textLabel1;
    QCtrlProdSiscomElectronica* QCtrProductos;
    QLabel* textLabel1_3_2;
    QLineEdit* QLECantidad;
    QLabel* textLabel1_3;
    QLineEdit* QLEExistencia;
    QLabel* textLabel1_2;
    QTextEdit* QTEDescripcion;
    QPushButton* QPBRegistrar;
    QPushButton* QPBActivaBodegas;

protected:
    QGridLayout* InventarioBodegaLayout;
    QVBoxLayout* layout7;
    QHBoxLayout* layout10;
    QSpacerItem* spacer1;
    QHBoxLayout* layout9;
    QVBoxLayout* layout1;
    QVBoxLayout* layout4_2;
    QVBoxLayout* layout4;
    QVBoxLayout* layout2;
    QHBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // INVENTARIOBODEGA_H
