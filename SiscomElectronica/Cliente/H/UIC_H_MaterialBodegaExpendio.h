/****************************************************************************
** Form interface generated from reading ui file 'UI/MaterialBodegaExpendio.ui'
**
** Created: Fri Apr 12 21:25:57 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MATERIALBODEGAEXPENDIO_H
#define MATERIALBODEGAEXPENDIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QTextEdit;
class QPushButton;
class QCtrlProdSiscomElectronica;
class QLineEdit;
class QCtrlBodegas;
class QCtrlExpendios;

class MaterialBodegaExpendio : public QWidget
{
    Q_OBJECT

public:
    MaterialBodegaExpendio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~MaterialBodegaExpendio();

    QLabel* textLabel1_2_2;
    QTable* QTDatos;
    QLabel* textLabel1_2_2_2;
    QTextEdit* QTEDescripcion;
    QPushButton* QPBAnexar;
    QPushButton* QPBRegistrar;
    QPushButton* QPBEliminar;
    QLabel* textLabel1_2;
    QCtrlProdSiscomElectronica* QCtrProductos;
    QLabel* textLabel1_4;
    QLineEdit* QLECantidad;
    QLabel* textLabel1_4_2;
    QLineEdit* QLEExistencia;
    QLabel* textLabel1_3;
    QCtrlBodegas* QCtrBodegas;
    QLabel* textLabel1;
    QCtrlExpendios* QCtrExpendios;

protected:
    QGridLayout* MaterialBodegaExpendioLayout;
    QVBoxLayout* layout3;
    QVBoxLayout* layout6;
    QHBoxLayout* layout15;
    QSpacerItem* spacer1;
    QVBoxLayout* layout2;
    QVBoxLayout* layout8;
    QVBoxLayout* layout8_2;
    QVBoxLayout* layout7;
    QVBoxLayout* layout6_2;

protected slots:
    virtual void languageChange();

};

#endif // MATERIALBODEGAEXPENDIO_H
