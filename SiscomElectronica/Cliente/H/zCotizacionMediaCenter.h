#ifndef __ZCOTIZACIONMEDIACENTER_H__
#define __ZCOTIZACIONMEDIACENTER_H__
#include <zCotizacion.h>


class zCotizacionMediaCenter:public zCotizacion
{
public:
	zCotizacionMediaCenter();
	zCotizacionMediaCenter(zCotizacion *);
	void Telefono(const char *pchrPtrTelefono);
	void PagaCon(const char *);
	void Hora(const char *);
	void LlevarA(const char *);
	void Escuela(const char *);
	void Modo(const char *);
	void Nombre(const char *);

	const char *Telefono();
	const char *Hora();
	const char *PagaCon();
	const char *Escuela();
	const char *Modo();
	const char *Nombre();
	void DescripcionMediaCenterCotizacion();
	void DescripcionMediaCenterEnvio();
	void DescripcionMediaCenter();
	void DescripcionSinEnvio();

        void CadenaCompleta(const char *);
	const char *Identificacion(const char **);





private:
	char chrArrCadena[4196];
private:
	void IniciaCampos();
};

#endif
