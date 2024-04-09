/****************************************************************************
** Form interface generated from reading ui file 'UI/ProductosSinSincronizar.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRODUCTOSSINSINCRONIZAR_H
#define PRODUCTOSSINSINCRONIZAR_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;

class ProductosSinSincronizar : public QWidget
{
    Q_OBJECT

public:
    ProductosSinSincronizar( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ProductosSinSincronizar();

    QLabel* textLabel1;
    QTable* QTProdNoSincronizados;
    QPushButton* QPBRegistra;
    QPushButton* pushButton1_2;

protected:
    QGridLayout* ProductosSinSincronizarLayout;
    QHBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // PRODUCTOSSINSINCRONIZAR_H
