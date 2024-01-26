#include <Cotizando.h>
#include <SqlProductos.h>
#include <SqlVentas.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void CotizaOrden(int pintSocket,
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
SiscomAgregaOperacion(CalculaTotalOrden,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaTotalesOrden,&lSiscomProDat); 
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void CotizaProducto(int pintSocket,
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
SiscomAgregaOperacion(SqlProductoPorCodigoBarras,&lSiscomProDat);
SiscomAgregaOperacion(AgregaCostoUnitario,&lSiscomProDat); 
SiscomAgregaOperacion(EnviaProductoCotizado,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ProductoNoRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
                   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];

SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
                       &lSiscomRegProLPtrAct,
                       lchrArrBuffer,
                       "MensajeSistema,",
                       "Producto No Registrado");

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
                           lchrArrBuffer,
                           lSiscomRegProLPtrPrim);

}
int AgregaCostoUnitario(SiscomOperaciones *pSiscomOpePtrDato)
{
float lfltImporte,
	lfltCantidad;

const char *lchrPtrCantidad;
char lchrArrImporte[28],
      lchrArrBuffer[128];

if(SiscomRegistrosAsociadoRespuestaOperacion("ProductoPorCodigo",pSiscomOpePtrDato))
{
lchrPtrCantidad=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "Cantidad",
						     pSiscomOpePtrDato);
lfltCantidad=atof(lchrPtrCantidad);
lfltImporte=lfltCantidad*SiscomCampoAsociadoRespuestaOperacionFloat("ProductoPorCodigo",
						       "preciogeneral",
						       pSiscomOpePtrDato);
sprintf(lchrArrImporte,"%.2f",lfltImporte);
SiscomAgregaCampoAsociadoRespuesta("Importe",
				   lchrArrImporte,
				   "ProductoPorCodigo",
				   pSiscomOpePtrDato);

SiscomAgregaCampoAsociadoRespuesta("Cantidad",
				   lchrPtrCantidad,
				   "ProductoPorCodigo",
				   pSiscomOpePtrDato);
}
return 0;
}

void AgregaSePuedeVender(SiscomOperaciones *pSiscomOpePtrDato)
{
int lintExistencia,
    lintCantidad;
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrDatos;
lSiscomRegProLPtrDatos=SiscomRegistrosAsociadoRespuestaOperacion("ProductoPorCodigo",pSiscomOpePtrDato);
/*
 * Sabado 25 de Junio del 2016 
 * Se quita la validacion de la existencia 
 * de la mercancia , ya que se puede vender 
 * aun cuando no alcance la existencia , lo que 
 * procede es realizar un pedido de mercancia, para que
 * el cliente regrese otro dia por su producto
 *
lintExistencia=SiscomObtenCampoRegistroProLInt("existencia",lSiscomRegProLPtrDatos);
lintCantidad=SiscomObtenCampoRegistroProLInt("Cantidad",lSiscomRegProLPtrDatos);
if(!lintExistencia)
{
SiscomAgregaCampoRegistro("SePuedeVender","0",lSiscomRegProLPtrDatos);
SiscomAgregaCampoRegistro("Mensaje","Existencia Cero",lSiscomRegProLPtrDatos);
}
else
if(lintCantidad>lintExistencia)
{
SiscomAgregaCampoRegistro("SePuedeVender","0",lSiscomRegProLPtrDatos);
SiscomAgregaCampoRegistro("Mensaje","La Existencia NO Alcanza",lSiscomRegProLPtrDatos);
}
else
*/
SiscomAgregaCampoRegistro("SePuedeVender","1",lSiscomRegProLPtrDatos);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrDatos);
}

int EnviaProductoCotizado(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];

if(SiscomRegistrosAsociadoRespuestaOperacion("ProductoPorCodigo",pSiscomOpePtrDato))
{
AgregaSePuedeVender(pSiscomOpePtrDato);
SiscomEnviaAsociadoRespuestaCliente("ProductoPorCodigo",
				    lchrArrBuffer,
				    pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("ProductoPorCodigo",
			   lchrArrBuffer,
			   pSiscomOpePtrDato);

}
else
{
LogSiscom("El producto no esta en la base de datos");
ProductoNoRegistrado(pSiscomOpePtrDato);
}
return 0;
}
void PreparaRespuestaCredito(float pfltDescuentoQuincenal,
			     float pfltPagoMasInteres,
			     SiscomOperaciones *pSiscomOpePtrDato,
			     SiscomRegistroProL **pSiscomRegProLPtrPrim,
			     SiscomRegistroProL **pSiscomRegProLPtrAct)
{
char lchrArrBuffer[256],
	lchrArrDesQuincenal[28],
	lchrArrPagoMasInteres[28];

sprintf(lchrArrDesQuincenal,"%.2f",pfltDescuentoQuincenal);
sprintf(lchrArrPagoMasInteres,"%.2f",pfltPagoMasInteres);
LogSiscom("%s",SiscomCampoAsociadoRespuestaOperacion("DatosCalculoCredito","nombre",pSiscomOpePtrDato));
SiscomAnexaRegistroPro(
	pSiscomRegProLPtrPrim,
	pSiscomRegProLPtrAct,
	lchrArrBuffer,
	"Plazo,DesQuincenal,PagoTotal,",
	SiscomCampoAsociadoRespuestaOperacion("DatosCalculoCredito","nombre",pSiscomOpePtrDato),
  	lchrArrDesQuincenal,
	lchrArrPagoMasInteres);
}
void DescuentoQuincenal(SiscomOperaciones *pSiscomOpePtrDato)
{
float lfltImporte,
      lfltDescuentoQuincenal,
      lfltTasa,
      lfltMeses,
      lfltPagoMasInteres;
SiscomRegistroProL *lSiscomRegProLPtrPrimCredito=0,
		   *lSiscomRegProLPtrActCredito=0;

lfltImporte=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Total",pSiscomOpePtrDato);
lfltTasa=SiscomCampoAsociadoRespuestaOperacionFloat("DatosCalculoCredito","tasa",pSiscomOpePtrDato);
lfltMeses=SiscomCampoAsociadoRespuestaOperacionFloat("DatosCalculoCredito","meses",pSiscomOpePtrDato);

lfltDescuentoQuincenal=lfltImporte*(1+lfltTasa)/(lfltMeses*2);
lfltPagoMasInteres=lfltImporte*(1+lfltTasa);
LogSiscom("Importe(%f) Tasa(%f) Meses(%f) Pago Quincenal(%f) PagoTotal(%f)",
	lfltImporte,
	lfltTasa,
	lfltMeses,
	lfltDescuentoQuincenal,
	lfltPagoMasInteres);
PreparaRespuestaCredito(lfltDescuentoQuincenal,
			lfltPagoMasInteres,
			pSiscomOpePtrDato,
			&lSiscomRegProLPtrPrimCredito,
			&lSiscomRegProLPtrActCredito);
SiscomAgregaArgumentoOperacion("RespuestaCredito",
			       lSiscomRegProLPtrPrimCredito,
			       lSiscomRegProLPtrActCredito,
			       pSiscomOpePtrDato);
LogSiscom("");
}
void CalculandoCredito(SiscomOperaciones *pSiscomOpePtrDato)
{
DescuentoQuincenal(pSiscomOpePtrDato);
}
int CalculandoCompraACredito(SiscomOperaciones *pSiscomOpePtrDato)
{
int lintIdTipoVenta=SiscomCampoAsociadoEntradaOperacionInt("Envio","IdTipoVenta",pSiscomOpePtrDato);
   if(lintIdTipoVenta==2)
   {
    SqlDatosCalculoCredito(pSiscomOpePtrDato);
    CalculandoCredito(pSiscomOpePtrDato);
    return 1;
   }
   else
   return 0;

}
int CalculaTotalOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
float lfltTotalOrden,
     lfltCantidad,
     lfltImporte,
     lfltPrecio;
SiscomRegistroProL *lSiscomRegProLPtrOrden,
		   *lSiscomRegProLPtrOrdenPaso;;
lSiscomRegProLPtrOrden=lSiscomRegProLPtrOrdenPaso=SiscomRegistrosAsociadosCampoEntrada("Envio","Productos",pSiscomOpePtrDato);
for(;
     lSiscomRegProLPtrOrden;
     lSiscomRegProLPtrOrden=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrOrden))
{
lfltPrecio=SiscomObtenCampoRegistroProLFloat("preciogeneral",lSiscomRegProLPtrOrden);
lfltCantidad=SiscomObtenCampoRegistroProLFloat("Cantidad",lSiscomRegProLPtrOrden);
lfltImporte=lfltCantidad*lfltPrecio;
SiscomActualizaCampoFloatRegistroActual("Importe","%.2f",lfltImporte,lSiscomRegProLPtrOrden);
}
lfltTotalOrden=SiscomObtenSumatoriaRegistros("Importe",lSiscomRegProLPtrOrdenPaso);
SiscomActualizaCampoAsociadoEntradaFloat("Envio","Total",lfltTotalOrden,pSiscomOpePtrDato);
return 0;
}

int EnviaTotalesOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0,
		   *lSiscomRegProLPtrPrimProductos;

char lchrArrBuffer[512];
SiscomAnexaRegistroPro(
	&lSiscomRegProLPtrPrim,
	&lSiscomRegProLPtrAct,
	lchrArrBuffer,
	"Total,Iva,SubTotal,Productos,Credito,",
	SiscomCampoAsociadoEntradaOperacion("Envio","Total",pSiscomOpePtrDato),
	"0",
	"0",
	 (const char *)0, 
	 (const char *)0);
lSiscomRegProLPtrPrimProductos=SiscomRegistrosAsociadosCampoEntrada("Envio","Productos",pSiscomOpePtrDato);
SiscomRegistrosAlCampo("Productos",
		 	lSiscomRegProLPtrPrimProductos,
			lSiscomRegProLPtrPrimProductos,
			lSiscomRegProLPtrPrim);
if(CalculandoCompraACredito(pSiscomOpePtrDato))
 SiscomRegistrosAlCampo("Credito",
 			SiscomObtenArgumentoPrimOperaciones("RespuestaCredito",pSiscomOpePtrDato),
			SiscomObtenArgumentoActOperaciones("RespuestaCredito",pSiscomOpePtrDato),
			lSiscomRegProLPtrPrim);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
return 0;
}
