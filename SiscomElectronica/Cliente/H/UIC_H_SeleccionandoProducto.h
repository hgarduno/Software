/****************************************************************************
** Form interface generated from reading ui file 'UI/SeleccionandoProducto.ui'
**
** Created: Thu Dec 21 12:53:40 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SELECCIONANDOPRODUCTO_H
#define SELECCIONANDOPRODUCTO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlProductosSE;
class QTextEdit;
class QPushButton;

class SeleccionandoProducto : public QDialog
{
    Q_OBJECT

public:
    SeleccionandoProducto( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SeleccionandoProducto();

    QLabel* textLabel5;
    QCtrlProductosSE* QCtrProductos;
    QTextEdit* QTEDescripcion;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* SeleccionandoProductoLayout;
    QVBoxLayout* layout22;
    QHBoxLayout* layout23;

protected slots:
    virtual void languageChange();

};

#endif // SELECCIONANDOPRODUCTO_H