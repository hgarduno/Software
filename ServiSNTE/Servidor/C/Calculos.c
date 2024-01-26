#include <Calculos.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomFuncionesComunes.h>
#include <string.h>
#include <stdio.h>
void CalculaCostoCantidad(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdCosto,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFechaHoy,&lSiscomProDat);
SiscomAgregaOperacion(EnviaCalculoCostoCantidad,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void CalculaCostoProveedor(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(FormaCamposRespuesta,&lSiscomProDat);
SiscomAgregaOperacion(CalculoCostoProductoProveedor,&lSiscomProDat);
SiscomAgregaOperacion(EnviaCalculoCostoProducto,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void CalculaPrecios(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(FormaCamposCalculoPrecios,&lSiscomProDat);
SiscomAgregaOperacion(CalculoPreciosProducto,&lSiscomProDat);
SiscomAgregaOperacion(EnviaCalculoPreciosProducto,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void CalculaPorcentajeGanancia(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaCalculoPorcentajeGanancia,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EnviaCalculoPorcentajeGanancia(SiscomOperaciones *pSiscomOpePtrDato)
{
float lfltGanancia ;
char lchrArrGanancia[20],lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrRegPrim=0,
		   *lSiscomRegProLPtrRegAct=0;
lfltGanancia=(SiscomCampoAsociadoEntradaOperacionFloat("Envio",
						      "Precio",
						      pSiscomOpePtrDato)-
	     SiscomCampoAsociadoEntradaOperacionFloat("Envio",
						      "CostoNeto",
						      pSiscomOpePtrDato))/100.00;
LogSiscom("El porcentaje de ganancia:%f",lfltGanancia);
sprintf(lchrArrGanancia,"%.2f",lfltGanancia);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrRegPrim,
		       &lSiscomRegProLPtrRegAct,
		       lchrArrBuffer,
		       "Ganancia,",
		       lchrArrGanancia);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrRegPrim);
	     
}
int EnviaCalculoCostoCantidad(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
const char *lchrPtrCosto;
char lchrArrCostoMIva[20],
     lchrArrCostoIva[20];
lchrPtrCosto=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "Costo",
						     pSiscomOpePtrDato);

GeneraValorCosto(pSiscomOpePtrDato,
		 lchrArrCostoMIva,
		 lchrArrCostoIva);
	
		
LogSiscom("Los datos son:%s",lchrPtrCosto);

SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdCosto,Costo,CostoMIva,CostoIva,Fecha,",
		       SiscomCampoAsociadoEntradaOperacion("Envio","IdCosto",pSiscomOpePtrDato),
		       lchrPtrCosto,
		       lchrArrCostoMIva,
		       lchrArrCostoIva,
		       SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato));
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
}

int EnviaCalculoDescuento(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
const char *lchrPtrDescuento;
/*char lchrArrDescuentoMIva[20],
     lchrArrDescuentoIva[20];
     */
lchrPtrDescuento=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "Descuento",
						     pSiscomOpePtrDato);

/*GeneraValorDescuento(pSiscomOpePtrDato,
		 lchrArrDescuentoMIva,
		 lchrArrDescuentoIva);*/
	
		
LogSiscom("Los datos son:%s",lchrPtrDescuento);

SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdDescuento,Descuento,Fecha,",
		       SiscomCampoAsociadoEntradaOperacion("Envio","IdDescuento",pSiscomOpePtrDato),
		       lchrPtrDescuento,
		       SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato));
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
}

int EnviaCalculoPreciosProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
return 0;
}



float PorcentajeDescuento(float pfltCosto,
			  float pfltDescuento)
{
float lfltDescuento;
 lfltDescuento=pfltCosto*(pfltDescuento/100);
 return pfltCosto-lfltDescuento;
}
int CalculoCostoProductoProveedor(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrRegreso,
		   *lSiscomRegProLPtrDescuentos;
char lchrArrBuffer[128];
float lfltCostoCalculado,
	lfltCosto;

if((lSiscomRegProLPtrRegreso=SiscomRegistrosAsociadosCampoEntrada("Envio",
								  "Costo",
								  pSiscomOpePtrDato)))
{
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrRegreso);
lfltCosto=lfltCostoCalculado=SiscomObtenCampoRegistroProLFloat("costobruto",lSiscomRegProLPtrRegreso); 
  if((lSiscomRegProLPtrDescuentos=SiscomRegistrosAsociadosCampoEntrada("Envio",
  								       "Descuento",
  								      pSiscomOpePtrDato)))
  {
	SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrDescuentos);
	if(SiscomObtenCampoRegistroProLChar("d1",lSiscomRegProLPtrDescuentos))
	lfltCostoCalculado=PorcentajeDescuento(lfltCostoCalculado,
				SiscomObtenCampoRegistroProLFloat("d1",lSiscomRegProLPtrDescuentos));
	if(SiscomObtenCampoRegistroProLChar("d2",lSiscomRegProLPtrDescuentos))
	lfltCostoCalculado=PorcentajeDescuento(lfltCostoCalculado,
				SiscomObtenCampoRegistroProLFloat("d2",lSiscomRegProLPtrDescuentos));
	if(SiscomObtenCampoRegistroProLChar("d3",lSiscomRegProLPtrDescuentos))
	lfltCostoCalculado=PorcentajeDescuento(lfltCostoCalculado,
				SiscomObtenCampoRegistroProLFloat("d3",lSiscomRegProLPtrDescuentos));
	if(SiscomObtenCampoRegistroProLChar("d4",lSiscomRegProLPtrDescuentos))
	lfltCostoCalculado=PorcentajeDescuento(lfltCostoCalculado,
				SiscomObtenCampoRegistroProLFloat("d4",lSiscomRegProLPtrDescuentos));
	lfltCostoCalculado*=(1+SiscomObtenCampoRegistroProLFloat("iva",lSiscomRegProLPtrRegreso)/100);
  }
  else
  {
	lfltCostoCalculado=SiscomObtenCampoRegistroProLFloat("costobruto",lSiscomRegProLPtrRegreso)*
	  ((1+SiscomObtenCampoRegistroProLFloat("iva",lSiscomRegProLPtrRegreso)/100));
  }
  SiscomActualizaCampoRespuestaFloat("Costo",
  				    "%.2f",
				    lfltCostoCalculado,
				    pSiscomOpePtrDato);
}
}
float CalculaPrecioVenta(SiscomRegistroProL *pSiscomRegProLPtrDatos,
			 float pfltCosto)
{
char lchrArrBuffer[128];
float lfltPrecio=(1+SiscomObtenCampoRegistroProLFloat("Margen",pSiscomRegProLPtrDatos)/100)*
		 pfltCosto;
return lfltPrecio;
}
int CalculoPreciosProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
float lfltPrecio,
	lfltPrecioForaneo;
SiscomRegistroProL *lSiscomRegProLPtrPrecio,
		   *lSiscomRegProLPtrForaneo;
float lfltCosto=SiscomCampoAsociadoAsociadoEntradaOperacionFloat(
			"Envio",
			"Costo",
			"costoneto",
			pSiscomOpePtrDato);
if((lSiscomRegProLPtrPrecio=SiscomRegistrosAsociadosCampoEntrada("Envio",	
								 "Precio",
								 pSiscomOpePtrDato)))
lfltPrecio=CalculaPrecioVenta(lSiscomRegProLPtrPrecio,lfltCosto);
if((lSiscomRegProLPtrForaneo=SiscomRegistrosAsociadosCampoEntrada("Envio",
								  "PrecioForaneo",
								  pSiscomOpePtrDato)))
lfltPrecioForaneo=CalculaPrecioVenta(lSiscomRegProLPtrForaneo,lfltCosto);
SiscomActualizaCampoRespuestaFloat("Precio",
				   "%.2f",
				   lfltPrecio,
				   pSiscomOpePtrDato);
SiscomActualizaCampoRespuestaFloat("PrecioForaneo",
				   "%.2f",
				   lfltPrecioForaneo,
				   pSiscomOpePtrDato);
LogSiscom("Precio:%f Precio Foraneo:%f",
	lfltPrecio,
	lfltPrecioForaneo);
return 0;
}
int EnviaCalculoCostoProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
return 0;
}



void GeneraValorCosto(SiscomOperaciones *pSiscomOpePtrDato,
		      char *pchrPtrCostoMIva,
		      char *pchrPtrCostoIva)
{
float lfltCostoMIva,
	lfltCostoIva,
	lfltCosto;
lfltCosto=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Costo",pSiscomOpePtrDato);;
lfltCostoMIva=lfltCosto*1.16;
lfltCostoIva=lfltCosto*(.16);
sprintf(pchrPtrCostoMIva,"%.2f",lfltCostoMIva);
sprintf(pchrPtrCostoIva,"%.2f",lfltCostoIva);
}
int AgregaFechaHoy(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrFecha[20];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
SiscomActualizaCampoAsociadoEntrada("Envio","Fecha",lchrArrFecha,pSiscomOpePtrDato);
}

int AgregaFechaHoyCostoDescuento(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAsignaFechaAsociadoAsociadoEntrada("Envio","Costo","Fecha",pSiscomOpePtrDato);
}

int GeneraIdCosto(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdAsociadoAsociadosCampoEntrada("Envio",
				      "Costo",
				      "IdCosto",
				      pSiscomOpePtrDato);
}

int GeneraIdDescuento(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdAsociadoAsociadosCampoEntrada("Envio",
				      "Descuento",
				      "IdDescuento",
				      pSiscomOpePtrDato);
}


int FormaCamposRespuesta(SiscomOperaciones *pSiscomOpePtrDato)
{
 SiscomAnexaRegistroRespuesta(pSiscomOpePtrDato);
 SiscomAgregaCampoRegistroRespuesta("IdCosto",0,pSiscomOpePtrDato); 
 SiscomAgregaCampoRegistroRespuesta("IdDescuento",0,pSiscomOpePtrDato); 
 SiscomAgregaCampoRegistroRespuesta("Costo",0,pSiscomOpePtrDato); 
 return 0;
}

int FormaCamposCalculoPrecios(SiscomOperaciones *pSiscomOpePtrDato)
{
 SiscomAnexaRegistroRespuesta(pSiscomOpePtrDato);
 SiscomAgregaCampoRegistroRespuesta("Precio",0,pSiscomOpePtrDato); 
 SiscomAgregaCampoRegistroRespuesta("PrecioForaneo",0,pSiscomOpePtrDato); 
 return 0;
 }
