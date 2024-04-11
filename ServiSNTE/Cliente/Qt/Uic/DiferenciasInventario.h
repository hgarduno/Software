/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/DiferenciasInventario.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DIFERENCIASINVENTARIO_H
#define DIFERENCIASINVENTARIO_H

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

class DiferenciasInventario : public QWidget
{
    Q_OBJECT

public:
    DiferenciasInventario( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~DiferenciasInventario();

    QLabel* textLabel1;
    QCtrlTiendasEntrega* ctrlTiendasEntrega1;
    QTable* table1;
    QTable* table2;
    QPushButton* pushButton1;
    QPushButton* pushButton1_2;
    QPushButton* pushButton1_2_2;
    QPushButton* pushButton1_2_2_2;
    QPushButton* pushButton1_2_2_2_2;

protected:
    QGridLayout* DiferenciasInventarioLayout;
    QVBoxLayout* layout1;

protected slots:
    virtual void languageChange();

};

#endif // DIFERENCIASINVENTARIO_H
