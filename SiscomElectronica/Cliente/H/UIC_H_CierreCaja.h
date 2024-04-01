/****************************************************************************
** Form interface generated from reading ui file 'UI/CierreCaja.ui'
**
** Created: Wed Jan 31 10:48:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CIERRECAJA_H
#define CIERRECAJA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QLineEdit;
class QPushButton;

class CierreCaja : public QWidget
{
    Q_OBJECT

public:
    CierreCaja( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CierreCaja();

    QLabel* textLabel1;
    QTable* table1;
    QLineEdit* lineEdit1;
    QLabel* textLabel2_2;
    QTable* table1_2_2;
    QLineEdit* lineEdit1_2_2;
    QLabel* textLabel2;
    QTable* table1_2;
    QLineEdit* lineEdit1_2;
    QPushButton* pushButton1;
    QPushButton* pushButton1_2;

protected:
    QGridLayout* CierreCajaLayout;
    QHBoxLayout* layout10;
    QVBoxLayout* layout5;
    QVBoxLayout* layout2;
    QHBoxLayout* layout1;
    QSpacerItem* spacer1;
    QVBoxLayout* layout6_2;
    QVBoxLayout* layout2_2_2;
    QHBoxLayout* layout1_2_2;
    QSpacerItem* spacer1_2_2;
    QVBoxLayout* layout6;
    QVBoxLayout* layout2_2;
    QHBoxLayout* layout1_2;
    QSpacerItem* spacer1_2;
    QHBoxLayout* layout11;

protected slots:
    virtual void languageChange();

};

#endif // CIERRECAJA_H
