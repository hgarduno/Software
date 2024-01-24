#ifndef __SISPRODUCTOS2_H__
#define	__SISPRODUCTOS2_H__
#include <SISCOMComunicaciones++.h>

class SisProducto2:public SiscomInformacion2
{
public:
	SisProducto2(	const char *,
			const char *,
			const char *,
			const char *);
			
private:
	void SiscomFormaRegistro();
	void SiscomAnexaRegistro();
private:

	const char *chrPtrClave;
	const char *chrPtrExistencia;
	const char *chrPtrPrecio;
	const char *chrPtrCantidad;

};


#endif
