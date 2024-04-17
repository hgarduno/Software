/****************************************************************************
** Form interface generated from reading ui file 'UI/RegistroProductosSiscom.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROPRODUCTOSSISCOM_H
#define REGISTROPRODUCTOSSISCOM_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QCtrlProductosSE;
class QLineEdit;
class QPushButton;

class RegistroProductosSiscom : public QWidget
{
    Q_OBJECT

public:
    RegistroProductosSiscom( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroProductosSiscom();

    QLabel* textLabel3;
    QTable* QTDefProducto;
    QLabel* textLabel1;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel4;
    QLineEdit* QLECantidad;
    QPushButton* QPBBodega;
    QPushButton* QPBExpendio;
    QPushButton* QPBRegistrar;

protected:
    QGridLayout* RegistroProductosSiscomLayout;
    QVBoxLayout* layout2;
    QVBoxLayout* layout1;
    QVBoxLayout* layout3;
    QHBoxLayout* layout18;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROPRODUCTOSSISCOM_H
