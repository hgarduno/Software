#include <OrdenesVendidas.h>
#include <TiendaLinea.h>

#include <SqlTiendaLinea.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>
#include <SqlOrdenesVendidas.h>
#include <SqlOrdenes.h>



#include <string.h>
#include <stdlib.h>
InformacionPorTipoOrden gInformacionPorTipoOrden[15]={
			    InformacionVenta,
			    InformacionCotizacion,
			    InformacionApartado,
			    0,
			    InformacionPedido,
			    InformacionCancelacion,
			    0,
			    0,
			    0,
			    0,
			    0,
			    InformacionPagoTransferencia,
			    0,
			    0
			};


StcConsultandoOrdenes gStcConOrdenes[]={
			{"PorRangoFechas",PorRangoFechas},
			{"PorHoraEntrega",PorHoraEntrega},
			{0,0}
			};



void OrdenesVendidas2(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoCotizaciones,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoPedidos,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoApartados,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoVentas,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoCondicionVentas,&lSiscomProDat);
SiscomAgregaOperacion(ComoHagoLaConsultaOrdenes,&lSiscomProDat);  
SiscomAgregaOperacion(ConsultandoDatosPorTipoOrden,&lSiscomProDat); 
SiscomAgregaOperacion(SqlOrdenesVendidas2,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoOrdenesVendidas2,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void OrdenesVendidas(int pintSocket,
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
SiscomAgregaOperacion(SqlOrdenesVendidas,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoOrdenesVendidas,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void OrdenesParaFacturar(int pintSocket,
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
SiscomAgregaOperacion(SqlOrdenesParaFacturar,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoOrdenesVendidas,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void OrdenParaFacturar(int pintSocket,
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
SiscomAgregaOperacion(SqlOrdenParaFacturar,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoOrdenesVendidas,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void OrdenesApartados(int pintSocket,
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
SiscomAgregaOperacion(SqlConsultaApartados,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoApartados,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ProductoEnApartados(int pintSocket,
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
SiscomAgregaOperacion(SqlProductoEnApartados,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoApartados,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConsultaOrdenVendida(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSisOpeErrS={
				      0,
				      NOSeEncontroOrden,
				      };
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlConsultaOrden,&lSiscomProDat);
SiscomAgregaOperacion(SeEncontroLaOrden,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoOrden,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSisOpeErrS,lSiscomProDat);
}

int EnviandoOrdenesVendidas2(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrRegreso;

lSiscomRegProLPtrRegreso=AgrupaOrdenesVendidas2(pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrRegreso);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  lSiscomRegProLPtrRegreso);

return 0;
}


int EnviandoOrdenesVendidas(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrRegreso;
char lchrArrBuffer[128];
lSiscomRegProLPtrRegreso=AgrupaOrdenesVendidas(pSiscomOpePtrDato);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  lSiscomRegProLPtrRegreso);
return 0;
}

int EnviandoApartados(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];

SiscomEnviaAsociadoRespuestaCliente("Apartados",
				    lchrArrBuffer,
				    pSiscomOpePtrDato);

return 0;
}
void AgregaInformacionCotizacion(SiscomRegistroProL *pSiscomRegProLPtrDato,
				 SiscomRegistroProL *pSiscomRegProLPtrCotizaciones)
{
SiscomRegistroProL *lSiscomRegProLPtrCotizacionPrim=0,
		   *lSiscomRegProLPtrCotizacionAct=0;
		  
  for(;
      pSiscomRegProLPtrCotizaciones;
      pSiscomRegProLPtrCotizaciones=pSiscomRegProLPtrCotizaciones->SiscomRegProLPtrSig)
  { 
     if(!SiscomComparaCampoRegistrosProL("idventa",
     					pSiscomRegProLPtrDato,
					pSiscomRegProLPtrCotizaciones))
     {
       SiscomNodoRegistroPro(pSiscomRegProLPtrCotizaciones->SiscomCamProLPtrDato,
       			     &lSiscomRegProLPtrCotizacionPrim,
			     &lSiscomRegProLPtrCotizacionAct);
       SiscomRegistrosAlCampo("Cotizacion",
       			       lSiscomRegProLPtrCotizacionPrim,
			       lSiscomRegProLPtrCotizacionAct,
       			       pSiscomRegProLPtrDato);
     }
  }
}
void AgregaImporteCotizacion(SiscomRegistroProL *pSiscomRegProLPtrDato)
{
char lchrArrBuffer[128];
float lfltImporte=0.0;
SiscomRegistroProL *lSiscomRegProLPtrProductos;
lSiscomRegProLPtrProductos=SiscomObtenRegistrosCampoProL("Productos",pSiscomRegProLPtrDato);
lfltImporte=SiscomObtenSumatoriaRegistros("importe",lSiscomRegProLPtrProductos);
SiscomActualizaCampoFloatRegistroActual("importeorden","%.2f",lfltImporte,pSiscomRegProLPtrDato);
}
void CompletandoCotizacion(SiscomRegistroProL *pSiscomRegProLPtrDato,
			   SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
lSiscomRegProLPtrDato=SiscomObtenArgumentoPrimOperaciones("SqlCotizaciones",pSiscomOpePtrDato);
    for(;
        pSiscomRegProLPtrDato;
	pSiscomRegProLPtrDato=pSiscomRegProLPtrDato->SiscomRegProLPtrSig)
    {
    	 AgregaImporteCotizacion(pSiscomRegProLPtrDato);
         AgregaInformacionCotizacion(pSiscomRegProLPtrDato,lSiscomRegProLPtrDato);
    }
}
void AgregaInformacionPedido(SiscomRegistroProL *pSisRegProLPtrDato,
			     SiscomRegistroProL *pSisRegProLPtrPedidos)
{
SiscomRegistroProL *lSisRegProLPtrPedidoPrim=0,
		   *lSisRegProLPtrPedidoAct=0;
    for(;
    	pSisRegProLPtrPedidos;
	pSisRegProLPtrPedidos=pSisRegProLPtrPedidos->SiscomRegProLPtrSig)
    {
      if(!SiscomComparaCampoRegistrosProL("idventa",
      					 pSisRegProLPtrDato,
					 pSisRegProLPtrPedidos))
      {
        SiscomNodoRegistroPro(pSisRegProLPtrPedidos->SiscomCamProLPtrDato,
			      &lSisRegProLPtrPedidoPrim,
			      &lSisRegProLPtrPedidoAct);
	SiscomRegistrosAlCampo("Pedido",
				lSisRegProLPtrPedidoPrim,
				lSisRegProLPtrPedidoAct,
				pSisRegProLPtrDato);
      }
    }

}
void CompletandoPedido(SiscomRegistroProL *pSiscomRegProLPtrDato,
		       SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrPedidos;
lSisRegProLPtrPedidos=SiscomObtenArgumentoPrimOperaciones("SqlPedidos",pSiscomOpePtrDato);
for( ;pSiscomRegProLPtrDato;
      pSiscomRegProLPtrDato=pSiscomRegProLPtrDato->SiscomRegProLPtrSig)
{
    AgregaInformacionPedido(pSiscomRegProLPtrDato,lSisRegProLPtrPedidos);
}
}

void AgregaInformacionApartado(SiscomRegistroProL *pSisRegProLPtrDato,
			     SiscomRegistroProL *pSisRegProLPtrPedidos)
{
SiscomRegistroProL *lSisRegProLPtrPedidoPrim=0,
		   *lSisRegProLPtrPedidoAct=0;
    for(;
    	pSisRegProLPtrPedidos;
	pSisRegProLPtrPedidos=pSisRegProLPtrPedidos->SiscomRegProLPtrSig)
    {
      if(!SiscomComparaCampoRegistrosProL("idventa",
      					 pSisRegProLPtrDato,
					 pSisRegProLPtrPedidos))
      {
        SiscomNodoRegistroPro(pSisRegProLPtrPedidos->SiscomCamProLPtrDato,
			      &lSisRegProLPtrPedidoPrim,
			      &lSisRegProLPtrPedidoAct);
	SiscomRegistrosAlCampo("Apartado",
				lSisRegProLPtrPedidoPrim,
				lSisRegProLPtrPedidoAct,
				pSisRegProLPtrDato);

	  LogSiscom("");
      }
    }

}

void CompletandoApartado(SiscomRegistroProL *pSiscomRegProLPtrDato,
		       SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrPedidos;
lSisRegProLPtrPedidos=SiscomObtenArgumentoPrimOperaciones("SqlApartados",pSiscomOpePtrDato);
for( ;pSiscomRegProLPtrDato;
      pSiscomRegProLPtrDato=pSiscomRegProLPtrDato->SiscomRegProLPtrSig)
{
    AgregaInformacionApartado(pSiscomRegProLPtrDato,lSisRegProLPtrPedidos);
}
}


int InformacionVenta(SiscomRegistroProL *pSiscomRegProLPtrOrdenes,
		     SiscomOperaciones *pSiscomOpePtrDatos)
{
}
int InformacionPedido(SiscomRegistroProL *pSiscomRegProLPtrOrdenes,
		      SiscomOperaciones *pSiscomOpePtrDatos)
{
CompletandoPedido(pSiscomRegProLPtrOrdenes,pSiscomOpePtrDatos);
}

int InformacionCotizacion(SiscomRegistroProL *pSiscomRegProLPtrOrdenes,
		      SiscomOperaciones *pSiscomOpePtrDatos)
{
  CompletandoCotizacion(pSiscomRegProLPtrOrdenes,pSiscomOpePtrDatos);
}

int InformacionCancelacion(SiscomRegistroProL *pSiscomRegProLPtrOrdenes,
		     SiscomOperaciones *pSiscomOpePtrDatos)
{
  LogSiscom("");
}

int InformacionApartado(SiscomRegistroProL *pSiscomRegProLPtrOrdenes,
			SiscomOperaciones *pSiscomOpePtrDatos)
{
 LogSiscom("0-----0");
   CompletandoApartado(pSiscomRegProLPtrOrdenes,pSiscomOpePtrDatos);
}

int InformacionPagoTransferencia(SiscomRegistroProL *pSiscomRegProLOrdenes,
				 SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrArrEdoTransferencia[256];
const char *lchrPtrObs=SiscomObtenCampoRegistroProLChar("observaciones",pSiscomRegProLOrdenes);
  LogSiscom("Viendo lo del pago con transferencia %s",
  SiscomObtenCampoRegistroProLChar("idventa",pSiscomRegProLOrdenes));
if(!lchrPtrObs) 
{
  if(SiscomObtenCampoRegistroProLInt("sereflejo",pSiscomRegProLOrdenes))
	strcpy(lchrArrEdoTransferencia,"Ya se reflejo la transferencia");	
  else
  {
	sprintf(lchrArrEdoTransferencia,
		"No se ha reflejado la transferencia\n\nNumero de contacto: %s",
		SiscomObtenCampoRegistroProLChar("telefonotra",pSiscomRegProLOrdenes));
  }
 
}
SiscomActualizaCampoAsignaMemoria2("observaciones",lchrArrEdoTransferencia,pSiscomRegProLOrdenes);
}
void CompletandoInformacionPorTipoOrden(SiscomRegistroProL *pSiscomRegProLPtrDatos,
					SiscomOperaciones *pSiscomOpePtrDato)
{
int lintIdTipoOrden;

for( ;pSiscomRegProLPtrDatos;pSiscomRegProLPtrDatos=pSiscomRegProLPtrDatos->SiscomRegProLPtrSig)
{
      lintIdTipoOrden=SiscomObtenCampoRegistroProLInt("edoventa",pSiscomRegProLPtrDatos);
      LogSiscom("El Tipo de orden %d ",lintIdTipoOrden); 
      if(gInformacionPorTipoOrden[lintIdTipoOrden])
      gInformacionPorTipoOrden[lintIdTipoOrden](pSiscomRegProLPtrDatos,pSiscomOpePtrDato);
}
}

void AgregaCamposTipoOrden(SiscomRegistroProL *pSiscomRegProLPtrDato)
{
SiscomAgregaCampoRegistros("Cotizacion",(const char *)0,pSiscomRegProLPtrDato);
SiscomAgregaCampoRegistros("Pedido",(const char *)0,pSiscomRegProLPtrDato);
SiscomAgregaCampoRegistros("Apartado",(const char *)0,pSiscomRegProLPtrDato);
}
SiscomRegistroProL *AgrupaOrdenesVendidas2(SiscomOperaciones *pSiscomOpePtrDato)
{
char *lchrPtrCamposRegistroAgrupado[]={"idventa",
				       "cliente",
				       "idpersona",
				       "idtipoorden",
				       "vendedor",
				       "fechahora",
				       "importeorden",
				       "edoventa",
				       "idescuela",
				       "escuela",
				       "nombre",
				       "apaterno",
				       "amaterno",
				       "rfc",
				       "idpersona",
				       "telefono",
				       "departamenteo",
				       "telefonotra",
				       "sereflejo",
				       "observaciones",
				       0};
char *lchrPtrCamposRegistros[]={"cveproducto",
				"dscproducto",
				"idtipoproducto",
				"idconsecutivo",
				"existencia",
				"exbodegas",
				"sat",
				"cantidad",
				"importe",
				"precio",
				0};
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrOrdenAgruPrim=0,
		   *lSiscomRegProLPtrOrdenAgruAct=0;


SiscomAgrupaPorCampo("idventa",
		     "Productos",
		     lchrPtrCamposRegistroAgrupado,
		     lchrPtrCamposRegistros,
		     SiscomObtenRegistrosCampoRespuesta("Ordenes",pSiscomOpePtrDato),
		     &lSiscomRegProLPtrOrdenAgruPrim,
		     &lSiscomRegProLPtrOrdenAgruAct);
AgregaCamposTipoOrden(lSiscomRegProLPtrOrdenAgruPrim);
CompletandoInformacionPorTipoOrden(lSiscomRegProLPtrOrdenAgruPrim,pSiscomOpePtrDato); 
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrOrdenAgruPrim);
return lSiscomRegProLPtrOrdenAgruPrim;
}


SiscomRegistroProL *AgrupaOrdenesVendidas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
char *lchrPtrCamposRegistroAgrupado[]={"idventa","fechahora","totalorden","idfactura",0};
char *lchrPtrCamposRegistros[]={"cveproducto",
				"dscproducto",
				"sat",
				"unidad",
				"cantidad",
				"importe",
				"precio",
				0};
SiscomRegistroProL *lSiscomRegProLPtrOrdenAgruPrim=0,
		   *lSiscomRegProLPtrOrdenAgruAct=0;
SiscomAgrupaPorCampo("idventa",
		     "Productos",
		     lchrPtrCamposRegistroAgrupado,
		     lchrPtrCamposRegistros,
		     SiscomObtenRegistrosCampoRespuesta("Ordenes",pSiscomOpePtrDato),
		     &lSiscomRegProLPtrOrdenAgruPrim,
		     &lSiscomRegProLPtrOrdenAgruAct);
return lSiscomRegProLPtrOrdenAgruPrim;
}

int EnviandoOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
LogSiscom("Enviando la orden vendida");
SiscomRegistroRegresoLog(lchrArrBuffer,pSiscomOpePtrDato);
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
return 0;
}
int SiVieneIdTipoOrden(SiscomOperaciones *pSiscomOpePtrDato,int *pintPtrIdTipoOrden)
{
const char *lchrPtrIdTipoOrden;

if((lchrPtrIdTipoOrden=SiscomCampoAsociadoEntradaOperacion("Envio",
							   "IdTipoOrden",
							   pSiscomOpePtrDato)))
{
  *pintPtrIdTipoOrden=atoi(lchrPtrIdTipoOrden);
  return 1;

}
else 
return 0;

}
int ConsultandoDatosPorTipoOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
int lintIdTipoOrden,
    lintSiVieneIdTipoOrden;
lintSiVieneIdTipoOrden=SiVieneIdTipoOrden(pSiscomOpePtrDato,&lintIdTipoOrden);
/* 
 *  Integrando la modificacion para filtrar lar ordenes 
 *
CondicionConsultaPorRangoFechas(pSiscomOpePtrDato,
				lintSiVieneIdTipoOrden,
				lintIdTipoOrden);
LogSiscom("%d  %d--- ",lintSiVieneIdTipoOrden,lintIdTipoOrden);
*/
if(lintSiVieneIdTipoOrden)
{
  if(lintIdTipoOrden==1)
  SqlCompletaCotizaciones(pSiscomOpePtrDato);
  if(lintIdTipoOrden==4)
  SqlCompletaPedidos(pSiscomOpePtrDato);
  if(lintIdTipoOrden==0)
  SqlCompletaVentas(pSiscomOpePtrDato);
  if(lintIdTipoOrden==2)
  SqlCompletaApartados(pSiscomOpePtrDato);
}
else
{
  SqlCompletaCotizaciones(pSiscomOpePtrDato);
  SqlCompletaPedidos(pSiscomOpePtrDato);
  SqlCompletaVentas(pSiscomOpePtrDato);
  SqlCompletaApartados(pSiscomOpePtrDato);
}
return 0;
}
int ConsultandoDatosPorDescripcion(SiscomOperaciones *pSiscomOpePtrDato)
{
int lintIdTipoOrden;
lintIdTipoOrden=SiscomCampoAsociadoEntradaOperacionInt("Envio",
							   "IdTipoOrden",
							   pSiscomOpePtrDato);
  if(lintIdTipoOrden==1)
  SqlCompletaCotizaciones(pSiscomOpePtrDato);

}

int ArgumentoCotizaciones(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlCotizaciones",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}


int ArgumentoPedidos(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlPedidos",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
int ArgumentoApartados(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlApartados",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}

int ArgumentoVentas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlVentas",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}

int SeEncontroLaOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
  return SiscomRegistrosAsociadoRespuestaOperacion("Productos",pSiscomOpePtrDato) ? 0 :1;
}
void CondicionComplementaCotizacionPorDescripcion(SiscomOperaciones *pSiscomOpePtrDato,
						  char *pchrPtrCondicion)
{
sprintf(pchrPtrCondicion,
	"where idventa in (select distinct idventa              \n\
                           from ventas                          \n\
                           where edoventa=1 and                 \n\
                                fechahora::date>='%s' and       \n\
                                fechahora::date<='%s')",
SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
}
int NOSeEncontroOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
ArgumentoCotizaciones(pSiscomOpePtrDato);
ArgumentoPedidos(pSiscomOpePtrDato);
ArgumentoVentas(pSiscomOpePtrDato);
ArgumentoCondicionVentas(pSiscomOpePtrDato);
CondicionConsultaPorDescripcion(pSiscomOpePtrDato);
ConsultandoDatosPorDescripcion(pSiscomOpePtrDato);
SqlOrdenesVendidas2(pSiscomOpePtrDato);
EnviandoOrdenesVendidas2(pSiscomOpePtrDato);
return 0;
}

int  ArgumentoCondicionVentas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrPrimArgVen=0,
		   *lSisRegProLPtrActArgVen=0;

SiscomAnexaRegistroPro(&lSisRegProLPtrPrimArgVen,
		       &lSisRegProLPtrActArgVen,
		       lchrArrBuffer,
		       "CondicionConsulta,CondCompCotizacion,",
		       (char *)0,
		       (char *)0);
SiscomAgregaArgumentoOperacion("Condicion",
				lSisRegProLPtrPrimArgVen,
				lSisRegProLPtrActArgVen,
				pSiscomOpePtrDato);

return 0;
}
void PorFechaYTipoOrden(SiscomOperaciones *pSiscomOpePtrDato,
			const char *pchrPtrIdTipoOrden,
		        char *pchrPtrCondicion)
{


if(strcmp(pchrPtrIdTipoOrden,"11"))
sprintf(pchrPtrCondicion,
	"where fechahora::date>='%s' and 	\n\
	       fechahora::date<='%s'  and 	\n\
	       a.edoventa=%s",
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato),
	pchrPtrIdTipoOrden);
else
sprintf(pchrPtrCondicion,
	"where fechahora::date>='%s' and 	\n\
	       fechahora::date<='%s'",
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));

}
void PorFechaOrdenes(SiscomOperaciones *pSiscomOpePtrDato,
		     char *pchrPtrCondicion)
{
sprintf(pchrPtrCondicion,
	"where fechahora::date>='%s' and 	\n\
	       fechahora::date<='%s'",
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
}
					
void ActualizaArgumentoCondicion(const char *pchrPtrCondicion,
				 SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomActualizaCampoArgumento2("Condicion",
				"CondicionConsulta",
				(char *)pchrPtrCondicion,
				pSiscomOpePtrDato);
}
void ActualizaArgumentoCondicionComplemento(const char *pchrPtrCondicion,
				 SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomActualizaCampoArgumento2("Condicion",
				"CondCompCotizacion",
				(char *)pchrPtrCondicion,
				pSiscomOpePtrDato);
}

int SiscomAccionAEjecutarPorCondicion(const char *pchrPtrAsociado,
				const char *pchrPtrCampo,
				const char *pchrPtrValor,
				SiscomOperaciones *pSisOpePtrDato,
				SiscomOperacion *pSisPtrOperaciones)
{
/* Tepotzotlan Mexico a 16 de abril del 2023 
 *
 *
 *  Recuperandome de operacion de prostata
 *
 *  Se debe terminar esta funcion que sera de soporte general
 *  se pasa la cadena en el asociado, con la que se compara un 
 *  arreglo de estructuras a funciones con las opciones, si se encuentra 
 *  en la lista , se ejecuta la funcion 
 *
 */


}


int PorRangoFechas(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"where a.idventa in ( select idventa 				\n\
			      from datospedido				\n\
			      where fechaentrega::date>='%s' and 	\n\
			            fechaentrega::date<='%s')",
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),	
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
ActualizaArgumentoCondicion(lchrArrSql,pSiscomOpePtrDato);
return 0;
}
int PorHoraEntrega(SiscomOperaciones *pSiscomOpePtrDato)
{
  char lchrArrSql[256];
  sprintf(lchrArrSql,
  	 "where a.idventa in (							\n\
  				select idventa					\n\
				from datospedido				\n\
				where fechaentrega::date>='%s' and 		\n\
					fechaentrega::date<='%s' and 		\n\
					fechaentrega::time>='%s' and 		\n\
					fechaentrega::time<='%s') ",
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","HoraInicio",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","HoraFin",pSiscomOpePtrDato));
ActualizaArgumentoCondicion(lchrArrSql,pSiscomOpePtrDato);
return 0;	   
}
int ComoConsultoOrdenes(SiscomOperaciones *pSiscomOpePtrDato)
{
StcConsultandoOrdenes *lStcConsOrdenes=gStcConOrdenes;
const char *lchrPtrComoConsulto;
lchrPtrComoConsulto=SiscomCampoAsociadoEntradaOperacion("Envio","ComoConsulto",pSiscomOpePtrDato);
LogSiscom("Consultando  por %s",lchrPtrComoConsulto);
for(; lStcConsOrdenes->chrPtrTipoConsulta;lStcConsOrdenes++)
{
    if(!strcmp(lchrPtrComoConsulto,lStcConsOrdenes->chrPtrTipoConsulta))
     lStcConsOrdenes->Consulta(pSiscomOpePtrDato);
}

}

int ComoHagoLaConsultaOrdenes(SiscomOperaciones *pSiscomOpePtrDato)
{
if(!SiscomEstaElCampoAsociado("Envio","PorCondicionConsultaOrdenes",pSiscomOpePtrDato))
   return CondicionConsultaOrdenes(pSiscomOpePtrDato); 
else
{
  LogSiscom("Consultando por condicion consulta");
  ComoConsultoOrdenes(pSiscomOpePtrDato);
  return 0;
}

}


int CondicionConsultaOrdenes(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrIdTipoOrden;
char lchrArrCondicion[256];
if((lchrPtrIdTipoOrden=SiscomCampoAsociadoEntradaOperacion("Envio",
							   "IdTipoOrden",
							   pSiscomOpePtrDato)))
PorFechaYTipoOrden(pSiscomOpePtrDato,lchrPtrIdTipoOrden,lchrArrCondicion);
else
PorFechaOrdenes(pSiscomOpePtrDato,lchrArrCondicion);
ActualizaArgumentoCondicion(lchrArrCondicion,pSiscomOpePtrDato);
return 0;
}
int CondicionConsultaPorDescripcion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrCondicion[512];
/*
 * CDMX, a 6 de julio del 2023 
 * Creo que ya sali de lo de la prostata, rinones etc, me siento super bien en la carretera
 * ahhhh, solo falta volver hacer EGO , para ver si se regularizaron los parametros 
sprintf(lchrArrCondicion,
	" where idventa in(select idventa 			\n\
                           from cotizacion 			\n\
                           where descripcion like '%%%s%%')",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdOrden",pSiscomOpePtrDato));

*/
sprintf(lchrArrCondicion,
	"where descripcion like '%%%s%%'",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdOrden",pSiscomOpePtrDato));

ActualizaArgumentoCondicion(lchrArrCondicion,pSiscomOpePtrDato);
}
int CondicionConsultaPorRangoFechas(SiscomOperaciones *pSiscomOpePtrDato,
				    int pintSiTipoOrden,
				    int pintIdTipoOrden)
{
char lchrArrCondicion[512];
int lintSeTomaTipoOrden;

/*
 * Tepotzotlan a 9/10/2022 
 * Revisando la condicion , porque se tarda mucho c...
 *
 * Sabado 29-Oct-2022 
 * CDMX , pensandolo bien , esta como historia de terror, como voy 
 * a buscar datos de una orden en la tabla de ventas ..... 
 *
sprintf(lchrArrCondicion,
	" where idventa in(select distinct idventa		\n\
			   from ventas 				\n\
			   where edoventa=%s and 		\n\
			         fechahora::date>='%s' and 	\n\
				 fechahora::date<='%s')",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoOrden",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
*/


if(pintSiTipoOrden)
sprintf(lchrArrCondicion,
	"where a.edoventa=%s 	      and	\n\
		fechahora::date>='%s' and 	\n\
	      fechahora::date<='%s'",
	 SiscomCampoAsociadoEntradaOperacion("Envio","IdTipoOrden",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));
else
sprintf(lchrArrCondicion,
	" where idventa in(select distinct idventa		\n\
			   from ventas 				\n\
			   where fechahora::date>='%s' and 	\n\
				 fechahora::date<='%s')",
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaInicio",pSiscomOpePtrDato),
	 SiscomCampoAsociadoEntradaOperacion("Envio","FechaFin",pSiscomOpePtrDato));

ActualizaArgumentoCondicion(lchrArrCondicion,pSiscomOpePtrDato);
}
