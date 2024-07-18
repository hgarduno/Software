#include <Facturando4.h>
#include <SqlClientes4.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>

#include <SiscomInsercionesSql.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
#include <ComunSiscomElectronica4.h>
#include <string.h>
#include <stdlib.h>

#include <PdfFactura.h>

SiscomArchivoFacturando gSiscomAFacturandoArrFunciones[]={ 
						{
						FacturandoDatosFactura,
						FacturandoDatosEmisor,
						FacturandoDatosClienteEmpresa,
						FacturandoDireccion,
						FacturandoIva,
						FacturandoProductos,
						0
						},
						{
						FacturandoDatosFactura_3_3,
						FacturandoDatosEmisor_3_3,
						FacturandoDatosClienteEmpresa_3_3,
						FacturandoDireccion_3_3,
						FacturandoIva_3_3,
						FacturandoProductos_3_3,
						0
						},
						{
						FacturandoGeneraXML_4_0,
						0
						},
					      };
						

					      

void ReEnviaFactura(int pintSocket,
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
SiscomAgregaOperacion(SqlAmbienteFacturacionPhp,&lSiscomProDat);
SiscomAgregaOperacion(ReEnviandoFactura,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void DatosParaReEnvioFactura(int pintSocket,
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
SiscomAgregaOperacion(SqlConsultaParaReEnvioFactura,&lSiscomProDat);
SiscomAgregaOperacion(EnviaDatosReEnvioFactura,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void CalculaFactura(int pintSocket,
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
SiscomAgregaOperacion(EnviaCalculoFactura,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RegistraClienteFacturacion(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoRegistroCliente,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdPersona4,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdEmpresa4,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraPersona4,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraEmpresa4,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraDireccion4,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraTelefonos4,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraCorreos4,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviaRegistroCliente,&lSiscomProDat);
SiscomAgregaOperacion(RegistraCliente4,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RealizaFactura(int pintSocket,
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
SiscomAgregaOperacion(AsignaIdFactura,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoRegistroFactura,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoAmbienteFacturacionPhp,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFecha,&lSiscomProDat);
SiscomAgregaOperacion(VerificandoCaracteres,&lSiscomProDat);
SiscomAgregaOperacion(SqlAmbienteFacturacionPhp,&lSiscomProDat);
SiscomAgregaOperacion(RealizandoFactura,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ValidaRfcRegistrado(int pintSocket,
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
/*SiscomAgregaOperacion(SqlClienteRegistrado4,&lSiscomProDat); */
SiscomAgregaOperacion(ValidandoRfcRegistrado,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void AgregaCorreoCliente(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoRegistroCliente,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraCorreos4,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviaRegistroCliente,&lSiscomProDat);
SiscomAgregaOperacion(AgregandoCorreoCliente,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}



int EnviaCalculoFactura(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrRegreso,
		   *lSiscomRegProLPtrFactura;
float lfltImporte,lfltIva;

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
if((lSiscomRegProLPtrRegreso=CalculandoFacturaOrdenes(pSiscomOpePtrDato,&lfltImporte)))
{
	lSiscomRegProLPtrFactura=FormaRegistroCalculaFactura(lSiscomRegProLPtrRegreso);
	lfltIva=CalculandoElIva(lfltImporte,lSiscomRegProLPtrRegreso);
	AgregaImportesMasIva(lfltImporte,lfltIva,lSiscomRegProLPtrFactura);
	SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrFactura);
	SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
				   lchrArrBuffer,
				   lSiscomRegProLPtrFactura);
}
return 0;
}
void AnexandoOrdenFactura(SiscomRegistroProL *pSiscomRegProLPtrDat,
			    SiscomRegistroProL **pSiscomRegProLPtrRegresoPrim,
			    SiscomRegistroProL **pSiscomRegProLPtrRegresoAct)
{
char lchrArrBuffer[128];
 SiscomRegistroProL *lSiscomRegProLPtrRegreso;


for(lSiscomRegProLPtrRegreso=pSiscomRegProLPtrDat;
    lSiscomRegProLPtrRegreso;
    lSiscomRegProLPtrRegreso=lSiscomRegProLPtrRegreso->SiscomRegProLPtrSig)
     SiscomNodoRegistroPro(lSiscomRegProLPtrRegreso->SiscomCamProLPtrDato,
     			   pSiscomRegProLPtrRegresoPrim,
     			   pSiscomRegProLPtrRegresoAct);
}
void ActualizaCantidadProducto(SiscomRegistroProL *pSiscomRegProLPtrProducto,
			       SiscomRegistroProL *pSiscomRegProLPtrFactura)
{
float lfltCantidad=SiscomObtenCampoRegistroProLFloat("importe",pSiscomRegProLPtrProducto);
lfltCantidad+=SiscomObtenCampoRegistroProLFloat("importe",pSiscomRegProLPtrFactura);
SiscomActualizaCampoFloatRegistroActual("importe","%.2f",lfltCantidad,pSiscomRegProLPtrFactura);
}
void ActualizaImporteProducto(SiscomRegistroProL *pSiscomRegProLPtrProducto,
			       SiscomRegistroProL *pSiscomRegProLPtrFactura)
{
float lfltCantidad=SiscomObtenCampoRegistroProLFloat("cantidad",pSiscomRegProLPtrProducto);
lfltCantidad+=SiscomObtenCampoRegistroProLFloat("cantidad",pSiscomRegProLPtrFactura);
SiscomActualizaCampoFloatRegistroActual("cantidad","%.2f",lfltCantidad,pSiscomRegProLPtrFactura);
}

int SumaPrecioCantidadProductoOrden(SiscomRegistroProL *pSiscomRegProLPtrProducto,
				    SiscomRegistroProL **pSiscomRegProLPtrRegresoPrim,
				    SiscomRegistroProL **pSiscomRegProLPtrRegresoAct)
{
int lintRegreso=0;
SiscomRegistroProL *lSiscomRegProLPtrFactura=*pSiscomRegProLPtrRegresoPrim;
  for( ;
       lSiscomRegProLPtrFactura;
       lSiscomRegProLPtrFactura=lSiscomRegProLPtrFactura->SiscomRegProLPtrSig)
  {
	if(!SiscomComparaCampoRegistrosProL("cveproducto",
					    lSiscomRegProLPtrFactura,
					    pSiscomRegProLPtrProducto))
	{
	   ActualizaCantidadProducto(pSiscomRegProLPtrProducto,lSiscomRegProLPtrFactura);
	   ActualizaImporteProducto(pSiscomRegProLPtrProducto,lSiscomRegProLPtrFactura);
	   lintRegreso=1;
	}
  }
  return lintRegreso;
}
void AgregandoProductosOrden(SiscomRegistroProL *pSiscomRegProLPtrProductos,
			     SiscomRegistroProL **pSiscomRegProLPtrRegresoPrim,
			     SiscomRegistroProL **pSiscomRegProLPtrRegresoAct)
{
SiscomRegistroProL *lSiscomRegProLPtrDatos;
for(lSiscomRegProLPtrDatos=pSiscomRegProLPtrProductos;
     lSiscomRegProLPtrDatos;
     lSiscomRegProLPtrDatos=lSiscomRegProLPtrDatos->SiscomRegProLPtrSig)
{
  if(!SumaPrecioCantidadProductoOrden(lSiscomRegProLPtrDatos,
  				  pSiscomRegProLPtrRegresoPrim,
				  pSiscomRegProLPtrRegresoAct))
   SiscomNodoRegistroPro(lSiscomRegProLPtrDatos->SiscomCamProLPtrDato,
   			 pSiscomRegProLPtrRegresoPrim,
			 pSiscomRegProLPtrRegresoAct);
}
}
SiscomRegistroProL *FormaRegistroCalculaFactura(SiscomRegistroProL *pSiscomRegProLPtrProductos)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrFacturaPrim=0,
		   *lSiscomRegProLPtrFacturaAct=0;
SiscomAnexaRegistroPro(&lSiscomRegProLPtrFacturaPrim,
		       &lSiscomRegProLPtrFacturaAct,
		       lchrArrBuffer,
		      "Total,Iva,Importe,Productos,",
			"0.0",
			"0.0",	
			"0.0",
			(char *)0);
SiscomRegistrosAlCampo("Productos",
			pSiscomRegProLPtrProductos,
			pSiscomRegProLPtrProductos,
			lSiscomRegProLPtrFacturaPrim);
return lSiscomRegProLPtrFacturaPrim;
}
void AgregaImportesMasIva(float pfltImporteTotal,
			  float pfltIva,
			  SiscomRegistroProL *pSiscomRegProLPtrFactura)
{
float lfltImporteMasIva=pfltImporteTotal+pfltIva;
LogSiscom("%f %f",lfltImporteMasIva,pfltIva);
SiscomActualizaCampoFloatRegistroActual("Importe","%.2f",pfltImporteTotal,pSiscomRegProLPtrFactura);
SiscomActualizaCampoFloatRegistroActual("Total","%.2f",lfltImporteMasIva,pSiscomRegProLPtrFactura);
SiscomActualizaCampoFloatRegistroActual("Iva","%.2f",pfltIva,pSiscomRegProLPtrFactura);
}
float CalculandoElIva(float pfltTotalOrden,SiscomRegistroProL *pSisRegProLPtrProductos)
{
/*
char lchrArrBuffer[2048];

*/
float lfltImporte=0.16*pfltTotalOrden;

/*
for(;
	pSisRegProLPtrProductos;
	pSisRegProLPtrProductos=pSisRegProLPtrProductos->SiscomRegProLPtrSig)
  lfltImporte+=0.1600000*SiscomObtenCampoRegistroProLFloat("importe",pSisRegProLPtrProductos);
LogSiscom("%f",lfltImporte);

*/
return lfltImporte;
}
SiscomRegistroProL *CalculandoFacturaOrdenes(SiscomOperaciones *pSiscomOpePtrDato,
					     float *pfltPtrImporte)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrDatos,
		   *lSiscomRegProLPtrRegresoPrim=0,
		   *lSiscomRegProLPtrRegresoAct=0,
		   *lSiscomRegProLPtrProductos=0;
float lfltImporteTotal=0.0,
	lfltIva,
	lfltTotalOrden;
lfltTotalOrden=SiscomCampoAsociadoEntradaOperacionFloat("Envio","totalorden",pSiscomOpePtrDato);
if((lSiscomRegProLPtrDatos=SiscomRegistrosAsociadoEntradaOperacion("Envio",pSiscomOpePtrDato)))
{
   for(;
   	lSiscomRegProLPtrDatos;
	lSiscomRegProLPtrDatos=lSiscomRegProLPtrDatos->SiscomRegProLPtrSig)
   {
       
	lSiscomRegProLPtrProductos=SiscomObtenRegistrosCampoProL("Productos",lSiscomRegProLPtrDatos);
	lfltImporteTotal+=SiscomObtenCampoRegistroProLFloat("totalorden",lSiscomRegProLPtrDatos);
	if(!lSiscomRegProLPtrRegresoPrim)
	AnexandoOrdenFactura(lSiscomRegProLPtrProductos,
			     &lSiscomRegProLPtrRegresoPrim,
			     &lSiscomRegProLPtrRegresoAct);
	else
	AgregandoProductosOrden(lSiscomRegProLPtrProductos,
				&lSiscomRegProLPtrRegresoPrim,
				&lSiscomRegProLPtrRegresoAct);
   }
lfltIva=CalculandoElIva(lfltImporteTotal,lSiscomRegProLPtrProductos);
LogSiscom("El Importe de las ordenes %f el Iva %f",lfltImporteTotal,lfltIva);
AgregaImportesMasIva(lfltImporteTotal,lfltIva,lSiscomRegProLPtrRegresoPrim); 
}
*pfltPtrImporte=lfltImporteTotal;
return lSiscomRegProLPtrRegresoPrim;
}



int ArgumentoRegistroCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlCliente",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
int ArgumentoAmbienteFacturacionPhp(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("AmbientePhp",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}

int ArgumentoRegistroFactura(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlRegistroFactura",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
int GeneraIdPersona4(SiscomOperaciones *pSiscomOpePtrDato)
{
if(EsPersonaFisica(pSiscomOpePtrDato))
SiscomIdAsociadosCampoEntrada("Envio","Persona","IdPersona",pSiscomOpePtrDato);
}

int GeneraIdEmpresa4(SiscomOperaciones *pSiscomOpePtrDato)
{
if(!EsPersonaFisica(pSiscomOpePtrDato))
SiscomIdAsociadosCampoEntrada("Envio","Empresa","IdEmpresa",pSiscomOpePtrDato);
}

int RegistraCliente4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
const char *lchrPtrIdEmpresa;
SiscomAsociadosArgumentoLog("SqlCliente",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
/* Tepotzotlan Mexico a 19 de Diciembre del 2017
 * Despues de ver a Jazmin, usar solo la razon social como nombre 
 * para una persona fisica o un persona moral, para rapido, regreso 
 * solo el IdEmpresa, sin realizar la validacion si es Fisica o Moral
 */
lchrPtrIdEmpresa=SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
							     "Empresa",
							     "IdEmpresa",
							     pSiscomOpePtrDato);
LogSiscom("El id de la empresa:%s",lchrPtrIdEmpresa);
pSiscomOpePtrDato->SiscomRegProLPtrPrimRes=0;
pSiscomOpePtrDato->SiscomRegProLPtrActRes=0;
SiscomAnexaRegistroPro(&pSiscomOpePtrDato->SiscomRegProLPtrPrimRes,
  			 &pSiscomOpePtrDato->SiscomRegProLPtrActRes,
			 lchrArrBuffer,
			 "IdEmpresa,",
			 lchrPtrIdEmpresa);
  SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);

}
int EsPersonaFisica(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
if((lSiscomRegProLPtrDato=SiscomRegistroAsociadoEntradaOperacion("Envio","Cliente",pSiscomOpePtrDato)))
  return SiscomObtenRegistrosCampoProL("Persona",lSiscomRegProLPtrDato) ? 1 :0;
if((lSiscomRegProLPtrDato=SiscomRegistroAsociadoEntradaOperacion("Envio","Persona",pSiscomOpePtrDato)))
 return lSiscomRegProLPtrDato ? 1 : 0;
}
void FormaNombreArchivoFactura(SiscomOperaciones *pSiscomOpePtrDato,
			       char *pchrPtrArchivo)
{
char lchrArrBuffer[128];
char lchrArrIdArchivo[18];
SiscomObtenNumeroUnicoChar(lchrArrIdArchivo);
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
sprintf(pchrPtrArchivo,
	"%s/%s.%s.SiscomFacturacion",
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","rutaarchivofactura",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","RFC",pSiscomOpePtrDato),
lchrArrIdArchivo);

}
void FacturandoDatosFactura(SiscomOperaciones *pSiscomOpePtrDato,FILE *pFlePtrArchivo)
{
char lchrArrFechaHora[25];
  SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
	fprintf(pFlePtrArchivo,
		"%d|%s|Pago en una sola exhibicion|%s|%s|Efectivo 01|%s\n",
		1,
		lchrArrFechaHora,
		SiscomCampoAsociadoEntradaOperacion("Envio","Importe",pSiscomOpePtrDato),
		SiscomCampoAsociadoEntradaOperacion("Envio","Total",pSiscomOpePtrDato),
		SiscomCampoAsociadoEntradaOperacion("Envio","TotalLetra",pSiscomOpePtrDato));
}
void FacturandoDatosEmisor(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
	fprintf(pFlePtrArchivo,"%s|Soluciones En Sistemas de Computo y Electronica S.A. de C.V.\n",
		SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","rfcemisor",pSiscomOpePtrDato));
	fprintf(pFlePtrArchivo,"Eva Samano de Lopez Mateos|28|1|Bo Tlacateco|Tepotzotlan|México|México|54600\n");
	fprintf(pFlePtrArchivo,"Regimen General Personas Morales\n");

}
void FacturandoDatosClienteEmpresa(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
lSiscomRegProLPtrDato=SiscomRegistroAsociadoEntradaOperacion("Envio",
							     "Cliente",
							     pSiscomOpePtrDato);
fprintf(pFlePtrArchivo,
	"%s|%s\n",
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","RFC",pSiscomOpePtrDato),
	SiscomAsociadoPrimerCampo("Empresa","RazonSocial",lSiscomRegProLPtrDato));
}
void FacturandoDatosClienteFisica(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
lSiscomRegProLPtrDato=SiscomRegistroAsociadoEntradaOperacion("Envio",
							     "Cliente",
							     pSiscomOpePtrDato);
fprintf(pFlePtrArchivo,
	"%s|%s %s %s\n",
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","RFC",pSiscomOpePtrDato),
	SiscomAsociadoPrimerCampo("Persona","Nombre",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Persona","APaterno",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Persona","AMaterno",lSiscomRegProLPtrDato));
}

void FacturandoDireccion(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
const char *lchrPtrNumeroInt;
lSiscomRegProLPtrDato=SiscomRegistroAsociadoEntradaOperacion("Envio",
							     "Cliente",
							     pSiscomOpePtrDato);
lchrPtrNumeroInt=SiscomAsociadoPrimerCampo("Direccion","NumeroInt",lSiscomRegProLPtrDato);
LogSiscom("El numero interior %s",lchrPtrNumeroInt);
fprintf(pFlePtrArchivo,
	"%s|%s|%s|%s|%s|%s|%s|%s\n",
	SiscomAsociadoPrimerCampo("Direccion","Calle",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Direccion","Numero",lSiscomRegProLPtrDato),
	/*  Miercoles 9 Agosto del 2017
	 *
	lchrPtrNumeroInt ? lchrPtrNumeroInt : "",
	*/
	"0",
	SiscomAsociadoPrimerCampo("Direccion","Colonia",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Direccion","Delegacion",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Direccion","Estado",lSiscomRegProLPtrDato),
	"Mexico",
	SiscomAsociadoPrimerCampo("Direccion","CP",lSiscomRegProLPtrDato));
}
void FacturandoIva(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
fprintf(pFlePtrArchivo,
	"%s\n",
SiscomCampoAsociadoEntradaOperacion("Envio","Iva",pSiscomOpePtrDato));
}
void FacturandoProductos(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrProductos;
lSiscomRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio",
								  "Productos",
								  pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrProductos);	
for(;
    lSiscomRegProLPtrProductos;
    lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
{
 fprintf(pFlePtrArchivo,
 	"%s|Pza|%s|%s|%s|%s\n",
  	SiscomObtenCampoRegistroProLChar("cantidad",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("cveproducto",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("cveproducto",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("precio",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("importe",lSiscomRegProLPtrProductos));
}
}

void FacturandoDatosFactura_3_3(SiscomOperaciones *pSiscomOpePtrDato,FILE *pFlePtrArchivo)
{
char lchrArrFechaHora[25];
 LogSiscom("Forma Pago Codigo(%s) Forma Pago(%s)",
 	   SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
	   					       "FormaPago",
						       "codigo",
						       pSiscomOpePtrDato),
 	   SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
	   					       "FormaPago",
						       "formapago",
						       pSiscomOpePtrDato));
  SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
	fprintf(pFlePtrArchivo,
		"%d|%s|%s|%s|%s|%s|%s|%s||\n",
		1,
		lchrArrFechaHora,
 	        SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
	   					            "FormaPago",
						             "codigo",
						              pSiscomOpePtrDato),
 	        SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
	   					            "FormaPago",
						            "formapago",
						             pSiscomOpePtrDato),
		SiscomCampoAsociadoEntradaOperacion("Envio","Importe",pSiscomOpePtrDato),
		SiscomCampoAsociadoEntradaOperacion("Envio","Total",pSiscomOpePtrDato),
 	        SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
	   					            "MetodoPago",
						            "codigo",
						             pSiscomOpePtrDato),
		SiscomCampoAsociadoEntradaOperacion("Envio","TotalLetra",pSiscomOpePtrDato));
}
void FacturandoDatosEmisor_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
	fprintf(pFlePtrArchivo,"%s|Soluciones En Sistemas de Cómputo y Electrónica S.A. de C.V.||\n",
		SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","rfcemisor",pSiscomOpePtrDato));
	fprintf(pFlePtrArchivo,"Eva Samano de López Mateos|28|1|Bo Tlacateco|Tepotzotlan|México|México|54600||\n");
	fprintf(pFlePtrArchivo,"Régimen General|601|\n");

}
void FacturandoDatosClienteEmpresa_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
lSiscomRegProLPtrDato=SiscomRegistroAsociadoEntradaOperacion("Envio",
							     "Cliente",
							     pSiscomOpePtrDato);
fprintf(pFlePtrArchivo,
	"%s|%s|%s|%s|\n",
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","RFC",pSiscomOpePtrDato),
	SiscomAsociadoPrimerCampo("Empresa","RazonSocial",lSiscomRegProLPtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
						    "UsoFactura",
						    "codigo",
						    pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
						    "UsoFactura",
						    "uso",
						    pSiscomOpePtrDato));
	
}
void FacturandoDatosClienteFisica_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
lSiscomRegProLPtrDato=SiscomRegistroAsociadoEntradaOperacion("Envio",
							     "Cliente",
							     pSiscomOpePtrDato);
fprintf(pFlePtrArchivo,
	"%s|%s %s %s\n",
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","RFC",pSiscomOpePtrDato),
	SiscomAsociadoPrimerCampo("Persona","Nombre",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Persona","APaterno",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Persona","AMaterno",lSiscomRegProLPtrDato));
}

void FacturandoDireccion_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
const char *lchrPtrNumeroInt;
lSiscomRegProLPtrDato=SiscomRegistroAsociadoEntradaOperacion("Envio",
							     "Cliente",
							     pSiscomOpePtrDato);
lchrPtrNumeroInt=SiscomAsociadoPrimerCampo("Direccion","NumeroInt",lSiscomRegProLPtrDato);
fprintf(pFlePtrArchivo,
	"%s|%s|%s|%s|%s|%s|%s|%s||\n",
	SiscomAsociadoPrimerCampo("Direccion","Calle",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Direccion","Numero",lSiscomRegProLPtrDato),
	/*  Miercoles 9 Agosto del 2017
	 *
	lchrPtrNumeroInt ? lchrPtrNumeroInt : "",
	*/
	"0",
	SiscomAsociadoPrimerCampo("Direccion","Colonia",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Direccion","Delegacion",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Direccion","Estado",lSiscomRegProLPtrDato),
	"Mexico",
	SiscomAsociadoPrimerCampo("Direccion","CP",lSiscomRegProLPtrDato));
}
void FacturandoIva_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
fprintf(pFlePtrArchivo,
	"%s||\n",
SiscomCampoAsociadoEntradaOperacion("Envio","Iva",pSiscomOpePtrDato));
}
void EncabezadoXML_4(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrXML)
{
sprintf(pchrPtrXML,
	"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
	"<cfdi:Comprobante"
	"\txmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
	"\tMoneda=\"MXN\"\n"
	"\tTotal=\"%s\"\n"
	"\txsi:schemaLocation=\"http://www.sat.gob.mx/cfd/4 http://www.sat.gob.mx/sitio_internet/cfd/4/cfdv40.xsd\"\n"
	"\tExportacion=\"01\"\n"
	"\tMetodoPago=\"%s\"\n"
	"\tTipoDeComprobante=\"I\"\n"
	"\tSubTotal=\"%s\"\n"
	"\tFormaPago=\"%s\"\n"
	"\tLugarExpedicion=\"20000\"\n"
	"\tFecha=\"%s\"\n"
	"\tFolio=\"1\"\n"
	"\tSerie=\"CFDI4I\"\n"
	"\tVersion=\"4.0\"\n"
	"\txmlns:cfdi=\"http://www.sat.gob.mx/cfd/4\">\n",
	SiscomCampoAsociadoEntradaOperacion("Envio","Total",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio", "MetodoPago","codigo",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","Importe",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","FormaPago","codigo",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato));

LogSiscom("%s %s %s",
	   SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","FormaPago","codigo",pSiscomOpePtrDato),
	   SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","FormaPago","formapago",pSiscomOpePtrDato),
	    SiscomCampoAsociadoAsociadoEntradaOperacion("Envio", "MetodoPago","codigo",pSiscomOpePtrDato));
}
/*  Siscom Zacatenco
 * Jueves 18 de Julio  2024 
 *
 * Con los caracteres raros en los datos fiscales , con esto cambio el ampersand por &amp; para que 
 * el formato de XML sea correcto
 *
 */
void CambiaAmpersandCadena(const char *pchrPtrCadena,char *pchrPtrSalida)
{
strcpy(pchrPtrSalida,pchrPtrCadena);
while(*pchrPtrCadena)
{
  *pchrPtrSalida=*pchrPtrCadena; 
   if(*pchrPtrSalida=='&')
   {
	strcpy(pchrPtrSalida+1,"amp;");
	pchrPtrSalida+=4;
   }
  pchrPtrCadena++;
  pchrPtrSalida++;
}
*pchrPtrSalida=0;
}
void FormateaRFC(const char *pchrPtrRFC,char *pchrPtrRFCSalida)
{

  CambiaAmpersandCadena(pchrPtrRFC,pchrPtrRFCSalida);

}

void FormateaRazonSocial(const char *pchrPtrRazonSocial,char *pchrPtrRazonSocialSalida)
{

  CambiaAmpersandCadena(pchrPtrRazonSocial,pchrPtrRazonSocialSalida);

}

/* 
 * Ecatepec Jueves 5 de octubre del 2023 
 *
 * Hay que poner el regimen fiscal del emisor en la base de datos, 
 * porque cuando cambio a facturar con mi RFC, es de persona fisica 
 *
 */
void EmisorXML_4(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrXML)
{
char lchrArrEmisor[512];
sprintf(lchrArrEmisor,
	"\n<cfdi:Emisor Rfc=\"%s\" Nombre=\"%s\" RegimenFiscal=\"601\"/>",
	 SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","rfcemisor",pSiscomOpePtrDato),
	 SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","razonsocial",pSiscomOpePtrDato));

strcat(pchrPtrXML,lchrArrEmisor);
}
void ReceptorXML_4(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrXML)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrDato;
char lchrArrReceptor[512],
	lchrArrCP[12];

char lchrArrRFC[25],lchrArrRazonSocial[256];

lSiscomRegProLPtrDato=SiscomRegistroAsociadoEntradaOperacion("Envio",
							     "Cliente",
							     pSiscomOpePtrDato);
FormateaRFC(SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","RFC",pSiscomOpePtrDato),lchrArrRFC);
FormateaRazonSocial(SiscomAsociadoPrimerCampo("Empresa","RazonSocial",lSiscomRegProLPtrDato),lchrArrRazonSocial);

sprintf(lchrArrCP,"%05d",atoi(SiscomAsociadoPrimerCampo("Direccion","CP",lSiscomRegProLPtrDato)));
sprintf(lchrArrReceptor,
	"\n<cfdi:Receptor Rfc=\"%s\" Nombre=\"%s\" DomicilioFiscalReceptor=\"%s\" RegimenFiscalReceptor=\"%s\" UsoCFDI=\"%s\"/>",
	/*
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","RFC",pSiscomOpePtrDato),
	*/
	lchrArrRFC,
	/*
	SiscomAsociadoPrimerCampo("Empresa","RazonSocial",lSiscomRegProLPtrDato),
	*/
	lchrArrRazonSocial,
	lchrArrCP,
	SiscomAsociadoPrimerCampo("Empresa","RegimenFiscal",lSiscomRegProLPtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","UsoFactura","codigo",pSiscomOpePtrDato));
strcat(pchrPtrXML,lchrArrReceptor);
}
const char *SiscomNumeroConDecimales(int pintNDecimales,
				     const char *pchrPtrNumero)
{
char *lchrPtrRegreso=strchr(pchrPtrNumero,'.');
int lintContador;
  if(lchrPtrRegreso)
  {
     lchrPtrRegreso++;
       for(lintContador=0;lintContador<pintNDecimales;lintContador++)
        lchrPtrRegreso++;
	*lchrPtrRegreso=0;
  }

  return pchrPtrNumero;
}
void ConceptosXML_4(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrXML)
{
char lchrArrConcepto[512];
int lintTamanoRegistro=0;
float lfltImporte,
	lfltImpuesto,lfltTotalImpuesto=0.0;
SiscomRegistroProL *lSiscomRegProLPtrProductos;
lSiscomRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio",
								  "Productos",
								  pSiscomOpePtrDato);
strcat(pchrPtrXML,"\n<cfdi:Conceptos>");

/*  Ciudad de Mexico a 25 de Agosto del 2023 
 *  Para calcular el tamano del XML, y hacer dinamico el buffer 
 *  se observo que el tamano del Registro es de 390 Bytes por cada producto
 */
for(;
    lSiscomRegProLPtrProductos;
    lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
{
  lfltImporte=SiscomObtenCampoRegistroProLFloat("importe",lSiscomRegProLPtrProductos)*1.16;
  lfltImpuesto=SiscomObtenCampoRegistroProLFloat("importe",lSiscomRegProLPtrProductos)*0.16;
 sprintf(lchrArrConcepto,
      "\n <cfdi:Concepto "
      " ClaveProdServ=\"32131000\""
      " Cantidad=\"%s\""
      " ClaveUnidad=\"H87\""
      " Unidad=\"Pieza\""
      " Descripcion=\"%s\""
      " ValorUnitario=\"%s\""
      " Importe=\"%s\""
      " ObjetoImp=\"02\">",
  	SiscomObtenCampoRegistroProLChar("cantidad",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("cveproducto",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("precio",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("importe",lSiscomRegProLPtrProductos));
  strcat(pchrPtrXML,lchrArrConcepto);
  sprintf(lchrArrConcepto,
  	 "\n\t<cfdi:Impuestos>"
	 "\n\t\t<cfdi:Traslados>"
         " \n\t\t\t<cfdi:Traslado Base=\"%.2f\" Impuesto=\"002\" TipoFactor=\"Tasa\" TasaOCuota=\"0.160000\" Importe=\"%.2f\"/>"
         " \n\t\t</cfdi:Traslados>"
         "\n\t</cfdi:Impuestos>"
	 "\n</cfdi:Concepto>",
	 SiscomObtenCampoRegistroProLFloat("importe",lSiscomRegProLPtrProductos),
	 lfltImpuesto);
   strcat(pchrPtrXML,lchrArrConcepto);
   lfltTotalImpuesto+=lfltImpuesto;
}
  strcat(pchrPtrXML,"\n</cfdi:Conceptos>");
}

void ImpuestosXML_4(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrXML)
{
char lchrArrXML[1024];
sprintf(lchrArrXML,
	" <cfdi:Impuestos TotalImpuestosTrasladados=\"%s\">\n"
        "        <cfdi:Traslados>\n"
        "                <cfdi:Traslado Base=\"%s\" Impuesto=\"002\" TipoFactor=\"Tasa\" TasaOCuota=\"0.160000\" Importe=\"%s\"/>\n"
        "        </cfdi:Traslados>\n"
        "</cfdi:Impuestos>",
	SiscomCampoAsociadoEntradaOperacion("Envio","Iva",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","Importe",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","Iva",pSiscomOpePtrDato));
strcat(pchrPtrXML,lchrArrXML);
}
void FinalXML_4(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrXML)
{
strcat(pchrPtrXML,"</cfdi:Comprobante>");
}
void NombreArchivoFacturacion_4_0(SiscomOperaciones *pSiscomOpePtrDato,
				  const char *pchrPtrExtension,
				  char *pchrPtrArchivo)
{
sprintf(pchrPtrArchivo,
	"%s/%s.%s%s",
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","rutaarchivofactura",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","RFC",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdFactura",pSiscomOpePtrDato),
pchrPtrExtension);
}
void NombreArchivoXML_4(SiscomOperaciones *pSiscomOpePtrDato, char *pchrPtrArchivo)
{
NombreArchivoFacturacion_4_0(pSiscomOpePtrDato,".xml",pchrPtrArchivo);
}
char *AsignaMemoriaXML_4(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrProductos;
char *lchrPtrRegreso;
int lintNRegistros;
int lintTamano=98  +  /*  Emisor     */
	       143 +  /*  Receptor   */
	       247;   /*  Impuestos  */

if((lSisRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio","Productos",pSiscomOpePtrDato)))
{
  
  lintTamano+=(lSisRegProLPtrProductos->intNRegistros*390);
  lintTamano+=128;
  lchrPtrRegreso=(char *)malloc(lintTamano);
  LogSiscom("El tamano del buffer %d",lintTamano);
  return lchrPtrRegreso;
}
}

void FacturandoGeneraXML_4_0(SiscomOperaciones *pSiscomOpePtrDato,FILE *pFlePtrArchivo)
{
/* Tepotzotlan Mexico a 23 de Abril del 2023 
 * Recuperandome de la operacion de prostata , ya me siento muy bien, creo
 * que la creatinina ya bajo
 *
 * Se debe declarar un apuntador, y calcular el tamano con base al numero 
 * de productos que llegan en la factura
 *
 */
/*
char *lchrArrXML=AsignaMemoriaXML_4(pSiscomOpePtrDato);
*/

char lchrArrXML[32000];
LogSiscom("Realizando la facturacion version 4");
EncabezadoXML_4(pSiscomOpePtrDato,lchrArrXML);
EmisorXML_4(pSiscomOpePtrDato,lchrArrXML);
ReceptorXML_4(pSiscomOpePtrDato,lchrArrXML);
ConceptosXML_4(pSiscomOpePtrDato,lchrArrXML);
ImpuestosXML_4(pSiscomOpePtrDato,lchrArrXML);
FinalXML_4(pSiscomOpePtrDato,lchrArrXML);
LogSiscom("EL archivo %x",pFlePtrArchivo);
fprintf(pFlePtrArchivo,"%s",lchrArrXML);
fflush(pFlePtrArchivo);

}
void FacturandoProductos_3_3(SiscomOperaciones *pSiscomOpePtrDato, FILE *pFlePtrArchivo)
{
SiscomRegistroProL *lSiscomRegProLPtrProductos;
lSiscomRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio",
								  "Productos",
								  pSiscomOpePtrDato);
for(;
    lSiscomRegProLPtrProductos;
    lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
{
/* Codigo para facturas siscom */
 fprintf(pFlePtrArchivo,
 	"%s|32101600|H87|%s|%s|%s|Pieza|%s|%s|\n",
  	SiscomObtenCampoRegistroProLChar("cantidad",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("cveproducto",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("importe",lSiscomRegProLPtrProductos),
  	SiscomObtenCampoRegistroProLChar("cveproducto",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("precio",lSiscomRegProLPtrProductos),
	SiscomObtenCampoRegistroProLChar("IvaProducto",lSiscomRegProLPtrProductos)); 
/* Para Factura Marco Acevedo 
 * En Medio del Covid 19 -> Octubre 2020 Ecatepec
 */

/*
 fprintf(pFlePtrArchivo,
 	"%s|%s|H87|%s|%s|%s|Pieza|%s|%s|\n",
  	SiscomObtenCampoRegistroProLChar("cantidad",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("sat",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("dscproducto",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("importe",lSiscomRegProLPtrProductos),
  	SiscomObtenCampoRegistroProLChar("cveproducto",lSiscomRegProLPtrProductos),	
  	SiscomObtenCampoRegistroProLChar("precio",lSiscomRegProLPtrProductos),
	SiscomObtenCampoRegistroProLChar("IvaProducto",lSiscomRegProLPtrProductos)); 
*/
}
}

/*  Codigos de Error en el timbrado
 *  1 -->  RFC Erroneo 
 *
 */
int EsErrorEnRFC(const char *pchrPtrLinea)
{
const char *lchrPtrRegreso;
	if((lchrPtrRegreso=strstr(pchrPtrLinea,"The 'rfc' attribute is invalid")))
	return 1;
	else
	return 0;
}
int EsErrorEnvioCorreo(const char *pchrPtrLinea,char *pchrPtrError)
{
const char *lchrPtrRegreso;
int lintRegreso=0;
	if((lchrPtrRegreso=strstr(pchrPtrLinea,"Error Correo")))
	{
		strcpy(pchrPtrError,lchrPtrRegreso+12);
		lintRegreso=2;
	}
	return lintRegreso;
}
int EsErrorTimbrado(const char *pchrPtrLinea,
		    char *pchrPtrError)
{
const char *lchrPtrRegreso;
int lintRegreso=0;
	 /*LogSiscom("Analizando ... (%s)",pchrPtrLinea); */
	if((lchrPtrRegreso=strstr(pchrPtrLinea,"Error")))
	{
	  	LogSiscom("Si hay error ...."); 
		strcpy(pchrPtrError,lchrPtrRegreso+6);
		lintRegreso=1;
	}

	return lintRegreso;

}

int EsErrorEnvioSat(const char *pchrPtrLinea,
		    char *pchrPtrError)
{
const char *lchrPtrRegreso;
 if((lchrPtrRegreso=strstr(pchrPtrLinea,"SOAPFault")))
 {
   LogSiscom("Error al enviar al Sat");
    strcpy(pchrPtrError,lchrPtrRegreso+11);
    return 3;
 }
  
  return 0;
}
void RegresaMensajeError(int pintRegreso,
			 const char *pchrPtrError,
			 SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],lchrArrRegreso[12];
sprintf(lchrArrRegreso,"%d",pintRegreso);
  SiscomAnexaRegistroPro(&pSiscomOpePtrDato->SiscomRegProLPtrPrimRes,
  			 &pSiscomOpePtrDato->SiscomRegProLPtrActRes,
			 lchrArrBuffer,
			 "SiscomElectronica,Estado,Descripcion,",
			 (const char *)0,
			 lchrArrRegreso,
			 pchrPtrError);
}

int ObtenDatosTimbrado(char *pchrPtrLinea,SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[4192];
char **lchrPtrCadenas;


 if(SiscomAnalizaCadenas(pchrPtrLinea,':',lchrArrBuffer,&lchrPtrCadenas))
 {
   LogSiscom("(Campo %s) (%s)",
   	     *(lchrPtrCadenas+0),
   	     *(lchrPtrCadenas+1));

   SiscomAgregaCampoAsociadoEntrada(*(lchrPtrCadenas+0),
   				    *(lchrPtrCadenas+1),
				    "Envio",
				    pSiscomOpePtrDato);
 }
}
int MuestraEstadoEjecucionPhp(FILE *pFlePtrComando,SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrLinea[1024],
	lchrArrMnsError[512];
int lintRegreso=0;
  while(!SiscomLeeLineaArchivo(pFlePtrComando,lchrArrLinea))
  {	
  	if(lchrArrLinea[0])
	{
	 LogSiscom("(%s)",lchrArrLinea);
	if((lintRegreso=EsErrorTimbrado(lchrArrLinea,lchrArrMnsError))==1)
	{
	  LogSiscom("%s",lchrArrMnsError);
	  /*
	   strcpy(lchrArrMnsError,"NO Se pudo conectar con el proveedor de \n"
	   			  "facturacion, no es posible generar la \n"
				  "FACTURA");
	  */
	   RegresaMensajeError(lintRegreso,lchrArrMnsError,pSiscomOpePtrDato);
	   return 1;

	}
	 else
	 if((lintRegreso=EsErrorEnvioCorreo(lchrArrLinea,lchrArrMnsError))==2)
	 {
	   strcpy(lchrArrMnsError,"Se genero la factura\n"
	   			  "pero no se envio el correo");
	   RegresaMensajeError(lintRegreso,lchrArrMnsError,pSiscomOpePtrDato);
	   return 2;
	 }
	 else
	if((lintRegreso=EsErrorEnvioSat(lchrArrLinea,lchrArrMnsError))==3)
	{
	   RegresaMensajeError(lintRegreso,lchrArrMnsError,pSiscomOpePtrDato);
	   return 3;
	}
	else
	ObtenDatosTimbrado(lchrArrLinea,pSiscomOpePtrDato);

 	}
  }
  return lintRegreso;
}
FILE *LanzaScriptPhp(const char *pchrPtrArchivo,
		     const char *pchrPtrCorreoCliente,
		     SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrComandoEjecucion[1024];
char lchrArrRutaDesarrolloPhp[1024];
char lchrArrArchivo[1024];
FILE *lFlePtrArchivo=0;
/*

sprintf(lchrArrComandoEjecucion,
	"%s %s/%s %s %s %s %s %s \"%s\" \"%s\" %s Envio 0",
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","binariophp",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","rutasistemaphpfacturacion",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","scriptfacturacion",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","rutasistemaphpfacturacion",pSiscomOpePtrDato),
pchrPtrArchivo,
pchrPtrCorreoCliente,
SiscomCampoAsociadoRespuestaOperacion("Correo","correo",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("Correo","password",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","usuario",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","urlservidor",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdFactura",pSiscomOpePtrDato));
LogSiscom("%s",lchrArrComandoEjecucion);

*/

NombreArchivoFacturacion_4_0(pSiscomOpePtrDato,"",lchrArrArchivo);	

sprintf(lchrArrComandoEjecucion,
	"%s %s/%s --Usuario=\"%s\" --WebService=\"%s\" --RutaASalida=\"%s\" --Archivo=\"%s\"",
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","binariophp",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","rutasistemaphpfacturacion",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","scriptfacturacion",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","usuario",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","urlservidor",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","rutaarchivofactura",pSiscomOpePtrDato),
lchrArrArchivo);

LogSiscom("%s\n",lchrArrComandoEjecucion);

lFlePtrArchivo=popen(lchrArrComandoEjecucion,"r");


return lFlePtrArchivo;
}
FILE *LanzaScriptPhpReEnvio(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrComandoEjecucion[1024];
char lchrArrRutaDesarrolloPhp[1024];
FILE *lFlePtrArchivo=0;
sprintf(lchrArrComandoEjecucion,
	"%s %s/%s %s %s %s %s %s \"%s\" \"%s\" %s ReEnvio 1",
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","binariophp",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","rutasistemaphpfacturacion",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","scriptfacturacion",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbientePhp","rutasistemaphpfacturacion",pSiscomOpePtrDato),
"Archivo",
SiscomCampoAsociadoEntradaOperacion("Envio","Correo",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("Correo","correo",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("Correo","password",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","usuario",pSiscomOpePtrDato),
SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","urlservidor",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","IdFactura",pSiscomOpePtrDato));
LogSiscom("%s",lchrArrComandoEjecucion);
lFlePtrArchivo=popen(lchrArrComandoEjecucion,"r");
return lFlePtrArchivo;
}

void CorreoActivoCliente(SiscomOperaciones *pSiscomOpePtrDato,
			 const char **pchrPtrCorreoActivo)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrDato;
if((lSiscomRegProLPtrDato=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion(
					"Envio",
					"Cliente",
					"CorreoActivo",
					pSiscomOpePtrDato)))
{
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrDato);
if((*pchrPtrCorreoActivo=SiscomObtenCampoRegistroProLChar("Correo",
							  lSiscomRegProLPtrDato)))
{

}
else
{

}
}
}
int CorrePhpFacturacion(const char *pchrPtrArchivo,
			 SiscomOperaciones *pSiscomOpePtrDato)
{
int lintRegreso=0;
FILE *lFlePtrArchivo;
const char *lchrPtrCorreoCliente;
CorreoActivoCliente(pSiscomOpePtrDato,&lchrPtrCorreoCliente);

  pSiscomOpePtrDato->SiscomRegProLPtrPrimRes=0;
if((lFlePtrArchivo=LanzaScriptPhp(pchrPtrArchivo,lchrPtrCorreoCliente,pSiscomOpePtrDato)))
{
  if(!(lintRegreso=MuestraEstadoEjecucionPhp(lFlePtrArchivo,pSiscomOpePtrDato)))
  FormaArchivoPdfFactura4_0(pSiscomOpePtrDato);
  pclose(lFlePtrArchivo);
}
return lintRegreso;
}
int FacturandoPersonaFisica(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrArchivo[1024];
FILE *lFlePtrArchivo;
  FormaNombreArchivoFactura(pSiscomOpePtrDato,lchrArrArchivo);
  if((lFlePtrArchivo=fopen(lchrArrArchivo,"w")))
  {
	FacturandoDatosFactura(pSiscomOpePtrDato,lFlePtrArchivo);
	FacturandoDatosEmisor(pSiscomOpePtrDato,lFlePtrArchivo);
	FacturandoDatosClienteFisica(pSiscomOpePtrDato,lFlePtrArchivo);
	FacturandoDireccion(pSiscomOpePtrDato,lFlePtrArchivo);
	FacturandoIva(pSiscomOpePtrDato,lFlePtrArchivo);
	FacturandoProductos(pSiscomOpePtrDato,lFlePtrArchivo);
        fclose(lFlePtrArchivo);	
	return CorrePhpFacturacion(lchrArrArchivo,pSiscomOpePtrDato); 
  }
  else 
  return 100; /* Error al abrir el archivo */
}
void GeneraArchivoDatosFacturacion(SiscomArchivoFacturando *pSiscomAFacturandoPtrDato,
				   SiscomOperaciones *pSiscomOpePtrDato,
				   FILE *pFlePtrArchivo,
				   int pintVersionFactura)
{
int lintContador;
for(lintContador=0;
    (pSiscomAFacturandoPtrDato+pintVersionFactura)->Facturando[lintContador];
    lintContador++)
(pSiscomAFacturandoPtrDato+pintVersionFactura)->Facturando[lintContador](pSiscomOpePtrDato,pFlePtrArchivo);
}
void SiscomFloatAChar(float pfltNumero,
		 int pintNDecimales,
		 char *pchrPtrSalida)
{
float lfltDecimal;
int lintEntero;
lfltDecimal=pfltNumero-(int )pfltNumero;
lintEntero=(int )(lfltDecimal*100);
sprintf(pchrPtrSalida,"%d.%d",(int )pfltNumero,lintEntero);
}
float AjustaDecimales(float pfltNumero)
{
float lfltDecimal;
lfltDecimal=pfltNumero-(int )pfltNumero;
LogSiscom("El importe %f",lfltDecimal);
if(lfltDecimal>=0.55)
{
 pfltNumero+=0.021111;
}
LogSiscom("---- %f",pfltNumero);
return pfltNumero;
}
void CalculosVersionFacturacion3_3(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrProductos,
		   *lSiscomRegProLPtrPasoProductos;
char lchrArrBuffer[128],lchrArrImporteOrden[128];
float lfltIvaProducto,
	lfltImporteOrden=0.0,
	lfltTotalOrden,
	lfltImporteProducto;
if((lSiscomRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio",
								      "Productos",
								      pSiscomOpePtrDato)))
{
lSiscomRegProLPtrPasoProductos=lSiscomRegProLPtrProductos;
SiscomAgregaCampoRegistros("IvaProducto",0,lSiscomRegProLPtrProductos);
for(;
	lSiscomRegProLPtrProductos;
	lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
{
 lfltImporteProducto=SiscomObtenCampoRegistroProLFloat("importe",lSiscomRegProLPtrProductos);
/* LogSiscom("%f",lfltImporteProducto); */
 /*
 lfltIvaProducto=lfltImporteProducto*0.16;
 */
 SiscomActualizaCampoFloatRegistroActual("IvaProducto","%.2f",lfltIvaProducto,lSiscomRegProLPtrProductos);
 /*
 lfltImporteOrden+=lfltIvaProducto+lfltImporteProducto;
 */
 lfltImporteOrden+=lfltImporteProducto;
}

lfltImporteOrden=AjustaDecimales(lfltImporteOrden);
SiscomFloatAChar(lfltImporteOrden,2,lchrArrImporteOrden);


lfltTotalOrden=lfltImporteOrden*1.16;

LogSiscom("Importe Orden %f  Total Orden %f",lfltImporteOrden,lfltTotalOrden);
sprintf(lchrArrImporteOrden,"%.2f",lfltTotalOrden);
SiscomActualizaCampoAsociadoEntrada("Envio","Total",lchrArrImporteOrden,pSiscomOpePtrDato);
}


}
int FacturandoEmpresa(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrArchivo[1024];
FILE *lFlePtrArchivo;
SiscomArchivoFacturando *lSiscomAFacturandoPtrProceso=gSiscomAFacturandoArrFunciones;
/*
 * Tepotzotlan Mexico a 23 de Abril del 2023
 *
 *
  FormaNombreArchivoFactura(pSiscomOpePtrDato,lchrArrArchivo);

*/
 NombreArchivoXML_4(pSiscomOpePtrDato,lchrArrArchivo); 
  LogSiscom("Archivo Datos Facturacion ( %s )",
  	    lchrArrArchivo);
  if((lFlePtrArchivo=fopen(lchrArrArchivo,"w")))
  {
  	CalculosVersionFacturacion3_3(pSiscomOpePtrDato); 
	GeneraArchivoDatosFacturacion(lSiscomAFacturandoPtrProceso,
				      pSiscomOpePtrDato,
				      lFlePtrArchivo,
				      2);
	
        fclose(lFlePtrArchivo);	
	return CorrePhpFacturacion(lchrArrArchivo,pSiscomOpePtrDato); 
  }
  else
  {
  LogSiscom("No se pudo Abrir el archivo(%s)",lchrArrArchivo);
  return 100; /* Error al abrir el archivo */
  }
}
void RegistrandoOrdenesFacturadasFisica(SiscomOperaciones *pSiscomOpePtrDato)
{
   SqlRegistraFacturaFisica(pSiscomOpePtrDato);
   SqlRegistraOrdenesFacturadas(pSiscomOpePtrDato);
   SqlEnviaRegistroFactura(pSiscomOpePtrDato);

}
void RegistrandoOrdenesFacturadasMoral(SiscomOperaciones *pSiscomOpePtrDato)
{
/*
	SqlRegistraFacturaMoral(pSiscomOpePtrDato);	
        SqlRegistraOrdenesFacturadas(pSiscomOpePtrDato);
   	SqlEnviaRegistroFactura(pSiscomOpePtrDato);


*/

LogSiscom(" Insercion de cosas de facturacion deshabilitada");
LogSiscom("*****************************************");
}
int RegresoEnvioFacturaExitoso(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(&pSiscomOpePtrDato->SiscomRegProLPtrPrimRes,
		       &pSiscomOpePtrDato->SiscomRegProLPtrActRes,
		       lchrArrBuffer,
		       "SiscomElectronica,Estado,Descripcion,",
		       (const char *)0,
		       "0",
		       "Generacion de Factura,y envio Exitoso");
  SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
}
void EnviaRegresoConErrorFacturacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
  SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
}
int SeRealizaInsercionOrdenFacturada(int pintRegreso)
{
    if(pintRegreso==0) /* Sin error */
     return 0;
    else 
    if(pintRegreso==1) /* Error en el timbrado, no hay conexion con el provedor*/
    return 1;	       /* de facturacion */
    else
    if(pintRegreso==2)  /*No Se pudo enviar el correo */
     return 2;
}
int RealizandoFactura(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
int lintRegreso;
  if(EsPersonaFisica(pSiscomOpePtrDato))
  {
	if(!(lintRegreso=FacturandoPersonaFisica(pSiscomOpePtrDato)))
	RegistrandoOrdenesFacturadasFisica(pSiscomOpePtrDato);
  }
  else
  {
     LogSiscom("********************** Facturando %s",
     		SiscomCampoAsociadoEntradaOperacion("Envio","IdFactura",pSiscomOpePtrDato));
     lintRegreso=SeRealizaInsercionOrdenFacturada(FacturandoEmpresa(pSiscomOpePtrDato));

    if(lintRegreso==0 || lintRegreso==2)
    {
     RegistrandoOrdenesFacturadasMoral(pSiscomOpePtrDato); 
     SiscomAsociadosArgumentoLog("SqlRegistroFactura",
 			     "SentenciasSql",
			     lchrArrBuffer,
			     pSiscomOpePtrDato);
    }
  }
  if(!lintRegreso)
  {
  pSiscomOpePtrDato->SiscomRegProLPtrPrimRes=0;
  pSiscomOpePtrDato->SiscomRegProLPtrActRes=0;
  RegresoEnvioFacturaExitoso(pSiscomOpePtrDato);
  }
  else
  EnviaRegresoConErrorFacturacion(pSiscomOpePtrDato);

  SiscomRegistroRegresoLog(lchrArrBuffer,pSiscomOpePtrDato);
}
SiscomRegistroProL *FormaRespuestaClienteRegistrado(
					   int pintPersonaFisica,
					   SiscomRegistroProL *pSiscomRegProLPtrPersona,
					   SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrRegresoPrim=0,
		   *lSiscomRegProLPtrRegresoAct=0,
		   *lSiscomRegProLPtrDireccion,
		   *lSiscomRegProLPtrCorreos,
		   *lSiscomRegProLPtrTelefonos; 


lSiscomRegProLPtrDireccion=SiscomObtenRegistrosCampoRespuesta("SqlDireccion",pSiscomOpePtrDato);
lSiscomRegProLPtrCorreos=SiscomObtenRegistrosCampoRespuesta("SqlCorreos",pSiscomOpePtrDato);
lSiscomRegProLPtrTelefonos=SiscomObtenRegistrosCampoRespuesta("SqlTelefonos",pSiscomOpePtrDato);

SiscomAnexaRegistroPro(&lSiscomRegProLPtrRegresoPrim,
		       &lSiscomRegProLPtrRegresoAct,
		       lchrArrBuffer,
		       "Persona,"
		       "Empresa,"
		       "Direccion,"
		       "Correos,"
		       "Telefonos,"
		       "RFC,",
			(const char *)0,
			(const char *)0,
			(const char *)0,
			(const char *)0,
			(const char *)0,
			(const char *)0);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrRegresoPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrTelefonos);
SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomRegProLPtrPersona);
if(pintPersonaFisica)
SiscomRegistrosAlCampo("Persona",
		       pSiscomRegProLPtrPersona,
		       pSiscomRegProLPtrPersona,
		       lSiscomRegProLPtrRegresoPrim);
else
SiscomRegistrosAlCampo("Empresa",
		       pSiscomRegProLPtrPersona,
		       pSiscomRegProLPtrPersona,
		       lSiscomRegProLPtrRegresoPrim);

		 		
SiscomRegistrosAlCampo("Direccion",
		       lSiscomRegProLPtrDireccion,
		       lSiscomRegProLPtrDireccion,
		       lSiscomRegProLPtrRegresoPrim);

SiscomRegistrosAlCampo("Correos",
		       lSiscomRegProLPtrCorreos,
		       lSiscomRegProLPtrCorreos,
		       lSiscomRegProLPtrRegresoPrim);
SiscomRegistrosAlCampo("Telefonos",
		       lSiscomRegProLPtrTelefonos,
		       lSiscomRegProLPtrTelefonos,
		       lSiscomRegProLPtrRegresoPrim);

return lSiscomRegProLPtrRegresoPrim;
}

void EnviaRfcNoRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "EdoValidacion,"
		       "Mensaje,",
		       "0",
		       "Cliente No Registrado");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
}
int RfcRegistradoFisica(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrCliente,
		   *lSiscomRegProLPtrRegreso;
if((lSiscomRegProLPtrCliente=SiscomObtenRegistrosCampoRespuesta("SqlPersona",pSiscomOpePtrDato)))
{
 SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrCliente);
 SqlDatosFisicaRegistrada(lSiscomRegProLPtrCliente,pSiscomOpePtrDato);
 lSiscomRegProLPtrRegreso=FormaRespuestaClienteRegistrado(1,
 				lSiscomRegProLPtrCliente,
				pSiscomOpePtrDato);
 SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
 			    lchrArrBuffer,
			    lSiscomRegProLPtrRegreso);
 return 1;
}
else
return 0;

}
int RfcRegistradoMoral(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrCliente,
		   *lSiscomRegProLPtrRegreso;
if((lSiscomRegProLPtrCliente=SiscomObtenRegistrosCampoRespuesta("SqlPersona",pSiscomOpePtrDato)))
{
 SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrCliente);
 SqlDatosMoralRegistrada(lSiscomRegProLPtrCliente,pSiscomOpePtrDato);
 lSiscomRegProLPtrRegreso=FormaRespuestaClienteRegistrado(0,lSiscomRegProLPtrCliente,pSiscomOpePtrDato);
 SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
 			    lchrArrBuffer,
			    lSiscomRegProLPtrRegreso);
 return 1;
}
else
return 0;

}

int ValidandoRfcRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
  SqlClienteRegistrado4(pSiscomOpePtrDato);
  if(RfcRegistradoFisica(pSiscomOpePtrDato))
	LogSiscom("Se enviaron los datos de una persona fisica");
  else
  {
   LogSiscom("No Estuvo en Personas, se busca en empresas");
   SqlClienteEmpresaRegistrado4(pSiscomOpePtrDato);
   if(RfcRegistradoMoral(pSiscomOpePtrDato))
   {
	LogSiscom("Se envia informacion de una empresa Registrada");
   }
   else
   {
    LogSiscom("Cliente no registrado");
    EnviaRfcNoRegistrado(pSiscomOpePtrDato);
   }
  }
}

int AgregandoCorreoCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrRegresoPrim=0,
		   *lSiscomRegProLPtrRegresoAct=0;
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(&lSiscomRegProLPtrRegresoPrim,
		       &lSiscomRegProLPtrRegresoAct,
			lchrArrBuffer,
			"Estado,"
			"Descripcion,",
			"0",
			"Probando el estado pra regresar");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrRegresoPrim);
}

int AsignaIdFactura(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio","IdFactura",pSiscomOpePtrDato);
}

int AgregaFecha(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaCampoAsociadoEntrada("Fecha",0,"Envio",pSiscomOpePtrDato);
SiscomAsignaFechaHoraAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
}


int EnviaDatosReEnvioFactura(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
LogSiscom("Para Re Enviar la Factura (Empresa) ");
SiscomAsociadoRespuestaLog("Empresa",lchrArrBuffer,pSiscomOpePtrDato);
LogSiscom("Correos ");
SiscomAsociadoRespuestaLog("Correos",lchrArrBuffer,pSiscomOpePtrDato);
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
}
int ReEnviandoFactura(SiscomOperaciones *pSiscomOpePtrDato)
{
FILE *lFlePtrRegresoPhp;
int lintRegreso;
 LogSiscom("Re Enviando la factura");
if((lFlePtrRegresoPhp=LanzaScriptPhpReEnvio(pSiscomOpePtrDato)))
{
  lintRegreso=MuestraEstadoEjecucionPhp(lFlePtrRegresoPhp,pSiscomOpePtrDato);
  pclose(lFlePtrRegresoPhp);

}
}

void IdentificandoCaracteresEspeciales(SiscomOperaciones *pSiscomOpePtrDato)
{
unsigned char lchrArrDescripcion[128];
const char *lchrPtrDescripcion=SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
									   "Productos",
									   "cveproducto",
									   pSiscomOpePtrDato);
strcpy(lchrArrDescripcion,lchrPtrDescripcion);

}

void ReemplazandoCaracteresNoValidos(SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
unsigned char lchrArrCarACambiar[512],
	      lchrArrCarPorCambiar[512],
	      lchrArrCveProducto[128],
	      lchrArrCveProductoRem[128];

memset(lchrArrCarACambiar,0,512);
memset(lchrArrCarPorCambiar,0,512);
SiscomNumeroCaracterACambiar(181,lchrArrCarACambiar);
SiscomNumeroCaracterRemplazar(181,'m',lchrArrCarPorCambiar);

strcpy(lchrArrCveProducto,
       SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrProducto));
     if(SiscomRemplazandoCaracteres(lchrArrCveProducto,
     				 lchrArrCarACambiar,
				 lchrArrCarPorCambiar,
				 lchrArrCveProductoRem))
     {

     SiscomActualizaCampoRegistroActual("cveproducto",
     					lchrArrCveProductoRem,
					pSiscomRegProLPtrProducto);
     }
}
				     
int VerificandoCaracteres(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrProductos;
lSiscomRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio",
								  "Productos",
								  pSiscomOpePtrDato);
for( ;
    lSiscomRegProLPtrProductos;
    lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
{
  ReemplazandoCaracteresNoValidos(lSiscomRegProLPtrProductos);  
}

return 0;
}

int FormaArchivoPdfFactura4_0(SiscomOperaciones *pSisOpePtrDatos)
{
PdfFacturaSiscomElectronica(pSisOpePtrDatos);
}

