#ifndef __QTIMPRIMEFACTURA_H__
#define __QTIMPRIMEFACTURA_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <zVenta.h>
#include <zOrden.h>
#include <zProducto.h>
#include <zProductos.h>

#include <qprinter.h>
#include <qpainter.h>
#include <qwidget.h>

class QtImprimeFactura : public QWidget
{
    Q_OBJECT
public:
    QtImprimeFactura();
    ~QtImprimeFactura();
public slots:
    void imprimir( zVenta & );
protected:
    void alistaDatos( zVenta & );
    void factura( QPainter * , zVenta &);
private:
    QPrinter *printer;

};

#endif

