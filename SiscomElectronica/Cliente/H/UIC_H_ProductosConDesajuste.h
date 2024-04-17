/****************************************************************************
** Form interface generated from reading ui file 'UI/ProductosConDesajuste.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRODUCTOSCONDESAJUSTE_H
#define PRODUCTOSCONDESAJUSTE_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;

class ProductosConDesajuste : public QDialog
{
    Q_OBJECT

public:
    ProductosConDesajuste( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ProductosConDesajuste();

    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel2;
    QTable* QTDatos;

protected:
    QGridLayout* ProductosConDesajusteLayout;
    QHBoxLayout* layout22;
    QVBoxLayout* layout23;

protected slots:
    virtual void languageChange();

};

#endif // PRODUCTOSCONDESAJUSTE_H
