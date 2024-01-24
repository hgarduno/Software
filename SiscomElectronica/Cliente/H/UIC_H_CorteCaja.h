/****************************************************************************
** Form interface generated from reading ui file 'UI/CorteCaja.ui'
**
** Created: Thu Dec 21 12:53:38 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CORTECAJA_H
#define CORTECAJA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QPushButton;
class QLCDNumber;

class CorteCaja : public QWidget
{
    Q_OBJECT

public:
    CorteCaja( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CorteCaja();

    QLabel* textLabel1;
    QTable* QTVentasPorCaja;
    QLabel* textLabel1_2;
    QTable* QTCorteCaja;
    QPushButton* QPBRangoFechas;
    QPushButton* QPBActualizar;
    QPushButton* QPBADenominacion;
    QPushButton* QPBEDenominacion;
    QPushButton* QBPRegistrarCaja;
    QLabel* textLabel2_2;
    QLCDNumber* QLCDTotalEnCaja;
    QLabel* textLabel2;
    QLCDNumber* QLCDTotal;

protected:
    QGridLayout* CorteCajaLayout;
    QVBoxLayout* layout1;
    QVBoxLayout* layout1_2;
    QHBoxLayout* layout19;
    QVBoxLayout* layout18;
    QVBoxLayout* layout7;
    QVBoxLayout* layout3_2;
    QVBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // CORTECAJA_H
