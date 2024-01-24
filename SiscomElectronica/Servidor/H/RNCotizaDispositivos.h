#ifndef __RNCOTIZADISPOSITIVOS_H__
#define __RNCOTIZADISPOSITIVOS_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>
void CotizaDispositivos(int,int);
void FormaConsultaDispositivos(LCamposSiscomPro2 *,char **);
void ConsultaProductosCotiza(int ,SiscomOperacionesServidor *);
void CotizaOrden(LCamposSiscomPro2 *,
		 LCamposSiscomPro2 *,
		 float,
		 float,
		 LCamposSiscomPro2 **,
		 int *,
		 SArgsSiscom *pSAgsSiscom);

void CotizandoOrden(LCamposSiscomPro2 *pLCSiscomPro2Ent,
		    LCamposSiscomPro2 *pLCSiscomPro2Base,
		    float pfltPorDescuento,
		    float pfltPorDescuentoCajaOrden,
		    LCamposSiscomPro2 **pLCSiscomPro2COrden,
		    int *pintPtrNRegRegreso,
		    SArgsSiscom *pSAgsSiscom);
int EliminaTotalOrden(LCamposSiscomPro2 *);
void EliminaTotalOrden2(LCamposSiscomPro2 *,char *pchrPtrTotal);
SArgsSiscom *AgregandoProductoPorTipoProducto(LCamposSiscomPro2 *pLCSiscomPro2Productos,SArgsSiscom *pSAgsSiscom);
void FormaConsultaTiposProducto(LCamposSiscomPro2 *pLCSiscomPro2Productos,
				const char *pchrPtrIdExpendio,
				char **pchrPtrSql);
void ArgumentosTipoProducto(SArgsSiscom *pSAgsSiscom);
void FormaCotizacionTipoProducto(SArgsSiscom *pSAgsSiscom,
		     SCampoSiscomPro2 *pSCSiscomPro2,
		     LCamposSiscomPro2 **pLCSiscomPro2Ent,
		     LCamposSiscomPro2 **pLCSiscomPro2Base,
		     int *pintPtrNRegistros);

void ArmaRespuestaVentaTipoProducto(LCamposSiscomPro2 *pLCSiscomPro2Ent,
				    const char *pchrPtrCveKit,
				    const char *pchrPtrIdProductoKit,
				    LCamposSiscomPro2 **pLCSiscomPro2COrdenPrim,
				    LCamposSiscomPro2 **pLCSiscomPro2COrdenAct,
				    int *pintPtrNRegRegreso);

		  /* Queretaro a 3 de diciembre del 2015 
		   * Se integra el modulo de faltantes 
		   * Cuando se detecte que la existencia en el expendio y la bodega
		   * es 0, se debera realizar la insercion a la tabla de faltantes 
		   * para que se lleve el registro ....
		   */
void RegistrandoFaltantes(LCamposSiscomPro2 *pLCSiscomPro2Base,
			  SArgsSiscom *pSAgsSiscom);
#endif 
