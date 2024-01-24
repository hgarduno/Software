#ifndef __SISCOMMODULO_H__
#define __SISCOMMODULO_H__
#include <qstring.h>

class SiscomModulo
{
public:
	SiscomModulo(const char *pchrPtrModulo);
	void Modulo(void **pvidPtrModulo);
	void Funcion(const char *,void **pvidPtrFuncion);
	void Modulo(char *pchrPtrModulo);
	int EstadoCarga();
	
private:
	void *vidPtrAncla;
	char chrArrModulo[256];
private:
	void CargaModulo();
};
#endif
