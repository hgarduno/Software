#ifndef __ZDENOMINACION_H__
#define __ZDENOMINACION_H__
#include <zSiscomRegistro.h>



class zDenominacion:public zSiscomRegistro
{
public:
	zDenominacion(int pintFila,
		      int pintColumna,
		      const char *pchrPtrValor,
		      const char *pchrPtrCantidad,
		      const char *pchrPtrImporte,
		      const char *pchrPtrColor);

	zDenominacion(zSiscomRegistro *);

	int Fila();
	int Columna();

	const char *Valor();
	const char *Cantidad();
	const char *Importe();
	const char *Color();

	void Cantidad(const char *pchrPtrCantidad);
	void Importe(const char *pchrPtrImporte);
	friend bool operator==(zDenominacion &,zDenominacion &);
private:
	int intFila;
	int intColumna;
};

#endif


