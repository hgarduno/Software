/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/ReporteVentas.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REPORTEVENTAS_H
#define REPORTEVENTAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class QCtrlTiendasEntrega;
class QCtrlTipoVentas;
class QTable;
class QPushButton;

class ReporteVentas : public QWidget
{
    Q_OBJECT

public:
    ReporteVentas( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~ReporteVentas();

    QLabel* textLabel1;
    QLineEdit* QLERangoFechas;
    QLabel* textLabel2;
    QCtrlTiendasEntrega* QCtrTiendas;
    QLabel* textLabel3;
    QCtrlTipoVentas* QCtrTipoVentas;
    QLabel* textLabel4;
    QTable* QTVentas;
    QPushButton* QPBConsultando;

protected:
    QGridLayout* ReporteVentasLayout;
    QHBoxLayout* layout4;
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QVBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // REPORTEVENTAS_H
