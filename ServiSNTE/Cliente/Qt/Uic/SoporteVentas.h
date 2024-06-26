/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/SoporteVentas.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SOPORTEVENTAS_H
#define SOPORTEVENTAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlTiendasEntrega;
class QLineEdit;
class QCtrlSoporteVentas;
class QPushButton;

class SoporteVentas : public QWidget
{
    Q_OBJECT

public:
    SoporteVentas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SoporteVentas();

    QLabel* textLabel1;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel2;
    QLineEdit* QLERangoFechas;
    QCtrlSoporteVentas* QCtrSoporteVentas;
    QPushButton* QPBImprimir;
    QPushButton* pushButton2;

protected:
    QGridLayout* SoporteVentasLayout;
    QVBoxLayout* layout11;
    QHBoxLayout* layout10;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QHBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // SOPORTEVENTAS_H
