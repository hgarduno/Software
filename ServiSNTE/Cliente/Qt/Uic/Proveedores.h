/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/Proveedores.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PROVEEDORES_H
#define PROVEEDORES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QPushButton;
class QTextEdit;

class Proveedores : public QWidget
{
    Q_OBJECT

public:
    Proveedores( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Proveedores();

    QLabel* textLabel1;
    QLineEdit* lineEdit49;
    QLabel* textLabel2;
    QLineEdit* lineEdit50;
    QPushButton* pushButton10;
    QPushButton* pushButton10_2;
    QPushButton* pushButton10_2_2;
    QLabel* textLabel2_2;
    QTextEdit* textEdit2;
    QLabel* textLabel3;
    QLineEdit* lineEdit24;
    QLabel* textLabel3_2;
    QLineEdit* lineEdit24_2;
    QLabel* textLabel3_3;
    QLineEdit* lineEdit24_3;
    QLabel* textLabel3_5;
    QLineEdit* lineEdit24_5;
    QLabel* textLabel3_5_2;
    QLineEdit* lineEdit24_5_2;
    QLabel* textLabel3_5_4;
    QLineEdit* lineEdit24_5_4;
    QLabel* textLabel3_5_3;
    QLineEdit* lineEdit24_5_3;
    QLabel* textLabel3_5_3_2_2;
    QLineEdit* lineEdit24_5_3_2_2;
    QLabel* textLabel3_5_3_2;
    QLineEdit* lineEdit24_5_3_2;

protected:
    QGridLayout* ProveedoresLayout;
    QHBoxLayout* layout6;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QHBoxLayout* layout62;
    QVBoxLayout* layout42;
    QHBoxLayout* layout46;
    QVBoxLayout* layout43;
    QVBoxLayout* layout43_2;
    QVBoxLayout* layout43_3;
    QHBoxLayout* layout67;
    QVBoxLayout* layout43_5;
    QVBoxLayout* layout43_5_2;
    QVBoxLayout* layout43_5_4;
    QVBoxLayout* layout43_5_3;
    QHBoxLayout* layout70;
    QVBoxLayout* layout43_5_3_2_2;
    QVBoxLayout* layout43_5_3_2;

protected slots:
    virtual void languageChange();

};

#endif // PROVEEDORES_H
