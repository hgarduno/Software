/****************************************************************************
** Form interface generated from reading ui file 'UI/Pruebas.ui'
**
** Created: Tue Dec 16 23:52:49 2014
**      by: The User Interface Compiler ($Id: qt/main.cpp   3.3.8   edited Jan 11 14:47 $)
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PRUEBAS_H
#define PRUEBAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTable;
class QPushButton;

class Pruebas : public QWidget
{
    Q_OBJECT

public:
    Pruebas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Pruebas();

    QLabel* textLabel1;
    QLineEdit* lineEdit1;
    QLabel* textLabel2;
    QLineEdit* lineEdit2;
    QLabel* textLabel3;
    QTable* table1;
    QPushButton* pushButton1;
    QPushButton* pushButton1_2;
    QPushButton* pushButton1_3;

protected:
    QGridLayout* PruebasLayout;
    QHBoxLayout* layout3;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QVBoxLayout* layout4;
    QHBoxLayout* layout5;

protected slots:
    virtual void languageChange();

};

#endif // PRUEBAS_H
