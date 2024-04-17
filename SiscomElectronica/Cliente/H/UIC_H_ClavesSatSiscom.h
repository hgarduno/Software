/****************************************************************************
** Form interface generated from reading ui file 'UI/ClavesSatSiscom.ui'
**
** Created: Fri Apr 12 21:25:59 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CLAVESSATSISCOM_H
#define CLAVESSATSISCOM_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCtrlProductosSE;
class QTextEdit;
class QPushButton;

class ClavesSatSiscom : public QWidget
{
    Q_OBJECT

public:
    ClavesSatSiscom( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ClavesSatSiscom();

    QLabel* textLabel5;
    QLabel* textLabel4;
    QLineEdit* QLEClaveSatReg;
    QLabel* textLabel4_2;
    QLineEdit* QLEPalabraClaveReg;
    QLabel* textLabel1;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel4_3;
    QLineEdit* QLEClaveSat;
    QLabel* textLabel4_2_2;
    QLineEdit* QLEPalabraClave;
    QLabel* textLabel3;
    QTextEdit* QTEDescripcion;
    QPushButton* pushButton2;
    QPushButton* QPBRegistrar;

protected:
    QGridLayout* ClavesSatSiscomLayout;
    QVBoxLayout* layout6;
    QHBoxLayout* layout5;
    QVBoxLayout* layout3;
    QVBoxLayout* layout3_2;
    QVBoxLayout* layout11;
    QHBoxLayout* layout10;
    QVBoxLayout* layout1;
    QHBoxLayout* layout5_2;
    QVBoxLayout* layout3_3;
    QVBoxLayout* layout3_2_2;
    QVBoxLayout* layout2;

protected slots:
    virtual void languageChange();

};

#endif // CLAVESSATSISCOM_H
