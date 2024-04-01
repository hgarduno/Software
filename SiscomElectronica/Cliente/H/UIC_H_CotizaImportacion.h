/****************************************************************************
** Form interface generated from reading ui file 'UI/CotizaImportacion.ui'
**
** Created: Wed Jan 31 10:48:07 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef COTIZAIMPORTACION_H
#define COTIZAIMPORTACION_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QGroupBox;
class QLabel;
class QLineEdit;
class QCtrlProveedoresSE;
class QCtrlProductosSE;
class QTable;
class QTextEdit;
class QPushButton;

class CotizaImportacion : public QWidget
{
    Q_OBJECT

public:
    CotizaImportacion( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~CotizaImportacion();

    QGroupBox* groupBox1;
    QLabel* textLabel2;
    QLineEdit* QLEPeso;
    QLabel* textLabel2_2;
    QLineEdit* QLECostoDolar;
    QLabel* textLabel3;
    QCtrlProveedoresSE* QCtrProveedores;
    QLabel* textLabel1;
    QCtrlProductosSE* QCtrProductos;
    QLabel* textLabel4;
    QLineEdit* QLECantidad;
    QLabel* textLabel4_2;
    QLineEdit* QLEPrecio;
    QLabel* textLabel5;
    QTable* QTProductos;
    QLabel* textLabel8;
    QTextEdit* QTEDatosCotizacion;
    QPushButton* QPBConsulta;
    QPushButton* QPBRegistra;
    QPushButton* QPBAnexar;
    QPushButton* QPBEliminar;

protected:
    QGridLayout* CotizaImportacionLayout;
    QGridLayout* groupBox1Layout;
    QVBoxLayout* layout2;
    QHBoxLayout* layout14;
    QVBoxLayout* layout2_2;
    QVBoxLayout* layout3;
    QVBoxLayout* layout1;
    QVBoxLayout* layout4;
    QVBoxLayout* layout4_2;
    QHBoxLayout* layout16;
    QVBoxLayout* layout6;
    QVBoxLayout* layout15;
    QHBoxLayout* layout17;

protected slots:
    virtual void languageChange();

};

#endif // COTIZAIMPORTACION_H
