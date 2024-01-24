/****************************************************************************
** Form interface generated from reading ui file 'UI/ActualizaPrecioExpendios.ui'
**
** Created: Thu Dec 21 12:53:40 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZAPRECIOEXPENDIOS_H
#define ACTUALIZAPRECIOEXPENDIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QCtrlProductosSE;
class QLineEdit;
class QTextEdit;
class QCtrlExpendios;
class QPushButton;
class QTable;

class ActualizaPrecioExpendios : public QWidget
{
    Q_OBJECT

public:
    ActualizaPrecioExpendios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ActualizaPrecioExpendios();

    QLabel* textLabel4;
    QComboBox* QCBTipoPrecio;
    QLabel* textLabel1;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel5;
    QLineEdit* QLEPVenta;
    QLabel* textLabel5_2;
    QLineEdit* QLENvoPrecio;
    QLabel* textLabel6;
    QTextEdit* QLEDescripcion;
    QLabel* textLabel1_2;
    QCtrlExpendios* QCtrExpendiosO;
    QPushButton* QPBActualizar;
    QPushButton* QPBImprimir_2;
    QPushButton* QPBRegistrar_2;
    QPushButton* QPBEliminar_2;
    QLabel* textLabel1_2_2_2_2;
    QTable* QTExpendios;

protected:
    QGridLayout* ActualizaPrecioExpendiosLayout;
    QVBoxLayout* layout12;
    QVBoxLayout* layout31;
    QHBoxLayout* layout11;
    QVBoxLayout* layout8;
    QVBoxLayout* layout33;
    QVBoxLayout* layout33_2;
    QVBoxLayout* layout52;
    QVBoxLayout* layout6;
    QHBoxLayout* layout40;
    QVBoxLayout* layout3_2;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZAPRECIOEXPENDIOS_H
