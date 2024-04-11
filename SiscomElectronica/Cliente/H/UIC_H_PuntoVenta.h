/****************************************************************************
** Form interface generated from reading ui file 'UI/PuntoVenta.ui'
**
** Created: Wed Apr 10 20:52:30 2024
**
** WARNING! All changes made in this file will be lost!
****************************************************************************/

#ifndef PUNTOVENTA_H
#define PUNTOVENTA_H

#include <qvariant.h>
#include <qwidget.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTextBrowser;
class QLabel;
class QLineEdit;
class QCtrlProductosSE;
class QPushButton;

class PuntoVenta : public QWidget
{
    Q_OBJECT

public:
    PuntoVenta( QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~PuntoVenta();

    QTextBrowser* QTBPuntoVenta;
    QLabel* textLabel1;
    QLineEdit* QLECantidad;
    QLabel* textLabel2;
    QCtrlProductosSE* QCtrProductos;
    QPushButton* QPBCargaArchivoHtml;
    QPushButton* QPBDecrementaTexto;
    QPushButton* QPBIncrementaTexto;
    QPushButton* QPBAnexarOrden;

protected:
    QGridLayout* PuntoVentaLayout;
    QHBoxLayout* layout4;
    QVBoxLayout* layout2;
    QVBoxLayout* layout3;

protected slots:
    virtual void languageChange();

};

#endif // PUNTOVENTA_H
