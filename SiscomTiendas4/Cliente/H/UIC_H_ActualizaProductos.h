/****************************************************************************
** Form interface generated from reading ui file 'UI/ActualizaProductos.ui'
**
** Created: Sun Feb 9 03:08:48 2020
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ACTUALIZAPRODUCTOS_H
#define ACTUALIZAPRODUCTOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QLineEdit;
class QTextEdit;
class QCtrlProductos;
class QPushButton;
class QCtrlFamilias;

class ActualizaProductos : public QWidget
{
    Q_OBJECT

public:
    ActualizaProductos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ActualizaProductos();

    QGroupBox* groupBox1;
    QLabel* textLabel3;
    QLineEdit* QLEProducto;
    QLabel* textLabel3_2;
    QLineEdit* QLEFamilia;
    QLabel* textLabel4;
    QTextEdit* QTEDscProducto;
    QLabel* textLabel4_2;
    QTextEdit* QTEDscFamilia;
    QLabel* textLabel1;
    QCtrlProductos* QCtrProductos;
    QPushButton* QPBActualizar;
    QGroupBox* groupBox2;
    QLabel* textLabel6;
    QCtrlFamilias* QCtrFamilias;
    QLabel* textLabel3_3;
    QTextEdit* QTEDsc;
    QLabel* textLabel5;
    QLineEdit* QLEClave;
    QLabel* textLabel7;
    QLineEdit* QLEFamSeleccionada;

protected:
    QGridLayout* ActualizaProductosLayout;
    QGridLayout* groupBox1Layout;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;
    QVBoxLayout* layout5;
    QVBoxLayout* layout6;
    QHBoxLayout* layout7;
    QSpacerItem* spacer2;
    QVBoxLayout* layout1;
    QGridLayout* groupBox2Layout;
    QVBoxLayout* layout9;
    QVBoxLayout* layout15;
    QVBoxLayout* layout8;
    QVBoxLayout* layout16;

protected slots:
    virtual void languageChange();

};

#endif // ACTUALIZAPRODUCTOS_H
