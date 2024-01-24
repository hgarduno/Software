#ifndef __IMPRESIONSEID_H__
#define __IMPRESIONSEID_H__
#include <SiscomDesarrollo2.h>
#include <libps/pslib-mp.h>
void ImprimeSeid(SArgsSiscom *pSAgsSiscom);

void NotaRemisionSeid(SArgsSiscom *pSAgsSiscom,
		      float pfltXmm,
		      float pfltYmm,
				  float pfltTamCantidad,
				  float pfltTamCodigo,
				  float pfltTamDescripcion,
				  float pfltTamPrecioU);

void NotaRemisionSeidDetalleVenta(PSDoc *ppsPtrDocArchivo,
				  SArgsSiscom *pSAgsSiscom,
				  int pintLetra,
				  float pfltXmm,
				  float pfltYmm,
				  float pfltTamCantidad,
				  float pfltTamCodigo,
				  float pfltTamDescripcion,
				  float pfltTamPrecioU);
void DibujaLinea(PSDoc *ppsPtrDocArchivo,
		 float pfltXmm,
		 float pfltYmm,
		 float pfltX1mm,
		 float pfltY1mm);
void NotaRemisionSeidTexto(PSDoc *ppsPtrDocArchivo,
			   SArgsSiscom *pSAgsSiscom,
			   int pintLetra,
			   float pfltXmm,
			   float pfltYmm);

void DibujandoLineasRemisionSeid(PSDoc *ppsPtrDocArchivo,
				float pfltXmm,
			float pfltYmm,
				  float pfltTamCantidad,
				  float pfltTamCodigo,
				  float pfltTamDescripcion,
				  float pfltTamPrecioU);
float MMAPuntos(float pfltMM);
char *RutaImagenImpresionSeid(char *pchrPtrImagen);

int TamanoTextoSeid(PSDoc *ppsPtrArchivo,
		   int pintLetra,
		  float pfltTamano,
		  float pfltTamCodigo,
		  float pfltTamDescripcion,
		  const char *pchrPtrTexto);
void NotaRemisionSeidDetalleVentaEncabezados(PSDoc *ppsPtrDocArchivo,
				  int pintLetra,
				  float pfltXmm,
				  float pfltYmm,
				  float pfltTamCantidad,
				  float pfltTamCodigo,
				  float pfltTamDescripcion,
				  float pfltTamPrecioU);

void MuestraDireccion(PSDoc *ppsPtrDocArchivo,
		      SArgsSiscom *pSAgsSiscom,
		      float pfltXpp,
		      float pfltYpp);

const char *EliminaSaltoRetono(const char *pchrPtrLinea);
const char *SiguienteLineaDireccion(const char *pchrPtrDireccion,
				    char *pchrPtrLinea);

void ObtenNombreArchivoImpresion(SArgsSiscom *pSAgsSiscom,	
				 char *pchrPtrArchivo);

void AsignaArchivoParaCups(SArgsSiscom *pSAgsSiscom,
			   const char *pchrPtrArchivo);
#endif
