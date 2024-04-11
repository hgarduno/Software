/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/SeleccionaProducto.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SELECCIONAPRODUCTO_H
#define SELECCIONAPRODUCTO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProductosSS;
class QLineEdit;
class QPushButton;
class QTable;

class SeleccionaProducto : public QDialog
{
    Q_OBJECT

public:
    SeleccionaProducto( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SeleccionaProducto();

    QLabel* textLabel1;
    QCtrlProductosSS* QCtrProductos;
    QLabel* textLabel1_2;
    QLineEdit* lineEdit79;
    QLabel* textLabel4;
    QLineEdit* lineEdit80;
    QLabel* textLabel5;
    QLineEdit* lineEdit81;
    QLabel* textLabel6;
    QLineEdit* lineEdit82;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel3;
    QTable* QTProductos;

protected:
    QGridLayout* SeleccionaProductoLayout;
    QVBoxLayout* layout54;
    QHBoxLayout* layout49;
    QVBoxLayout* layout40;
    QVBoxLayout* layout41;
    QHBoxLayout* layout356;
    QVBoxLayout* layout42;
    QVBoxLayout* layout43;
    QHBoxLayout* layout89;
    QVBoxLayout* layout76;

protected slots:
    virtual void languageChange();

};

#endif // SELECCIONAPRODUCTO_H
