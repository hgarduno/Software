/****************************************************************************
** Form interface generated from reading ui file 'UI/Cotizaciones.ui'
**
** Created: Thu Dec 21 12:53:40 2023
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COTIZACIONES_H
#define COTIZACIONES_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QButtonGroup;
class QRadioButton;
class QLabel;
class CQControlFecha;
class QLineEdit;
class QTable;
class QPushButton;
class QTextEdit;
class QLCDNumber;

class Cotizaciones : public QDialog
{
    Q_OBJECT

public:
    Cotizaciones( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~Cotizaciones();

    QButtonGroup* QBGTipoOrden;
    QRadioButton* QRBVentas;
    QRadioButton* QRBCotizaciones;
    QRadioButton* QRBPedidos;
    QLabel* textLabel3;
    CQControlFecha* QCtrFechaInicio;
    QLabel* textLabel3_2;
    CQControlFecha* QCtrFechaFin;
    QLabel* textLabel4;
    QLineEdit* QLEIdOrden;
    QLabel* textLabel1;
    QTable* QTOrdenes;
    QPushButton* QPBConsultar;
    QPushButton* QPBAceptar;
    QPushButton* QPBCancelar;
    QLabel* textLabel2;
    QTable* QTProductos;
    QLabel* textLabel6;
    QTextEdit* QTEDescripcion;
    QLabel* textLabel5;
    QLCDNumber* QLCDNImporte;

protected:
    QGridLayout* CotizacionesLayout;
    QVBoxLayout* layout21;
    QHBoxLayout* layout20;
    QGridLayout* QBGTipoOrdenLayout;
    QHBoxLayout* layout13;
    QVBoxLayout* layout4;
    QVBoxLayout* layout4_2;
    QVBoxLayout* layout5;
    QVBoxLayout* layout3;
    QHBoxLayout* layout19;
    QVBoxLayout* layout6;
    QHBoxLayout* layout19_2;
    QVBoxLayout* layout18;
    QVBoxLayout* layout13_2;

protected slots:
    virtual void languageChange();

};

#endif // COTIZACIONES_H
