/****************************************************************************
** Form interface generated from reading ui file 'UI/Devoluciones.ui'
**
** Created: Thu Apr 11 21:39:51 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef DEVOLUCIONES_H
#define DEVOLUCIONES_H

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
class QLCDNumber;

class Devoluciones : public QWidget
{
    Q_OBJECT

public:
    Devoluciones( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Devoluciones();

    QLabel* textLabel1;
    QLineEdit* QLENoOrden;
    QLabel* textLabel1_2;
    QLineEdit* QLEFecha;
    QTable* QTPOrden;
    QLabel* textLabel3;
    QLabel* textLabel2;
    QTable* QTPDevolver;
    QPushButton* QPBDevuelve;
    QPushButton* pushButton1;
    QLabel* textLabel2_2_2;
    QLCDNumber* QLCDNTDevolver;
    QLabel* textLabel2_2;
    QLCDNumber* QLCDNTOrden;

protected:
    QGridLayout* DevolucionesLayout;
    QHBoxLayout* layout4;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QHBoxLayout* layout9;
    QVBoxLayout* layout7;
    QHBoxLayout* layout8;
    QVBoxLayout* layout5_2;
    QVBoxLayout* layout5;

protected slots:
    virtual void languageChange();

};

#endif // DEVOLUCIONES_H
