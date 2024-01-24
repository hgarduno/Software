#ifndef __IMPRESIONFACTURASEID_H__
#define __IMPRESIONFACTURASEID_H__
#include <SiscomDesarrollo2.h>
#include <libps/pslib-mp.h>

typedef struct Posicion
{
float fltHojaXmm;
float fltHojaYmm;
float fltBaseXmm;
float fltBaseYmm;
}StcPosicion;


float SumaXpp(const StcPosicion *pPosPtrDato,float pfltXmmDes);
float SumaYpp(const StcPosicion *pPosPtrDato,float pfltYmmDes);
float RestaXpp(const StcPosicion *pPosPtrDato,float pfltXmmDes);
float RestaYpp(const StcPosicion *pPosPtrDato,float pfltYmmDes);

float FacturaTextoSeid(PSDoc *ppsPtrDocArchivo,
		      SArgsSiscom *pSAgsSiscom,
		      int pintTipoLetra,
		      float pfltTamDescripcion,
		      const StcPosicion *pPosPtrPosicion);
void ColocaLogoSeid(PSDoc *ppsPtrDocArchivo,
		    const StcPosicion *pPosPtrPosicion);

void FacturaSeid(SArgsSiscom *pSAgsSiscom,
		 const StcPosicion *pPosPtrPosicion,
		 float pfltTamCantidad,
		 float pfltTamCodigo,
		float pfltTamDescripcion,
		float pfltTamPrecioU);

float MuestraDireccionFacturacion(PSDoc *ppsPtrDocArchivo,
		      const StcPosicion *pPosPtrPosicion,
		      float pfltPosLugarYFecha,
		      SArgsSiscom *pSAgsSiscom);

void FacturaSeidDetalleEncabezados(PSDoc *ppsPtrDocArchivo,	
				   int pintLetra,
				   const StcPosicion *pPosPtrPosicion,
				   float pfltPosLugarYFecha,
				   float pfltTamCantidad,
				   float pfltTamCodigo,
				   float pfltTamDescripcion,
				   float pfltTamPrecioU);

void FacturaSeidDetalleVenta(PSDoc *ppsPtrDocArchivo,	
			    SArgsSiscom *pSAgsSiscom,
			    int pintLetra,
			    const StcPosicion *pPosPtrPosicion,
			    float pfltPosLugarYFecha,
			    float pfltTamCantidad,
			    float pfltTamCodigo,
			    float pfltTamDescripcion,
			    float pfltTamPrecioU);

void FacturaSeidFiscales(PSDoc *ppsPtrDocArchivo,
			 int pintLetra,
			 const StcPosicion *pPosPtrPosicion);
#endif
