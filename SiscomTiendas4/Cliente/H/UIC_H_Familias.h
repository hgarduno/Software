/****************************************************************************
** Form interface generated from reading ui file 'UI/Familias.ui'
**
** Created: Thu Apr 11 22:09:35 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FAMILIAS_H
#define FAMILIAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QTextEdit;
class QTable;
class QPushButton;

class Familias : public QWidget
{
    Q_OBJECT

public:
    Familias( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Familias();

    QLabel* textLabel1;
    QLineEdit* QLEFamilia;
    QLabel* textLabel2;
    QTextEdit* QTEDsc;
    QLabel* textLabel3;
    QTable* QTDatos;
    QPushButton* QPBAnexar;
    QPushButton* pushButton1_2;
    QPushButton* pushButton1_2_2;

protected:
    QGridLayout* FamiliasLayout;
    QHBoxLayout* layout4;
    QSpacerItem* spacer1;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QVBoxLayout* layout5;
    QHBoxLayout* layout6;

protected slots:
    virtual void languageChange();

};

#endif // FAMILIAS_H
