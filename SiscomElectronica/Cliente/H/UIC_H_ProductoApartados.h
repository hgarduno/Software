/****************************************************************************
** Form interface generated from reading ui file 'UI/ProductoApartados.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRODUCTOAPARTADOS_H
#define PRODUCTOAPARTADOS_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;

class ProductoApartados : public QDialog
{
    Q_OBJECT

public:
    ProductoApartados( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ProductoApartados();

    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel1;
    QTable* QTApartados;

protected:
    QGridLayout* ProductoApartadosLayout;
    QHBoxLayout* layout8;
    QVBoxLayout* layout9;

protected slots:
    virtual void languageChange();

};

#endif // PRODUCTOAPARTADOS_H
