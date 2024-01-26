#ifndef __QTIMPRIMETRANSFERENCIA_H__
#define __QTIMPRIMETRANSFERENCIA_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <zTransferencia.h>
#include <zOrden.h>
#include <zProducto.h>
#include <zProductos.h>

#include <qprinter.h>
#include <qpainter.h>
#include <qwidget.h>

class QtImprimeTransferencia : public QWidget
{
    Q_OBJECT
public:
    QtImprimeTransferencia();
    ~QtImprimeTransferencia();
public slots:
    void imprimir( zTransferencia & );
protected:
    void alistaDatos( zTransferencia & );
    void transferencia( QPainter * , zTransferencia &);
private:
    QPrinter *printer;

};

#endif

