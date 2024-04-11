/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/PuntoDeVenta.ui'
**
** Created: Sat Jan 27 16:35:16 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PUNTODEVENTA_H
#define PUNTODEVENTA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QCtrlTipoVentas;
class QCtrlFinanciadoras;
class QCtrlPlazos;
class QCtrlVendedores;
class QLineEdit;
class QPushButton;
class QTable;
class QLCDNumber;
class QTextEdit;
class QCtrlFormasEntrega;
class QCtrlProveedoresSS;

class PuntoDeVenta : public QWidget
{
    Q_OBJECT

public:
    PuntoDeVenta( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PuntoDeVenta();

    QLabel* textLabel1_3;
    QCtrlTipoVentas* QCtrTipoVenta;
    QLabel* textLabel2_2;
    QCtrlFinanciadoras* QCtrFinanciadora;
    QLabel* textLabel1_6;
    QCtrlPlazos* QCtrPlazos;
    QLabel* textLabel3;
    QCtrlVendedores* QCtrVendedores;
    QLabel* textLabel4;
    QLineEdit* QLEFolio;
    QLabel* textLabel5;
    QLineEdit* QLEFecha;
    QLabel* textLabel10;
    QLineEdit* QLECliente;
    QPushButton* QPBCapturaCliente;
    QLabel* textLabel6_2;
    QLineEdit* QLEDireccion;
    QPushButton* QPBCapturaDireccion;
    QTable* QTDetalleFactura;
    QLabel* textLabel1;
    QLCDNumber* QLCDImporte;
    QLabel* textLabel2_3;
    QLCDNumber* QLCDExistencia;
    QTextEdit* QTEInfoCredito;
    QLabel* textLabel1_5;
    QLineEdit* QLEDescripcionProducto;
    QLabel* textLabel13;
    QLineEdit* QLEModelo;
    QLabel* textLabel14;
    QLineEdit* QLESerie;
    QLabel* textLabel16;
    QLineEdit* QLEPrecioVenta;
    QLabel* textLabel7;
    QTextEdit* QTEInstrucionesEntrega;
    QLabel* textLabel8;
    QLCDNumber* QLCDSuma;
    QLabel* textLabel9;
    QLCDNumber* QLCDIva;
    QLabel* textLabel10_2;
    QLCDNumber* QLCDTotal;
    QLabel* textLabel1_7;
    QLineEdit* QLETelefono;
    QLabel* textLabel1_4;
    QCtrlFormasEntrega* QCtrFormaEntrega;
    QLabel* textLabel1_2_2;
    QLineEdit* QLECantidadCotiza;
    QLabel* textLabel1_2;
    QLineEdit* QLECodigoBarras;
    QLabel* textLabel2;
    QCtrlProveedoresSS* QCtrProveedores;
    QLabel* textLabel1_2_3;
    QLineEdit* QLENumeroProducto;
    QPushButton* QPBProductosProveedor;
    QPushButton* QPRegistrarVenta;
    QPushButton* QPBImprimir;
    QPushButton* QPBNuevaVenta;
    QPushButton* QPBAgregar;
    QPushButton* QPBCambiarPrecio;
    QPushButton* QPBEliminar;
    QPushButton* QPBCancelarVenta;
    QPushButton* QPBCodigoBarras;
    QPushButton* QPBClaveProveedor;

protected:
    QGridLayout* PuntoDeVentaLayout;
    QHBoxLayout* layout52;
    QVBoxLayout* layout33;
    QVBoxLayout* layout34;
    QVBoxLayout* layout33_2;
    QVBoxLayout* layout39;
    QVBoxLayout* layout62;
    QVBoxLayout* layout36;
    QHBoxLayout* layout50;
    QHBoxLayout* layout50_2;
    QHBoxLayout* layout49;
    QVBoxLayout* layout46;
    QHBoxLayout* layout44;
    QVBoxLayout* layout38;
    QVBoxLayout* layout36_2;
    QVBoxLayout* layout37;
    QHBoxLayout* layout33_3;
    QVBoxLayout* layout31;
    QHBoxLayout* layout39_2;
    QVBoxLayout* layout84;
    QVBoxLayout* layout85;
    QVBoxLayout* layout175;
    QHBoxLayout* layout37_2;
    QVBoxLayout* layout37_3;
    QVBoxLayout* layout36_3;
    QHBoxLayout* layout37_4;
    QHBoxLayout* layout38_3;
    QHBoxLayout* layout49_2;
    QHBoxLayout* layout52_2;
    QVBoxLayout* layout50_3;
    QVBoxLayout* layout51;
    QHBoxLayout* layout57;
    QHBoxLayout* layout55;
    QVBoxLayout* layout47;
    QVBoxLayout* layout48;
    QVBoxLayout* layout49_3;
    QVBoxLayout* layout48_2;
    QVBoxLayout* layout66;

protected slots:
    virtual void languageChange();

};

#endif // PUNTODEVENTA_H
