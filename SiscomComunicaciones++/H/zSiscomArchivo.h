#ifndef __ZSISCOMARCHIVO_H__
#define __ZSISCOMARCHIVO_H__
#include <zSiscomRegistros.h>
#include <stdio.h>
class zSiscomRegistro;
class zSiscomArchivo:public zSiscomRegistros
{
public:
	zSiscomArchivo(const char *pchrPtrArchivo);
	zSiscomArchivo();
	void Copia(const char *pchrPtrDestino);
	zSiscomRegistro *NodoArchivo(const unsigned char *pchrPtrLectura,
				     int pintTamano);
private:
	void Carga(const char *pchrPtrArchivo);

private:
	const char *chrPtrArchivo;
};
#endif
