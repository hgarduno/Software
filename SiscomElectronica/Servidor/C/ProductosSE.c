#include <ProductosSE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <ComunSiscomElectronica4.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SqlProductosSE.h>

#include <string.h>

void ObtenDefinicionProducto(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlDefinicionProductoSE,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoDefinicionProductoSE,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void TiposProductoSE(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlTiposProductoSE,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoTiposProductoSE,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}



/* Martes 22 de Marzo 2016
 * Queretaro
 * Se debe integrar en esta consulta, el tipo de 
 * producto, para que cuando se cotice se pueda 
 * considerar con la informacion que llega
 */
void ProductosSE(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlProductosSiscomElectronica,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoProductosSE,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviandoProductosSE(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomRegistroProL *lSiscomRegProLPtrRegreso;
/*
if(LlegoCriterioBusqueda(pSiscomOpePtrDato))
{
   LogSiscom("Se Arma la respuesta para productos Similares");
   lSiscomRegProLPtrRegreso=ArmaRespuestaProductosSimilares(pSiscomOpePtrDato);
}
else
*/
LogSiscom("---");
lSiscomRegProLPtrRegreso=SiscomObtenRegistrosCampoRespuesta("Productos",pSiscomOpePtrDato);

if(lSiscomRegProLPtrRegreso)
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  lSiscomRegProLPtrRegreso);
return 0;
}

int EnviandoTiposProductoSE(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];

SiscomEnviaAsociadoRespuestaCliente("TiposProducto",
				    lchrArrBuffer,
				    pSiscomOpePtrDato);
return 0;
}
int EnviandoDefinicionProductoSE(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomEnviaAsociadoRespuestaCliente("DefinicionProducto",
				    lchrArrBuffer,
				    pSiscomOpePtrDato);

return 0;
}

int LlegoCriterioBusqueda(SiscomOperaciones *pSiscomOpePtrDato)
{
 const char *lchrPtrCriterio; 
 lchrPtrCriterio=SiscomCampoAsociadoEntradaOperacion("Envio","Criterio",pSiscomOpePtrDato);
 return lchrPtrCriterio ? 1 : 0;
}
int CondicionBusqueda(const char *pchrPtrCriterio,
		      SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
char lchrArrCriterio[128];
const char *lchrPtrClave,*lchrPtrDescripcion;
strcpy(lchrArrCriterio,pchrPtrCriterio);
SiscomAMayusculas(lchrArrCriterio);
lchrPtrClave=SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrProducto);
lchrPtrDescripcion=SiscomObtenCampoRegistroProLChar("dscproducto",pSiscomRegProLPtrProducto);
if(lchrPtrClave &&
   lchrPtrDescripcion && (strstr(lchrPtrClave,lchrArrCriterio) 	||
   strstr(lchrPtrDescripcion,lchrArrCriterio)))
return 1;
else
return 0;
}
/* Tepotzotlan Mexico a 26 de diciembre del 2017 
 * Se requiere implementar un algoritmo de busqueda 
 * del criterio en la descripcion y clave del producto ..
 */
SiscomRegistroProL *ArmaRespuestaProductosSimilares(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrProductos,
		   *lSiscomRegProLPtrRegPrim=0,
		   *lSiscomRegProLPtrRegAct=0;
lSiscomRegProLPtrProductos=SiscomObtenRegistrosCampoRespuesta("Productos",pSiscomOpePtrDato);
const char *lchrPtrCriterio;
lchrPtrCriterio=SiscomCampoAsociadoEntradaOperacion("Envio",
						    "Criterio",
						    pSiscomOpePtrDato);
for(;
    lSiscomRegProLPtrProductos;
    lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
{
  if(CondicionBusqueda(lchrPtrCriterio,lSiscomRegProLPtrProductos))
  SiscomNodoRegistroPro(lSiscomRegProLPtrProductos->SiscomCamProLPtrDato,
			&lSiscomRegProLPtrRegPrim,
		        &lSiscomRegProLPtrRegAct);

}

return lSiscomRegProLPtrRegPrim;
}
