/****************************************************************************
** Form interface generated from reading ui file 'Qt/Ui/TransferenciaAlmacen.ui'
**
** Created: Thu Apr 11 21:05:33 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef TRANSFERENCIAALMACEN_H
#define TRANSFERENCIAALMACEN_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QFrame;
class QLabel;
class QCtrlVendedores;
class QCtrlTiendasEntrega;
class QTextEdit;
class QLineEdit;
class QCtrlCamiones;
class QPushButton;
class QGroupBox;
class QTable;
class QCtrlProveedoresSS;
class QRadioButton;

class TransferenciaAlmacen : public QWidget
{
    Q_OBJECT

public:
    TransferenciaAlmacen( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~TransferenciaAlmacen();

    QFrame* frame7;
    QLabel* textLabel1_2;
    QCtrlVendedores* QCtrAlmacenistas;
    QLabel* textLabel1;
    QCtrlTiendasEntrega* QCtrTiendasEntrega;
    QFrame* frame7_2;
    QLabel* textLabel1_3_2_3;
    QTextEdit* QTEObservacionGeneral;
    QFrame* frame6;
    QLabel* textLabel1_3;
    QCtrlVendedores* QCtrChoferes;
    QLabel* textLabel1_3_2_2;
    QLineEdit* QLEPlacas;
    QLabel* textLabel1_3_2;
    QCtrlCamiones* QCtrCamiones;
    QFrame* frame23;
    QPushButton* QPBTransfiereAPiso;
    QPushButton* QPBTransferir;
    QPushButton* QPBEliminar;
    QPushButton* QPBImprimir;
    QPushButton* QPBCopiar;
    QFrame* frame8;
    QGroupBox* GBProductos;
    QTable* QTProductos;
    QLabel* textLabel2_2;
    QCtrlProveedoresSS* QCtrProveedores;
    QRadioButton* QRBEsStock;
    QLabel* textLabel2;
    QLineEdit* QLECodigoBarras;

protected:
    QGridLayout* TransferenciaAlmacenLayout;
    QGridLayout* frame7Layout;
    QHBoxLayout* layout3;
    QHBoxLayout* layout4;
    QGridLayout* frame7_2Layout;
    QSpacerItem* spacer2;
    QGridLayout* frame6Layout;
    QHBoxLayout* layout4_2;
    QHBoxLayout* layout4_3;
    QHBoxLayout* layout5;
    QGridLayout* frame23Layout;
    QGridLayout* frame8Layout;
    QGridLayout* GBProductosLayout;
    QHBoxLayout* layout64;
    QHBoxLayout* layout8;

protected slots:
    virtual void languageChange();

};

#endif // TRANSFERENCIAALMACEN_H
