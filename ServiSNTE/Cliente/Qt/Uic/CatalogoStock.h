/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/CatalogoStock.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CATALOGOSTOCK_H
#define CATALOGOSTOCK_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class QTabWidget;
class QCtrlTiendasEntrega;

class CatalogoStock : public QWidget
{
    Q_OBJECT

public:
    CatalogoStock( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CatalogoStock();

    QLabel* textLabel1;
    QTable* QTProductos;
    QPushButton* PushButton1;
    QPushButton* PushButton2;
    QPushButton* PushButton3;
    QPushButton* PushButton4;
    QTabWidget* tabWidget2;
    QWidget* tab;
    QLabel* textLabel2;
    QCtrlTiendasEntrega* CtrTiendas;
    QWidget* tab_2;

protected:
    QVBoxLayout* layout2;
    QHBoxLayout* layout8;
    QGridLayout* tabLayout;
    QVBoxLayout* layout6;

protected slots:
    virtual void languageChange();

};

#endif // CATALOGOSTOCK_H
