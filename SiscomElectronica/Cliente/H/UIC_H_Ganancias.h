/****************************************************************************
** Form interface generated from reading ui file 'UI/Ganancias.ui'
**
** Created: Thu Apr 11 21:39:51 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef GANANCIAS_H
#define GANANCIAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QTable;
class QGroupBox;
class QLabel;
class QLineEdit;

class Ganancias : public QWidget
{
    Q_OBJECT

public:
    Ganancias( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Ganancias();

    QPushButton* QPFechas;
    QTable* QTGFecha;
    QTable* QTGProducto;
    QGroupBox* groupBox1;
    QLabel* textLabel1_2;
    QLineEdit* QLEPeriodo;
    QLabel* textLabel1_2_2;
    QLineEdit* QLETotalVentas;
    QLabel* textLabel1_2_2_2;
    QLineEdit* QLEGanancias;

protected:
    QGridLayout* GananciasLayout;
    QHBoxLayout* layout9;
    QGridLayout* groupBox1Layout;
    QVBoxLayout* layout1_2;
    QVBoxLayout* layout1_2_2;
    QVBoxLayout* layout1_2_2_2;

protected slots:
    virtual void languageChange();

};

#endif // GANANCIAS_H
