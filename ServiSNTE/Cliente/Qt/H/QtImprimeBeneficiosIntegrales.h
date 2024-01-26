#ifndef __QTIMPRIMEBENEFICIOSINTEGRALES_H__
#define __QTIMPRIMEBENEFICIOSINTEGRALES_H__ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <zContratoBeneficios.h>
#include <zOrden.h>
#include <zProducto.h>
#include <zProductos.h>

#include <qprinter.h>
#include <qpainter.h>
#include <qwidget.h>
struct Registro{
    int x,y;
    const char *valor;
};
class QtImprimeBeneficiosIntegrales : public QWidget
{
    Q_OBJECT
public:
    QtImprimeBeneficiosIntegrales();
    ~QtImprimeBeneficiosIntegrales();
    void MargenArriba(int pintMargenArriba);
    void MargenIzquierda(int pintMargenIzquierda);
    void MargenAbajo(int pintMargenAbajo);
    void MargenDerecha(int pintMargenDerecha);
    void Inicia();
    void AsignaPosiciones(Registro *pRegistro);
public slots:
    void imprimir( zContratoBeneficios * );
    void ImprimeFrente(zContratoBeneficios *pzConBeneficios);
    void ImprimeAtras(zContratoBeneficios *pzConBeneficios);

    void ImprimeAArchivo(const char *pchrPtrArchivo,
    			zContratoBeneficios *);

protected:
    void alistaDatos( zContratoBeneficios * );
    void beneficios( QPainter * );
    void beneficiosAdelante(QPainter *);
    void beneficiosFrente(QPainter *);
    void beneficiosAArchivo( QPainter * );
    void beneficiosAtras( QPainter * );
private:
	void Posiciones(Registro *pRegPosiciones);
private:
    QPrinter *printer;
    int intMargenArriba;
    int intMargenIzquierda;
    int intMargenAbajo;
    int intMargenDerecha;
    int i;
};


#endif

