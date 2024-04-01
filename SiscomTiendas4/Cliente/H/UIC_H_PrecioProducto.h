/****************************************************************************
** Form interface generated from reading ui file 'UI/PrecioProducto.ui'
**
** Created: Sun Jan 28 16:00:48 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRECIOPRODUCTO_H
#define PRECIOPRODUCTO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlPrecios;
class QCtrlProductos;
class QPushButton;
class QTable;
class QTextEdit;
class QLineEdit;

class PrecioProducto : public QWidget
{
    Q_OBJECT

public:
    PrecioProducto( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PrecioProducto();

    QLabel* textLabel1;
    QCtrlPrecios* QCtrPrecios;
    QLabel* textLabel2;
    QCtrlProductos* QCtrProductos;
    QPushButton* QPBActualiza;
    QPushButton* QPBIniciaPrecios;
    QPushButton* pushButton4;
    QLabel* textLabel4_2;
    QTable* QTDatos;
    QLabel* textLabel4;
    QTextEdit* QTEDscProducto;
    QLabel* textLabel4_3;
    QTextEdit* QTEDscPrecio;
    QLabel* textLabel3;
    QLineEdit* QLEPrecio;
    QLabel* textLabel3_2;
    QLineEdit* QLECantidad;

protected:
    QGridLayout* PrecioProductoLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QHBoxLayout* layout15;
    QVBoxLayout* layout17;
    QVBoxLayout* layout17_2;
    QHBoxLayout* layout9;
    QSpacerItem* spacer2;
    QVBoxLayout* layout3;
    QVBoxLayout* layout3_2;

protected slots:
    virtual void languageChange();

};

#endif // PRECIOPRODUCTO_H
