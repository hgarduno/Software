#ifndef __QTIMPRIMERECIBO_H__
#define __QTIMPRIMERECIBO_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <zReciboApartado.h>
#include <zOrden.h>
#include <zProducto.h>
#include <zProductos.h>

#include <qprinter.h>
#include <qpainter.h>
#include <qwidget.h>

class QtImprimeRecibo : public QWidget
{
    Q_OBJECT
public:
    QtImprimeRecibo();
    ~QtImprimeRecibo();
public slots:
    void imprimir( zReciboApartado & );
protected:
    void alistaDatos( zReciboApartado & );
    void Recibo( QPainter * );
private:
    QPrinter *printer;

};

#endif

