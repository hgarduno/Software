/****************************************************************************
** Form interface generated from reading ui file 'UI/SeleccionaOrdenFactura.ui'
**
** Created: Fri Apr 12 21:25:58 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef SELECCIONAORDENFACTURA_H
#define SELECCIONAORDENFACTURA_H

#include <qvariant.h>
#include <qdialog.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QLineEdit;
class CQControlFecha;
class QTable;
class QPushButton;

class SeleccionaOrdenFactura : public QDialog
{
    Q_OBJECT

public:
    SeleccionaOrdenFactura( QWidget* parent = 0, const char* name = 0, bool modal = FALSE, WFlags fl = 0 );
    ~SeleccionaOrdenFactura();

    QLabel* textLabel3;
    QLineEdit* QLENoOrden;
    QLabel* textLabel2;
    CQControlFecha* QCtrFechaInicio;
    QLabel* textLabel2_2;
    CQControlFecha* QCtrFechaFin;
    QLabel* textLabel1;
    QTable* QTOrdenes;
    QLabel* textLabel1_2;
    QTable* QTProductos;
    QPushButton* QPBCancelar;
    QPushButton* QPBAceptar;
    QPushButton* QPBConsultar;
    QPushButton* QPBReEnviar;

protected:
    QGridLayout* SeleccionaOrdenFacturaLayout;
    QHBoxLayout* layout7;
    QVBoxLayout* layout5;
    QVBoxLayout* layout3;
    QVBoxLayout* layout3_2;
    QVBoxLayout* layout2;
    QVBoxLayout* layout2_2;
    QGridLayout* layout9;

protected slots:
    virtual void languageChange();

};

#endif // SELECCIONAORDENFACTURA_H
