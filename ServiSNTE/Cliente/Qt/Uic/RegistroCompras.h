/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/RegistroCompras.ui'
**
** Created: Sat Jan 27 16:35:17 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef REGISTROCOMPRAS_H
#define REGISTROCOMPRAS_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QGroupBox;
class QCtrlProductosSS;
class QLineEdit;
class QFrame;
class QTable;
class QCtrlTipoDocumentos;
class QCtrlConceptosExistencias;
class QCtrlProveedoresSS;
class QPushButton;

class RegistroCompras : public QWidget
{
    Q_OBJECT

public:
    RegistroCompras( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~RegistroCompras();

    QLabel* textLabel7;
    QGroupBox* groupBox3;
    QLabel* textLabel8;
    QCtrlProductosSS* QCtrProducto;
    QLabel* textLabel1_2;
    QLineEdit* QLEModelo;
    QLabel* textLabel11;
    QLineEdit* QLESerieProducto;
    QLabel* textLabel11_2;
    QLineEdit* QLECantidad;
    QFrame* frame4;
    QGroupBox* groupBox1;
    QTable* QTDetalleCompra;
    QFrame* frame3;
    QLabel* textLabel2;
    QCtrlTipoDocumentos* QCtrTipoDocumento;
    QLabel* textLabel4;
    QLineEdit* QLESerieFactura;
    QLabel* textLabel5;
    QLineEdit* QLEFolio;
    QLabel* textLabel6;
    QCtrlConceptosExistencias* QCtrConcepto;
    QLabel* textLabel1;
    QCtrlProveedoresSS* QCtrProveedor;
    QLabel* textLabel3;
    QLineEdit* QLEFecha;
    QPushButton* QPBRegistrar;
    QPushButton* QPBImprimir;
    QPushButton* QPBAgregar;
    QPushButton* QPBEliminar;
    QPushButton* QPBCancelar;
    QPushButton* QPBCopiar;

protected:
    QGridLayout* RegistroComprasLayout;
    QGridLayout* groupBox3Layout;
    QVBoxLayout* layout48;
    QVBoxLayout* layout33;
    QVBoxLayout* layout50;
    QVBoxLayout* layout50_2;
    QGridLayout* frame4Layout;
    QGridLayout* groupBox1Layout;
    QGridLayout* frame3Layout;
    QHBoxLayout* layout46;
    QVBoxLayout* layout41;
    QVBoxLayout* layout42;
    QVBoxLayout* layout43;
    QHBoxLayout* layout45;
    QVBoxLayout* layout44;
    QVBoxLayout* layout38;
    QVBoxLayout* layout70;
    QHBoxLayout* layout14;

protected slots:
    virtual void languageChange();

};

#endif // REGISTROCOMPRAS_H
