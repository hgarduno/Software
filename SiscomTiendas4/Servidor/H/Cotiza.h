#ifndef __COTIZA_H__
#define __COTIZA_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OPCotiza();
SiscomOperaciones2 *OPIdCotizacion();
void EnviaCotizacion(SArgsSiscom *);
void EjecutaCotizacion(SArgsSiscom *);
void GeneraIdCotizacion(SArgsSiscom *);
void NombreArchivoImpresion(SArgsSiscom *);
void ArgumentosCotiza(SArgsSiscom *);
void ArgumentosImpresion(SArgsSiscom *pSAgsSiscom);
void ObtenFechaRemision(SArgsSiscom *pSAgsSiscom);
void NombreArchivoImpresion(SArgsSiscom *pSAgsSiscom);
void EnviaImpresion(SArgsSiscom *pSAgsSiscom);

void ActualizaResultados(LCamposSiscomPro2  *,
			 float,
			 float,
			 float,
			 float,
			 const char *,
			 const char *);
void ColocaImporteOrden(SArgsSiscom *,LCamposSiscomPro2 *,float );

void EnviaImpresion(SArgsSiscom *pSAgsSiscom);

void ArchivoParaCups(SArgsSiscom *pSAgsSiscom,
			    char *pchrPtrArchivo);
#endif
