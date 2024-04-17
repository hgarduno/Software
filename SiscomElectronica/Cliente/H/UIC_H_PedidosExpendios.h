/****************************************************************************
** Form interface generated from reading ui file 'UI/PedidosExpendios.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PEDIDOSEXPENDIOS_H
#define PEDIDOSEXPENDIOS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class CQControlFecha;
class QTable;
class QTextEdit;
class QPushButton;

class PedidosExpendios : public QWidget
{
    Q_OBJECT

public:
    PedidosExpendios( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PedidosExpendios();

    QLabel* textLabel1;
    CQControlFecha* QCtrFechaInicio;
    QLabel* textLabel2_2;
    CQControlFecha* QCtrFechaFin;
    QLabel* textLabel3;
    QTable* QTPedidos;
    QLabel* textLabel3_2;
    QTextEdit* QTEObservaciones;
    QLabel* textLabel2;
    QTable* QTProductos;
    QPushButton* QPBDesactivaValCantidad;
    QPushButton* QPBImprime;
    QPushButton* QPBConsultaPedidos;
    QPushButton* QPBValidaExistencia;
    QPushButton* QPBAInventario;
    QPushButton* QPBTranBodegaExp;
    QPushButton* QPBTransfiere;

protected:
    QGridLayout* PedidosExpendiosLayout;
    QVBoxLayout* layout9;
    QHBoxLayout* layout25;
    QSpacerItem* spacer1;
    QVBoxLayout* layout23;
    QVBoxLayout* layout24;
    QHBoxLayout* layout15;
    QVBoxLayout* layout12;
    QVBoxLayout* layout14;
    QVBoxLayout* layout11;
    QHBoxLayout* layout28;

protected slots:
    virtual void languageChange();

};

#endif // PEDIDOSEXPENDIOS_H
