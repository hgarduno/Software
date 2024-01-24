/****************************************************************************
** Form interface generated from reading ui file 'UI/ControladorReportesVentasExpendios.ui'
**
** Created: Thu Dec 21 12:53:16 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef CONTROLADORREPORTESVENTASEXPENDIOS_H
#define CONTROLADORREPORTESVENTASEXPENDIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QTable;
class QLineEdit;
class CQControlFecha;
class QPushButton;

class ControladorReportesVentasExpendios : public QWidget
{
    Q_OBJECT

public:
    ControladorReportesVentasExpendios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ControladorReportesVentasExpendios();

    QLabel* textLabel1;
    QTable* QTExpendios;
    QLabel* textLabel2;
    QLineEdit* QLEPeriodo;
    QLabel* textLabel3;
    CQControlFecha* QCtrFechaIni;
    QLabel* textLabel3_2;
    CQControlFecha* QCtrFechaFin;
    QPushButton* QPBIniMuestreo;
    QPushButton* QPBDetenMuestreo;

protected:
    QGridLayout* ControladorReportesVentasExpendiosLayout;
    QVBoxLayout* layout10;
    QHBoxLayout* layout15;
    QVBoxLayout* layout11;
    QVBoxLayout* layout12;
    QVBoxLayout* layout12_2;
    QHBoxLayout* layout16;

protected slots:
    virtual void languageChange();

};

#endif // CONTROLADORREPORTESVENTASEXPENDIOS_H
