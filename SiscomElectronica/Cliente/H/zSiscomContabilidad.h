#ifndef __ZSISCOMCONTABILIDAD_H__
#define __ZSISCOMCONTABILIDAD_H__

#include <zSiscomOperaciones.h>
#include <zFactura.h>
/* Tepotzotlan  Mexico 17 de enero 2026 
 *
 * Se debe revisar en el servidor para poner en una biblioteca
 * diferente libSiscomContabilidad.so , la funcionalidad de la 
 * contabilidad, ahorita para poner todos los archivos, la dejo 
 * en libSiscomElectronica4.so , pero hay que cambiar todo eso 
 *
 */

class zSiscomContabilidad:public zSiscomOperaciones
{
public:
	zSiscomContabilidad(zSiscomConexion *,
			    const char *pchrPtrFuncion,
			    const char *pchrPtrModulo="libSiscomElectronica4.so");
	~zSiscomContabilidad();

	void OrdenesTarjetaTransferencia(const char *pchrPtrFechaIni,
					 const char *pchrPtrFechaFin);
	void FacturaPublicoEnGeneralPE(zFactura *pzFactura);
private:
};


#endif
