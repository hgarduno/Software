/****************************************************************************
** Form interface generated from reading ui file 'UI/VentasPorCaja.ui'
**
** Created: Thu Dec 21 12:53:38 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef VENTASPORCAJA_H
#define VENTASPORCAJA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QPushButton;
class QLCDNumber;

class VentasPorCaja : public QWidget
{
    Q_OBJECT

public:
    VentasPorCaja( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~VentasPorCaja();

    QTable* QTDatos;
    QPushButton* QPBRangoFechas;
    QPushButton* QPBADatos;
    QLCDNumber* QLCDTotalVentas;

protected:
    QGridLayout* VentasPorCajaLayout;
    QHBoxLayout* layout21;
    QVBoxLayout* layout20;

protected slots:
    virtual void languageChange();

};

#endif // VENTASPORCAJA_H
