#ifndef __RNCOMPRAS_H__
#define __RNCOMPRAS_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>


void ConsultaCompras(int,int);
void RegistraCompras(int,int);
int EsConsultaCompras(char **);
void FormaConsultaCompras(char **,SiscomOperacionesServidor *);
void SqlMaterialBodega(LCamposSiscomPro2 *pLCSiscomPro2Dat,
		       LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
		       LCamposSiscomPro2 **pLCSiscomPro2DatUlt,
		       int *pintPtrNRegistros);
		      
void AgregaActualizaImporteCompra(LCamposSiscomPro2 **pLCSiscomPro2Prim,
				LCamposSiscomPro2 **pLCSiscomPro2Act,
				int *pintPtrNRegistro,
				const char *pchrPtrIdCompra,
				float pfltImporteTotalCompra);

void AgregaRegistroRegistroCompra(LCamposSiscomPro2 **pLCSiscomPro2Prim,
				LCamposSiscomPro2 **pLCSiscomPro2Act,
				int *pintPtrNRegistro,
				const char *pchrPtrIdOrigenCompra,
				const char *pchrPtrIdCompra,
				const char *pchrPtrFechaCompra,
				float lfltImporteTotalCompra);

int SqlUpdateMaterialBodegaDescuentaTransferencia(
		       LCamposSiscomPro2 *pLCSiscomPro2Dat,
		       LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
		       LCamposSiscomPro2 **pLCSiscomPro2DatUlt,
		       int *pintPtrNRegistros);

void SqlInsertBodegaAExpendioTransferencia(
		       LCamposSiscomPro2 *pLCSiscomPro2Dat,
		       const char *pchrPtrFecha,
		       LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
		       LCamposSiscomPro2 **pLCSiscomPro2DatUlt,
		       int *pintPtrNRegistros);

void SqlUpdateExistenciasTransferencia(
		       LCamposSiscomPro2 *pLCSiscomPro2Dat,
		       LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
		       LCamposSiscomPro2 **pLCSiscomPro2DatUlt,
		       int *pintPtrNRegistros);

#endif
