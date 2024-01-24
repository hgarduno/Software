/****************************************************************************
** Form interface generated from reading ui file 'UI/ReporteVentasCursos.ui'
**
** Created: Thu Dec 21 12:53:39 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPORTEVENTASCURSOS_H
#define REPORTEVENTASCURSOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLCDNumber;
class QPushButton;
class QTable;
class QCtrlProgramacionCursos;

class ReporteVentasCursos : public QWidget
{
    Q_OBJECT

public:
    ReporteVentasCursos( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ReporteVentasCursos();

    QLabel* textLabel2;
    QLCDNumber* QLCDNVTotales;
    QLabel* textLabel2_2;
    QLCDNumber* QLCDNPSiscom;
    QPushButton* pushButton1;
    QPushButton* pushButton1_2;
    QTable* QTVentasCursos;
    QLabel* textLabel1;
    QCtrlProgramacionCursos* QCtrProgramacionCursos;

protected:
    QGridLayout* ReporteVentasCursosLayout;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;
    QHBoxLayout* layout4;
    QVBoxLayout* layout5;

protected slots:
    virtual void languageChange();

};

#endif // REPORTEVENTASCURSOS_H
