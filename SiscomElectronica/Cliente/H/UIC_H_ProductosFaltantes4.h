/****************************************************************************
** Form interface generated from reading ui file 'UI/ProductosFaltantes4.ui'
**
** Created: Wed Jan 31 10:48:06 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRODUCTOSFALTANTES4_H
#define PRODUCTOSFALTANTES4_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class ProductosFaltantes4 : public QDialog
{
    Q_OBJECT

public:
    ProductosFaltantes4( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~ProductosFaltantes4();

    QLabel* textLabel1;
    QTable* table6;
    QLabel* textLabel3;
    QTable* QTDatos;
    QLabel* textLabel5;
    QTable* QTOrdenCompra;
    QPushButton* pushButton3;
    QPushButton* pushButton4;

protected:
    QGridLayout* ProductosFaltantes4Layout;
    QVBoxLayout* layout21;
    QVBoxLayout* layout12;
    QVBoxLayout* layout32;
    QHBoxLayout* layout22;

protected slots:
    virtual void languageChange();

};

#endif // PRODUCTOSFALTANTES4_H
