/****************************************************************************
** Form interface generated from reading ui file 'UI/ManejadorKits.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef MANEJADORKITS_H
#define MANEJADORKITS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTextEdit;
class QTable;
class QComboBox;
class QLineEdit;
class QCtrlTiposProductoSE;

class ManejadorKits : public QWidget
{
    Q_OBJECT

public:
    ManejadorKits( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ManejadorKits();

    QPushButton* QPBRegistraKit;
    QPushButton* QPBAnexar;
    QPushButton* QPBEliminaProducto;
    QPushButton* QPBRegistraProductos;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcion;
    QTable* QTProductos;
    QLabel* textLabel1;
    QComboBox* QCBProductos;
    QLabel* textLabel3;
    QLineEdit* QLECantidad;
    QLabel* textLabel1_2;
    QCtrlTiposProductoSE* QCtrTiposProducto;
    QLabel* textLabel2_2;
    QLineEdit* QLEProductoTipoProducto;
    QLabel* textLabel2_3;

protected:
    QGridLayout* ManejadorKitsLayout;
    QHBoxLayout* layout33;
    QHBoxLayout* layout15;
    QVBoxLayout* layout2;
    QHBoxLayout* layout24;
    QVBoxLayout* layout9;
    QVBoxLayout* layout8;
    QHBoxLayout* layout25;
    QVBoxLayout* layout23;
    QVBoxLayout* layout17;

protected slots:
    virtual void languageChange();

};

#endif // MANEJADORKITS_H
