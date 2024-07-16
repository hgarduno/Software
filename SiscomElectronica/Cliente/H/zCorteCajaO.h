#ifndef __ZCORTECAJAO_H__
#define __ZCORTECAJAO_H__

#include <zSiscomOperaciones.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h> 

/* Siscom Zacatenco
 * Viernes 12 Julio 2024 
 *
 * Se deben pasar todas las funciones que tienen que ver con 
 * el corte de caja de la clase zSiscomElectronica.
 *
 */

class zCorteCaja;
class zSiscomConexion;
class zCorteCajaO:public zSiscomOperaciones
{
public:
	zCorteCajaO(zSiscomConexion *,
		    const char *pchrPtrFuncion,
		    const char *pchrPtrModulo="libSiscomElectronica4.so");
	~zCorteCajaO();
public:
	int RealizaCorte(const char *pchrPtrFechaH,zCorteCaja *);
	int RegistraCorte(zCorteCaja *);
};


#endif

