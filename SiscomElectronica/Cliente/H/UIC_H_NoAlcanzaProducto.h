/****************************************************************************
** Form interface generated from reading ui file 'UI/NoAlcanzaProducto.ui'
**
** Created: Thu Apr 11 21:39:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef NOALCANZAPRODUCTO_H
#define NOALCANZAPRODUCTO_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;

class NoAlcanzaProducto : public QDialog
{
    Q_OBJECT

public:
    NoAlcanzaProducto( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~NoAlcanzaProducto();

    QPushButton* QPBAceptar;
    QLabel* textLabel1;
    QTable* QTDatos;

protected:
    QGridLayout* NoAlcanzaProductoLayout;
    QHBoxLayout* layout1;
    QVBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // NOALCANZAPRODUCTO_H
