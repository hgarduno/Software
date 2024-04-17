/****************************************************************************
** Form interface generated from reading ui file 'UI/Caja.ui'
**
** Created: Fri Apr 12 21:36:40 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CAJA_H
#define CAJA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;
class QCtrlOrdenes;
class QTable;
class QPushButton;
class QLCDNumber;

class Caja : public QWidget
{
    Q_OBJECT

public:
    Caja( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~Caja();

    QLabel* textLabel1;
    CQControlFecha* QCtrFechaIni;
    QLabel* textLabel1_2;
    CQControlFecha* QCtrFechaFin;
    QLabel* textLabel4;
    QCtrlOrdenes* QCtrOrdenes;
    QLabel* textLabel2_4;
    QTable* QTDatos;
    QPushButton* QPBOrdenes;
    QPushButton* pushButton13;
    QPushButton* pushButton13_2;
    QPushButton* pushButton13_2_2;
    QPushButton* QPBMOrden;
    QPushButton* QPBRVenta;
    QLabel* textLabel2_4_2;
    QLCDNumber* QLCDNTotal;

protected:
    QGridLayout* CajaLayout;
    QHBoxLayout* layout28;
    QSpacerItem* spacer1;
    QVBoxLayout* layout26;
    QVBoxLayout* layout26_2;
    QVBoxLayout* layout25;
    QVBoxLayout* layout44;
    QHBoxLayout* layout47;
    QHBoxLayout* layout46;
    QVBoxLayout* layout43;
    QVBoxLayout* layout55;

protected slots:
    virtual void languageChange();

};

#endif // CAJA_H
