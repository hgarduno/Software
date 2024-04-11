/****************************************************************************
** Form interface generated from reading ui file 'UI/CierreDia.ui'
**
** Created: Wed Apr 10 20:52:31 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CIERREDIA_H
#define CIERREDIA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;
class QPushButton;
class QLineEdit;
class QTable;
class QLCDNumber;

class CierreDia : public QWidget
{
    Q_OBJECT

public:
    CierreDia( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CierreDia();

    QLabel* textLabel3;
    CQControlFecha* QCtrFechaInicio;
    QLabel* textLabel3_2;
    CQControlFecha* QCtrFechaFin;
    QPushButton* QPBSeleccionarExpendio;
    QPushButton* QPBConsulta;
    QPushButton* QPBSeleccionarExpendio_2;
    QLabel* textLabel2;
    QLineEdit* lineEdit10;
    QLabel* textLabel2_3;
    QLineEdit* lineEdit10_3;
    QLabel* textLabel2_2;
    QLineEdit* lineEdit10_2;
    QLabel* textLabel2_2_2;
    QLineEdit* lineEdit10_2_2;
    QLabel* textLabel2_4;
    QLineEdit* QLEVentasEfectivo;
    QLabel* textLabel2_3_2;
    QLineEdit* QLEVentasTarjeta;
    QLabel* textLabel2_2_3;
    QLineEdit* QLEVentasPedidos;
    QTable* table16;
    QLabel* textLabel1;
    QLCDNumber* QLCDNTotal;

protected:
    QGridLayout* CierreDiaLayout;
    QHBoxLayout* layout65;
    QSpacerItem* spacer11;
    QHBoxLayout* layout12;
    QVBoxLayout* layout10;
    QVBoxLayout* layout10_2;
    QHBoxLayout* layout67;
    QHBoxLayout* layout63;
    QVBoxLayout* layout59;
    QVBoxLayout* layout59_3;
    QVBoxLayout* layout59_2;
    QVBoxLayout* layout59_2_2;
    QHBoxLayout* layout74;
    QVBoxLayout* layout73;
    QHBoxLayout* layout63_2;
    QVBoxLayout* layout59_4;
    QVBoxLayout* layout59_3_2;
    QVBoxLayout* layout59_2_3;
    QVBoxLayout* layout57;

protected slots:
    virtual void languageChange();

};

#endif // CIERREDIA_H
