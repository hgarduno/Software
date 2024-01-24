#ifndef __SISCOMCLASEINI_H__
#define __SISCOMCLASEINI_H__
#include <qptrlist.h>
#include <SiscomVariableIni.h>


class SiscomClaseIni:public QPtrList<SiscomVariableIni>
{
public:
	SiscomClaseIni(const char *pchrPtrNombre);
	void Clase(char *pchrPtrNombre);
	int operator==(const char *pchrPtrNombre);
	int EsLaClasePorNombre(const char *pchrPtrNombre);
	int EsLaClasePorNombre(const char *pchrPtrNombre,int pintNivel);
	void AgregaPropiedad(const char *pchrPtrPropiedad,
			     const char *pchrPtrValor);
	void Muestra();	
	SiscomVariableIni *Propiedad(const char *pchrPtrPropiedad);
private:
	char chrArrNombre[256];
};


#endif
