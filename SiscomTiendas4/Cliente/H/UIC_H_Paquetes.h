/****************************************************************************
** Form interface generated from reading ui file 'UI/Paquetes.ui'
**
** Created: Thu Apr 11 20:30:19 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PAQUETES_H
#define PAQUETES_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QLineEdit;
class QTextEdit;
class QCtrlProductos3Qt;
class QPushButton;
class QLCDNumber;

class Paquetes : public QWidget
{
    Q_OBJECT

public:
    Paquetes( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Paquetes();

    QLabel* textLabel3;
    QTable* QTDatos;
    QLabel* textLabel1_2;
    QLineEdit* QLEClave;
    QLabel* textLabel2;
    QTextEdit* QTEDescripcionP;
    QLabel* textLabel1;
    QCtrlProductos3Qt* QCtrProductos;
    QLabel* textLabel4;
    QLineEdit* QLECantidad;
    QLabel* textLabel2_2;
    QTextEdit* QTEDescripcion;
    QPushButton* QPBRegistra;
    QPushButton* QPBRProductos;
    QPushButton* QPBAnexar;
    QPushButton* pushButton3_3;
    QLCDNumber* lCDNumber1;

protected:
    QGridLayout* PaquetesLayout;
    QVBoxLayout* layout12;
    QHBoxLayout* layout22;
    QVBoxLayout* layout21;
    QVBoxLayout* layout9;
    QVBoxLayout* layout3;
    QVBoxLayout* layout19;
    QVBoxLayout* layout1;
    QHBoxLayout* layout18;
    QSpacerItem* spacer1;
    QVBoxLayout* layout17;
    QVBoxLayout* layout3_2;
    QHBoxLayout* layout25;
    QVBoxLayout* layout24;
    QHBoxLayout* layout23;

protected slots:
    virtual void languageChange();

};

#endif // PAQUETES_H
