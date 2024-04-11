/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/DesajusteInventario.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DESAJUSTEINVENTARIO_H
#define DESAJUSTEINVENTARIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlTiendasEntrega;
class QTable;
class QPushButton;

class DesajusteInventario : public QWidget
{
    Q_OBJECT

public:
    DesajusteInventario( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~DesajusteInventario();

    QLabel* textLabel4;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel5;
    QTable* table5;
    QLabel* textLabel6;
    QTable* table6;
    QPushButton* pushButton17;
    QPushButton* pushButton17_2;
    QPushButton* pushButton17_2_2;

protected:
    QGridLayout* DesajusteInventarioLayout;
    QVBoxLayout* layout71;
    QVBoxLayout* layout72;
    QVBoxLayout* layout73;
    QHBoxLayout* layout74;

protected slots:
    virtual void languageChange();

};

#endif // DESAJUSTEINVENTARIO_H
