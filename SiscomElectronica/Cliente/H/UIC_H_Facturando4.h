/****************************************************************************
** Form interface generated from reading ui file 'UI/Facturando4.ui'
**
** Created: lun abr 1 18:57:47 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef FACTURANDO4_H
#define FACTURANDO4_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QLabel;
class QTable;
class QLCDNumber;
class QTextEdit;

class Facturando4 : public QWidget
{
    Q_OBJECT

public:
    Facturando4( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Facturando4();

    QPushButton* QPBOrdenesFecha;
    QPushButton* QPBDatosFacturacion;
    QPushButton* QPBRealizaFactura;
    QLabel* textLabel1;
    QTable* QTFactura;
    QLabel* textLabel5_2_2;
    QLCDNumber* QLCDNImporte;
    QLabel* textLabel5;
    QLCDNumber* QLCDNTotal;
    QLabel* textLabel5_2;
    QLCDNumber* QLCDNIva;
    QLabel* textLabel4;
    QTextEdit* QTEDatos;

protected:
    QGridLayout* Facturando4Layout;
    QVBoxLayout* layout2;
    QHBoxLayout* layout18;
    QVBoxLayout* layout15_2_2;
    QVBoxLayout* layout15;
    QVBoxLayout* layout15_2;
    QVBoxLayout* layout6;

protected slots:
    virtual void languageChange();

};

#endif // FACTURANDO4_H
