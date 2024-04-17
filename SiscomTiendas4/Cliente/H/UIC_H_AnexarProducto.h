/****************************************************************************
** Form interface generated from reading ui file 'UI/AnexarProducto.ui'
**
** Created: Fri Apr 12 21:36:40 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef ANEXARPRODUCTO_H
#define ANEXARPRODUCTO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProductos3Qt;
class QLineEdit;
class QTextEdit;
class QPushButton;

class AnexarProducto : public QDialog
{
    Q_OBJECT

public:
    AnexarProducto( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~AnexarProducto();

    QLabel* textLabel1;
    QCtrlProductos3Qt* QCtrProductos;
    QLabel* textLabel4;
    QLineEdit* QLECantidad;
    QLabel* textLabel2_2;
    QTextEdit* QTEDescripcion;
    QPushButton* QPBAnexar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* AnexarProductoLayout;
    QVBoxLayout* layout19;
    QVBoxLayout* layout1;
    QHBoxLayout* layout18;
    QSpacerItem* spacer1;
    QVBoxLayout* layout17;
    QVBoxLayout* layout3_2;
    QHBoxLayout* layout26;

protected slots:
    virtual void languageChange();

};

#endif // ANEXARPRODUCTO_H
