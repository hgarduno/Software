#ifndef __RNVENTASELECTRONICA_H__
#define __RNVENTASELECTRONICA_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>


/* Queretaro 4 de noviembre del 2015
 * Con el problema de los negativos, en la existencia
 * se debe integrar la funcionalidad que permita validar 
 * la disponibilidad de los dispositivos en las cotizaciones
 */

void RegistrandoVentas(int pintSocket,
			int pintNRegistros);
void ConsultaVentas(int,int);
void RegistraVentas(int,int);
int EsConsultaVentas(char **);
void FormaConsultaVentas(char **,SiscomOperacionesServidor *);

void AgregaOrdenACaja(const char *pchrPtrIdVenta,
		      const char *pchrPtrIdExpendio,
		      const char *pchrPtrIdCaja,
		      const char *pchrPtrImporteTotal,
		      LCamposSiscomPro2 **pLCSiscomPro2Prim,
		      LCamposSiscomPro2 **pLCSiscomPro2Act,
		      int *pintPtrNRegistros);
		      


#endif
