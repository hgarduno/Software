/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/SoporteCompras.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SOPORTECOMPRAS_H
#define SOPORTECOMPRAS_H

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

class SoporteCompras : public QWidget
{
    Q_OBJECT

public:
    SoporteCompras( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~SoporteCompras();

    QLabel* textLabel1;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel2;
    QLineEdit* QLERangoFechas;
    QCtrlSoporteVentas* QCtrSoporteVentas;
    QPushButton* QPBImprimir;
    QPushButton* pushButton2;

protected:
    QGridLayout* SoporteComprasLayout;
    QVBoxLayout* layout6;
    QVBoxLayout* layout5;
    QHBoxLayout* layout4;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QHBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // SOPORTECOMPRAS_H
