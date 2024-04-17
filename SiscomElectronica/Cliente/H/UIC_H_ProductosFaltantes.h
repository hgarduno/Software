/****************************************************************************
** Form interface generated from reading ui file 'UI/ProductosFaltantes.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRODUCTOSFALTANTES_H
#define PRODUCTOSFALTANTES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;

class ProductosFaltantes : public QWidget
{
    Q_OBJECT

public:
    ProductosFaltantes( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ProductosFaltantes();

    QPushButton* QPBFaltantes;
    QPushButton* pushButton1_2;
    QLabel* textLabel1;
    QTable* QTDatos;

protected:
    QGridLayout* ProductosFaltantesLayout;
    QHBoxLayout* layout1;
    QVBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // PRODUCTOSFALTANTES_H
