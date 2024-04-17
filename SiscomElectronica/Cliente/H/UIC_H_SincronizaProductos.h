/****************************************************************************
** Form interface generated from reading ui file 'UI/SincronizaProductos.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SINCRONIZAPRODUCTOS_H
#define SINCRONIZAPRODUCTOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;

class SincronizaProductos : public QWidget
{
    Q_OBJECT

public:
    SincronizaProductos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SincronizaProductos();

    QPushButton* pushButton1;
    QLabel* textLabel1;
    QTable* table1;

protected:
    QGridLayout* SincronizaProductosLayout;

protected slots:
    virtual void languageChange();

};

#endif // SINCRONIZAPRODUCTOS_H
