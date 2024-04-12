/****************************************************************************
** Form interface generated from reading ui file 'UI/ReportandoVentas.ui'
**
** Created: Thu Apr 11 21:39:52 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPORTANDOVENTAS_H
#define REPORTANDOVENTAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QPushButton;
class QTable;
class QLabel;
class CQControlFecha;

class ReportandoVentas : public QWidget
{
    Q_OBJECT

public:
    ReportandoVentas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ReportandoVentas();

    QPushButton* QPBConsultar;
    QTable* table8;
    QLabel* textLabel1;
    CQControlFecha* QCtrFechaInicio;
    QLabel* textLabel1_2;
    CQControlFecha* QCtrFechaFin;

protected:
    QGridLayout* ReportandoVentasLayout;
    QHBoxLayout* layout14;
    QSpacerItem* spacer1;
    QHBoxLayout* layout13;
    QVBoxLayout* layout11;
    QVBoxLayout* layout11_2;

protected slots:
    virtual void languageChange();

};

#endif // REPORTANDOVENTAS_H
