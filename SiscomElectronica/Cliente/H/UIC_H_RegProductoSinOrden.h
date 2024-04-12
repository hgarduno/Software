/****************************************************************************
** Form interface generated from reading ui file 'UI/RegProductoSinOrden.ui'
**
** Created: Thu Apr 11 21:39:51 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGPRODUCTOSINORDEN_H
#define REGPRODUCTOSINORDEN_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTextEdit;
class QCtrlProdSiscomElectronica;
class QLineEdit;
class QPushButton;

class RegProductoSinOrden : public QDialog
{
    Q_OBJECT

public:
    RegProductoSinOrden( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~RegProductoSinOrden();

    QLabel* textLabel3;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel2;
    QCtrlProdSiscomElectronica* QCtrProductos;
    QLabel* textLabel4;
    QLineEdit* QLEProducto;
    QPushButton* QPBRegistrar;
    QPushButton* QPBCancelar;

protected:
    QGridLayout* RegProductoSinOrdenLayout;
    QSpacerItem* spacer1;
    QVBoxLayout* layout18;
    QVBoxLayout* layout14;
    QVBoxLayout* layout15;
    QHBoxLayout* layout23;

protected slots:
    virtual void languageChange();

};

#endif // REGPRODUCTOSINORDEN_H
