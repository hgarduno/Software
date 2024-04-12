/****************************************************************************
** Form interface generated from reading ui file 'UI/ProductosInventariar.ui'
**
** Created: Thu Apr 11 21:53:28 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRODUCTOSINVENTARIAR_H
#define PRODUCTOSINVENTARIAR_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QPushButton;
class QTable;
class QLineEdit;

class ProductosInventariar : public QWidget
{
    Q_OBJECT

public:
    ProductosInventariar( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ProductosInventariar();

    QLabel* textLabel1;
    QComboBox* comboBox1;
    QPushButton* pushButton3;
    QPushButton* pushButton3_2;
    QPushButton* pushButton2;
    QTable* table2_2;
    QLabel* textLabel2;
    QTable* table2;
    QLabel* textLabel3;
    QLineEdit* lineEdit1;

protected:
    QGridLayout* ProductosInventariarLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // PRODUCTOSINVENTARIAR_H
