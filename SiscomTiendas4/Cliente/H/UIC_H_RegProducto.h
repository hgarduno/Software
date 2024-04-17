/****************************************************************************
** Form interface generated from reading ui file 'UI/RegProducto.ui'
**
** Created: Fri Apr 12 21:36:40 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGPRODUCTO_H
#define REGPRODUCTO_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlFamilias;
class QLineEdit;
class QTextEdit;
class QPushButton;

class RegProducto : public QWidget
{
    Q_OBJECT

public:
    RegProducto( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegProducto();

    QLabel* textLabel2_2;
    QCtrlFamilias* QCtrFamilias;
    QLabel* textLabel2;
    QLineEdit* QLEClave;
    QLabel* textLabel3;
    QTextEdit* QTEDsc;
    QPushButton* QPBRegistra;

protected:
    QGridLayout* RegProductoLayout;
    QVBoxLayout* layout5;
    QHBoxLayout* layout4;
    QVBoxLayout* layout3;
    QVBoxLayout* layout14;
    QVBoxLayout* layout15;

protected slots:
    virtual void languageChange();

};

#endif // REGPRODUCTO_H
