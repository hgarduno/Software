/****************************************************************************
** Form interface generated from reading ui file 'UI/PuntosAlumnos.ui'
**
** Created: Wed Apr 10 20:52:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PUNTOSALUMNOS_H
#define PUNTOSALUMNOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlAlumnos;
class QLCDNumber;
class QTable;
class QPushButton;

class PuntosAlumnos : public QWidget
{
    Q_OBJECT

public:
    PuntosAlumnos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PuntosAlumnos();

    QLabel* textLabel1;
    QCtrlAlumnos* QCtrAlumnos;
    QLCDNumber* QLCDNPuntos;
    QLabel* textLabel2;
    QTable* QTDatos;
    QLabel* textLabel3_2;
    QLCDNumber* QLCDNPPSel;
    QLabel* textLabel3_2_2;
    QLCDNumber* QLCDNSaldo;
    QLabel* textLabel3_2_2_2;
    QLCDNumber* QLCDNSaldo_2;
    QPushButton* QPBValidaPSel;
    QPushButton* QPBTomaPromocion;
    QPushButton* QPBReInicia;
    QPushButton* QPBRPSeleccionadas_2;
    QPushButton* QPBRPSeleccionadas_3_2;

protected:
    QGridLayout* PuntosAlumnosLayout;
    QHBoxLayout* layout4;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QVBoxLayout* layout21;
    QVBoxLayout* layout16;
    QHBoxLayout* layout20;
    QVBoxLayout* layout16_2;
    QVBoxLayout* layout16_2_2;
    QVBoxLayout* layout15;
    QHBoxLayout* layout14;

protected slots:
    virtual void languageChange();

};

#endif // PUNTOSALUMNOS_H
