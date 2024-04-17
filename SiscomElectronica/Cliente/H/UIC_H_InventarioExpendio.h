/****************************************************************************
** Form interface generated from reading ui file 'UI/InventarioExpendio.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef INVENTARIOEXPENDIO_H
#define INVENTARIOEXPENDIO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;
class QCtrlProductosSE;
class QLineEdit;
class CQControlFecha;
class QTextEdit;

class InventarioExpendio : public QWidget
{
    Q_OBJECT

public:
    InventarioExpendio( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~InventarioExpendio();

    QPushButton* pushButton1;
    QPushButton* pushButton2;
    QLabel* textLabel1_2;
    QTable* table1;
    QLabel* textLabel1;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel2;
    QLineEdit* lineEdit1;
    QLabel* textLabel2_2;
    CQControlFecha* cQControlFecha1;
    QLabel* textLabel3;
    QTextEdit* textEdit1;

protected:
    QGridLayout* InventarioExpendioLayout;
    QHBoxLayout* layout8;
    QVBoxLayout* layout6;
    QHBoxLayout* layout10;
    QVBoxLayout* layout9;
    QVBoxLayout* layout5;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QHBoxLayout* layout8_2;
    QSpacerItem* spacer2;
    QVBoxLayout* layout7;
    QVBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // INVENTARIOEXPENDIO_H
