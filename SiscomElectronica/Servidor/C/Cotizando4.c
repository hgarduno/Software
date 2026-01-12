#include <Cotizando4.h>
#include <SqlCotizando4.h>
#include <SqlProductosSE.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomConfiguracionServidor.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdlib.h>

void CalculaCambioPago(int pintSocket,
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
SiscomAgregaOperacion(CalculandoCambioPago,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ObtenIdOrden(int pintSocket,
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
SiscomAgregaOperacion(ObteniendoIdOrden,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void CotizandoProductos4(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSisOpeErrores={0,
					 NoJuegosInvalido,
					 DescuentoInvalido,
					 ProductoSinPrecioExistencia,
					 0};
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoDefinicionProducto,&lSiscomProDat); 
SiscomAgregaOperacion(ValidandoDatosCotizacion,&lSiscomProDat); 
SiscomAgregaOperacion(AsignaFechaHoraCotizacion,&lSiscomProDat); 
SiscomAgregaOperacion(SqlProductosCotizando,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoCotizacion,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSisOpeErrores,lSiscomProDat); 
}

int ObteniendoIdOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024],
	lchrArrIdOrden[24];
SiscomRegistroProL *lSiscomRegProLPtrRegPrim=0,
		   *lSiscomRegProLPtrRegAct=0;
SiscomObtenNumeroUnicoChar(lchrArrIdOrden);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrRegPrim,
		       &lSiscomRegProLPtrRegAct,
		       lchrArrBuffer,
		       "IdOrden,",
		       lchrArrIdOrden);
LogSiscom("Se Inicia la Orden ****** %s   **** ",lchrArrIdOrden);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrRegPrim);
}
int ValidandoNoJuegos(SiscomOperaciones *pSiscomOpePtrDato)
{
int lintNoJuegos;

lintNoJuegos=SiscomCampoAsociadoEntradaOperacionInt("Envio",
						    "JuegosNuevo",
						    pSiscomOpePtrDato);
if(lintNoJuegos>0)
return 0;
else
if(lintNoJuegos<=0)
return 1;
}
int ValidandoDatosCotizacion(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrJuegosNuevo;
char lchrArrBuffer[512];
LogSiscom("");
 if(ValidandoNoJuegos(pSiscomOpePtrDato))
 {
 	return 1;
 }
 else
 {
 	lchrPtrJuegosNuevo=SiscomCampoAsociadoEntradaOperacion("Envio",
								"JuegosNuevo",
								pSiscomOpePtrDato);
	SiscomActualizaCampoAsociadoEntrada("Envio",
					    "Juegos",
					    (char *)lchrPtrJuegosNuevo,
					    pSiscomOpePtrDato);
	return 0;
 }
}

int EnviandoCotizacion(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
if(ArmaRespuestaCotizacion(pSiscomOpePtrDato))
return 3;
else
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   pSiscomOpePtrDato->SiscomRegProLPtrPrimEnt);
LOGOrden(pSiscomOpePtrDato);
return 0;
}
void AsignaMemoriaInicioCondicion(SiscomRegistroProL *pSiscomRegProLPtrProducto,
				  const char *pchrPtrPaso,
				  char **pchrPtrCondicion)
{
const char *lchrPtrClave;
lchrPtrClave=SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrProducto);
   *pchrPtrCondicion=(char *)malloc(strlen(pchrPtrPaso)+
   				    strlen(lchrPtrClave)+5);
   sprintf(*pchrPtrCondicion,
   	  "%s'%s'",
	  pchrPtrPaso,
	  lchrPtrClave);
}
void AgregaCadenaCondicion(SiscomRegistroProL *pSiscomRegProLPtrProducto,
			   char **pchrPtrCondicion)
{
char lchrArrPaso[1024];
const char *lchrPtrClave;
int lintTamano;
	lchrPtrClave=SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrProducto);
         lintTamano=strlen(*pchrPtrCondicion)+strlen(lchrPtrClave)+5; 
	 *pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,lintTamano);
	  sprintf(lchrArrPaso,",'%s'",lchrPtrClave);
	  strcat(*pchrPtrCondicion,lchrArrPaso);
}

void ArmaCondicionConsultaProductos(SiscomOperaciones *pSiscomOpePtrDato,
				    SiscomRegistroProL *pSiscomRegProLPtrProductos,
			    	    char **pchrPtrCondicion)
{
char lchrArrBuffer[1024];
char lchrArrPaso[1024];
int lintContador=0;
strcpy(lchrArrPaso,"where CveProducto in(");
while(pSiscomRegProLPtrProductos)
{
   if(!lintContador)
   AsignaMemoriaInicioCondicion(pSiscomRegProLPtrProductos,lchrArrPaso,pchrPtrCondicion);
   else
   AgregaCadenaCondicion(pSiscomRegProLPtrProductos,pchrPtrCondicion);

  pSiscomRegProLPtrProductos=pSiscomRegProLPtrProductos->SiscomRegProLPtrSig;
  lintContador++;
}
*pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,strlen(*pchrPtrCondicion)+
						   strlen(lchrArrPaso)+128);
sprintf(lchrArrPaso,
	") and idexpendio=%s and idpersona in(%s) ",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdExpendio",pSiscomOpePtrDato),
	SiElClienteEsNuloUsaPublicoGeneral(pSiscomOpePtrDato));
strcat(*pchrPtrCondicion,lchrArrPaso);
}
void ProductoSinDatosVenta(SiscomRegistroProL *pSiscomRegProLPtrProdEntrada)
{
SiscomActualizaCampoAsignaMemoriaRegistro("SePuedeVender","0",pSiscomRegProLPtrProdEntrada);
}
int ArmaRespuestaCotizacion(SiscomOperaciones *pSiscomOpePtrDato)
{
float lfltImporteOrden=0;
char lchrArrImporte[28];
SiscomRegistroProL *lSiscomRegProLPtrProdBase,
		   *lSiscomRegProLPtrProEntrada,
		   *lSiscomRegProLPtrProdEntradaRes;
int lintNumKitsPracticasEtc=0,
    lintNumProductos=0;

char lchrArrBuffer[1024];
lSiscomRegProLPtrProdEntradaRes=lSiscomRegProLPtrProEntrada=SiscomRegistrosAsociadosCampoEntrada("Envio",
								 "Productos",
								 pSiscomOpePtrDato);
lSiscomRegProLPtrProdBase=SiscomObtenRegistrosCampoRespuesta("Productos",pSiscomOpePtrDato);
if(lSiscomRegProLPtrProdBase)
{
while(lSiscomRegProLPtrProEntrada)
{
   DefinicionTipoProducto(pSiscomOpePtrDato,
   			  lSiscomRegProLPtrProEntrada,
			  &lintNumKitsPracticasEtc,
			  &lintNumProductos);
   lfltImporteOrden+=CotizandoProductoSiscom4(pSiscomOpePtrDato,
   					      lSiscomRegProLPtrProdBase,
					      lSiscomRegProLPtrProEntrada);
   lSiscomRegProLPtrProEntrada=lSiscomRegProLPtrProEntrada->SiscomRegProLPtrSig;
}
}
else
{
ProductoSinDatosVenta(lSiscomRegProLPtrProEntrada);
return 3;
}
/*
AjustaImporteTotal4(lfltImporteOrden,lchrArrImporte);
*/
sprintf(lchrArrImporte,"%.3f",lfltImporteOrden);
SiscomActualizaCampoAsociadoEntrada("Envio","Importe",lchrArrImporte,pSiscomOpePtrDato); 
SiscomActualizaCampoAsociadoEntradaFloat("Envio","NumKitsPracticasEtc",(float )lintNumKitsPracticasEtc,pSiscomOpePtrDato);
SiscomActualizaCampoAsociadoEntradaFloat("Envio","NumProductos",(float )lintNumProductos,pSiscomOpePtrDato);
return 0;
}
int NoEsProducto(SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
const char *lchrPtrTipoProducto;
lchrPtrTipoProducto=SiscomObtenCampoRegistroProLChar("TipoProducto",pSiscomRegProLPtrProducto);
if(lchrPtrTipoProducto &&
   (!strcmp(lchrPtrTipoProducto,"1") ||
   !strcmp(lchrPtrTipoProducto,"2")  ||
   !strcmp(lchrPtrTipoProducto,"3")  ||
   !strcmp(lchrPtrTipoProducto,"4")))
return 0;
else
return 1;

}
void ActualizaCantidadDefinicion(SiscomRegistroProL *pSiscomRegProLPtrDefinicion,
				 SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
float lfltCantidad=SiscomObtenCampoRegistroProLFloat("Cantidad",pSiscomRegProLPtrProducto);
float lfltCantidadTotal;
  for(;
      pSiscomRegProLPtrDefinicion;
      pSiscomRegProLPtrDefinicion=pSiscomRegProLPtrDefinicion->SiscomRegProLPtrSig)
  {
       lfltCantidadTotal=lfltCantidad*SiscomObtenCampoRegistroProLFloat("cantidad",pSiscomRegProLPtrDefinicion);
	SiscomActualizaCampoFloatRegistroActual("cantidad",
					  "%.2f",
					  lfltCantidadTotal,
					  pSiscomRegProLPtrDefinicion);
  }
}
void CotizandoDefinicionProducto(SiscomRegistroProL *pSiscomRegProLPtrProducto,
				 SiscomRegistroProL *pSiscomRegProLPtrDefProducto)
{
char lchrArrBuffer[1024];
float lfltPrecioPractica=0.0,
	lfltImporte;
 for(;
     pSiscomRegProLPtrDefProducto;
     pSiscomRegProLPtrDefProducto=pSiscomRegProLPtrDefProducto->SiscomRegProLPtrSig)
{
 if(!SiscomComparaCadenaCampoRegistroProL("1","sicotiza",pSiscomRegProLPtrDefProducto))
    lfltPrecioPractica+=SiscomObtenCampoRegistroProLFloat("importe",pSiscomRegProLPtrDefProducto);
}
lfltImporte=lfltPrecioPractica*
	    SiscomObtenCampoRegistroProLFloat("Cantidad",pSiscomRegProLPtrProducto);
LogSiscom("El Importe de la practica es %f",lfltPrecioPractica);
SiscomActualizaCampoFloatRegistroActual("Precio","%.3f",lfltPrecioPractica,pSiscomRegProLPtrProducto);
SiscomActualizaCampoFloatRegistroActual("Importe","%.3f",lfltImporte,pSiscomRegProLPtrProducto);
SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomRegProLPtrProducto);
}
void CotizaDefinicionProducto(SiscomOperaciones *pSiscomOpePtrDato,
			      SiscomRegistroProL *pSiscomRegProLPtrProducto,
			      SiscomRegistroProL *pSiscomRegProLPtrDefProducto)
{
char lchrArrBuffer[1024];
if(EsProductoKit(pSiscomRegProLPtrProducto) ||
   EsProductoSiscom(pSiscomRegProLPtrProducto))
return;
else
{
LogSiscom("Se Cotiza una practica o promocion");
SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomRegProLPtrDefProducto);
CotizandoDefinicionProducto(pSiscomRegProLPtrProducto,
			    pSiscomRegProLPtrDefProducto);
}
}
void DefinicionTipoProducto(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrProducto,
			    int *pintPtrNumKitPracticaEtc,
			    int *pintPtrNumProductos)
{
char lchrArrBuffer[1024];
SiscomRegistroProL *lSiscomRegProLPtrDefinicionProd;
if(!NoEsProducto(pSiscomRegProLPtrProducto))
{
SqlDefinicionProducto(pSiscomRegProLPtrProducto,pSiscomOpePtrDato);
lSiscomRegProLPtrDefinicionProd=SiscomObtenArgumentoPrimOperaciones("SqlDefinicionProducto",
								     pSiscomOpePtrDato);
CotizaDefinicionProducto(pSiscomOpePtrDato,
			 pSiscomRegProLPtrProducto,
			 lSiscomRegProLPtrDefinicionProd);
ActualizaCantidadDefinicion(lSiscomRegProLPtrDefinicionProd,
			    pSiscomRegProLPtrProducto);
SiscomRegistrosAlCampo("Productos",
			lSiscomRegProLPtrDefinicionProd,
			0,
			pSiscomRegProLPtrProducto);
(*pintPtrNumKitPracticaEtc)++;
}
else
(*pintPtrNumProductos)++;
}

int SeTomaPrecioBaseDatos(float pfltDescuentoOrden,
			  SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
/*
LogSiscom("Prodcto %s Precio (%s) Descuento Orden (%f) Precio Especial(%s)",
	  SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrProducto),
	  SiscomObtenCampoRegistroProLChar("Precio",pSiscomRegProLPtrProducto),
	  pfltDescuentoOrden,
	  SiscomObtenCampoRegistroProLChar("PrecioEspecial",pSiscomRegProLPtrProducto));
*/
if((int )pfltDescuentoOrden )
return 0;
else
if(SiscomObtenCampoRegistroProLInt("PrecioEspecial",pSiscomRegProLPtrProducto))
return 1;
else
return 0;
}


float PrecioProductoOPracticaEtc(float pfltDescuentoOrden,
				 SiscomRegistroProL *pSiscomRegProLPtrProducto,
				 SiscomRegistroProL *pSiscomRegProLPtrProdBase)
{
float lfltPorDescuento;
if(EsProductoPractica(pSiscomRegProLPtrProducto))
return SiscomObtenCampoRegistroProLFloat("Precio",pSiscomRegProLPtrProducto);
else
{
 if(SeTomaPrecioBaseDatos(pfltDescuentoOrden,pSiscomRegProLPtrProducto))
 return SiscomObtenCampoRegistroProLFloat("Precio",pSiscomRegProLPtrProducto);
 else
 {
  if((int )pfltDescuentoOrden)
  {
 	lfltPorDescuento=(100.00-pfltDescuentoOrden)/100.0;
	return SiscomObtenCampoRegistroProLFloat("precio",pSiscomRegProLPtrProdBase)*
		lfltPorDescuento;
  }
  else
 return SiscomObtenCampoRegistroProLFloat("precio",pSiscomRegProLPtrProdBase);
 }
}
}
float ImporteProductoOPracticaEtc(float pfltPrecio,
				  SiscomRegistroProL *pSiscomRegProLPtrProducto,
				  SiscomRegistroProL *pSiscomRegProLPtrProdBase,
				  float pfltJuegos)
{
float lfltImporte;
if(EsProductoPractica(pSiscomRegProLPtrProducto))
   lfltImporte=SiscomObtenCampoRegistroProLFloat("Importe",pSiscomRegProLPtrProducto);
else
lfltImporte=SiscomObtenCampoRegistroProLFloat("Cantidad",pSiscomRegProLPtrProducto)	*
	    pfltPrecio						   	   		*
	    pfltJuegos;
return lfltImporte;
}

float ActualizandoDatosProducto(SiscomOperaciones *pSiscomOpePtrDato,
			       SiscomRegistroProL *pSiscomRegProLPtrProdBase,
			       SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
char lchrArrPrecio[12],
     lchrArrImporte[12];
const char *lchrPtrProducto,
	   *lchrPtrExistencia,
	   *lchrPtrExisBodega,
	   *lchrPtrPrecio;
float lfltImporte,
	lfltJuegos,
	lfltDescuentoOrden,
	lfltPrecio;

lchrPtrExistencia=SiscomObtenCampoRegistroProLChar("existencia",pSiscomRegProLPtrProdBase);
lchrPtrExisBodega=SiscomObtenCampoRegistroProLChar("exbodegas",pSiscomRegProLPtrProdBase);
lfltDescuentoOrden=SiscomCampoAsociadoEntradaOperacionFloat("Envio","DescuentoOrden",pSiscomOpePtrDato);
lfltPrecio=PrecioProductoOPracticaEtc(lfltDescuentoOrden,
					 pSiscomRegProLPtrProducto,
					 pSiscomRegProLPtrProdBase);
lfltJuegos=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Juegos",pSiscomOpePtrDato);
SiscomActualizaCampo2("Existencia",(char *)lchrPtrExistencia,pSiscomRegProLPtrProducto);
SiscomActualizaCampo2("ExiBodega",(char *)lchrPtrExisBodega,pSiscomRegProLPtrProducto);
lfltImporte=ImporteProductoOPracticaEtc(lfltPrecio,
  					pSiscomRegProLPtrProducto,
  					pSiscomRegProLPtrProdBase,
					lfltJuegos);
 SiscomActualizaCampoFloatRegistroActual("Precio","%.3f",lfltPrecio,pSiscomRegProLPtrProducto);
 SiscomActualizaCampoFloatRegistroActual("Importe","%.3f",lfltImporte,pSiscomRegProLPtrProducto);
  return lfltImporte;
}
float CotizandoProductoSiscom4(SiscomOperaciones *pSiscomOpePtrDato,
				SiscomRegistroProL *pSiscomRegProLPtrProdBase,
		       	       SiscomRegistroProL *pSiscomRegProLPtrProductos)
{
float lfltImporte;
const char *lchrPtrProducto;
lchrPtrProducto=SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrProductos);
 for(;
      pSiscomRegProLPtrProdBase;
      pSiscomRegProLPtrProdBase=pSiscomRegProLPtrProdBase->SiscomRegProLPtrSig)
 if(!SiscomComparaCadenaCampoRegistroProL(lchrPtrProducto,"cveproducto",pSiscomRegProLPtrProdBase))
 {
   lfltImporte=ActualizandoDatosProducto(pSiscomOpePtrDato,
   					pSiscomRegProLPtrProdBase,
					pSiscomRegProLPtrProductos);
    SePuedeVender(pSiscomOpePtrDato,pSiscomRegProLPtrProdBase,pSiscomRegProLPtrProductos);
    return lfltImporte;
 }
}

int ArgumentoDefinicionProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaArgumentoOperacion("SqlDefinicionProducto",
				(SiscomRegistroProL *)0,
				(SiscomRegistroProL *)0,
				pSiscomOpePtrDato);
return 0;
}
int SePuedeVenderPorTipoOrden(SiscomOperaciones *pSiscomOpePtrDato)
{
int lintIdTipoOrden;
lintIdTipoOrden=SiscomCampoAsociadoEntradaOperacionInt("Envio","IdTipoOrden",pSiscomOpePtrDato);
if(lintIdTipoOrden==1 ||
   lintIdTipoOrden==2)
return 1;
else
return 0;
}
int SePuedeVenderProducto4(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrProdBase,
			   SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
char lchrArrBuffer[1024];
float lfltExistencia,
	lfltCantidad,
	lfltPrecio,
	lfltJuegos=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Juegos",pSiscomOpePtrDato);

lfltExistencia=SiscomObtenCampoRegistroProLFloat("existencia",pSiscomRegProLPtrProdBase);
lfltCantidad=SiscomObtenCampoRegistroProLFloat("Cantidad",pSiscomRegProLPtrProducto)*lfltJuegos;
lfltPrecio=SiscomObtenCampoRegistroProLFloat("Precio",pSiscomRegProLPtrProducto);
if(lfltPrecio)
{
if(lfltCantidad && lfltExistencia>=lfltCantidad)
{
SiscomActualizaCampo2("SePuedeVender","1",pSiscomRegProLPtrProducto);
return 1;
}
else
{
  if(SePuedeVenderPorTipoOrden(pSiscomOpePtrDato))
  {
  SiscomActualizaCampo2("SePuedeVender","1",pSiscomRegProLPtrProducto);
  return 1;
  }
  else
  {
  SiscomActualizaCampo2("SePuedeVender","0",pSiscomRegProLPtrProducto);
  return 0;
  }
}
}
SiscomActualizaCampo2("SePuedeVender","0",pSiscomRegProLPtrProducto);
return 0;
}
int EsProductoKit(SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
return !SiscomComparaCadenaCampoRegistroProL("2","TipoProducto",pSiscomRegProLPtrProducto);
}
int EsProductoSiscom(SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
return !SiscomComparaCadenaCampoRegistroProL("3","TipoProducto",pSiscomRegProLPtrProducto);
}

int EsProductoPractica(SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
return !SiscomComparaCadenaCampoRegistroProL("1","TipoProducto",pSiscomRegProLPtrProducto);
}

int EsCircuitoImpreso(SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
return !SiscomComparaCadenaCampoRegistroProL("4","TipoProducto",pSiscomRegProLPtrProducto);
}
int EsProductoKitPracticaEtc(SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
/* Queretaro 3 de Febrero 2019 
 * Se Elimino de la lista de validaciones 
 * de la definicion de productos, la llamada a
 * EsProductoSiscom , debido a que la validacion de la
 * existencia del producto se realizara con base al registro
 * de los productos fabricados , y sera solo por clave 
 */
return EsProductoPractica(pSiscomRegProLPtrProducto) 	||
       EsProductoKit(pSiscomRegProLPtrProducto)		||
       EsCircuitoImpreso(pSiscomRegProLPtrProducto);
}
void AgregaCampoClaveProducto(SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
const char *lchrPtrClave;
  while(pSiscomRegProLPtrProducto)
  {
     lchrPtrClave=SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrProducto);
     SiscomAgregaCampoRegistro("Clave",lchrPtrClave,pSiscomRegProLPtrProducto);
     pSiscomRegProLPtrProducto=pSiscomRegProLPtrProducto->SiscomRegProLPtrSig;
  }
}
SiscomRegistroProL *ExistenciaProductosDefinicion(SiscomOperaciones *pSiscomOpePtrDato,
						  SiscomRegistroProL *pSiscomRegProLPtrDefProducto)
{
SiscomRegistroProL *lSiscomRegProLPtrDefBase;
SqlProductosCotizacion(pSiscomOpePtrDato,
		       "Definicion%",
		       pSiscomRegProLPtrDefProducto);
lSiscomRegProLPtrDefBase=SiscomObtenRegistrosCampoRespuesta("Definicion",pSiscomOpePtrDato);

return lSiscomRegProLPtrDefBase;
}
int ValidaExistenciaProductoDefinicion(SiscomRegistroProL *pSiscomRegProLPtrDefBase,
				       SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
float lfltCantidad,
	lfltExistencia;
  for(; 
      pSiscomRegProLPtrDefBase;
      pSiscomRegProLPtrDefBase=pSiscomRegProLPtrDefBase->SiscomRegProLPtrSig)
  {
      if(!SiscomComparaCampoRegistrosProL2("cveproducto",
      					   "Clave",
					   pSiscomRegProLPtrDefBase,
					   pSiscomRegProLPtrProducto))
       {
    	LogSiscom("Validando Existencia de %s",
    		  SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDefBase));
   	    lfltCantidad=SiscomObtenCampoRegistroProLFloat("cantidad",pSiscomRegProLPtrProducto);
	    lfltExistencia=SiscomObtenCampoRegistroProLFloat("existencia",pSiscomRegProLPtrDefBase);
	    return lfltExistencia>=lfltCantidad;
       }
  }
}
int ValidandoExistenciaProductosDefinicion(SiscomRegistroProL *pSiscomRegProLPtrDefBase,
					   SiscomRegistroProL *pSiscomRegProLPtrDefProducto)
{
int lintNoAlcanza=1;
 for(;
     pSiscomRegProLPtrDefProducto;
     pSiscomRegProLPtrDefProducto=pSiscomRegProLPtrDefProducto->SiscomRegProLPtrSig)
  if(ValidaExistenciaProductoDefinicion(pSiscomRegProLPtrDefBase,pSiscomRegProLPtrDefProducto))
  {
  }
  else
  {
   SiscomActualizaCampo2("sepuedevender","0",pSiscomRegProLPtrDefProducto);
    LogSiscom("NO ALCANZA %s %s",
    	      SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDefProducto),
	      SiscomObtenCampoRegistroProLChar("sepuedevender",pSiscomRegProLPtrDefProducto));
    lintNoAlcanza=0; 
  }
 return lintNoAlcanza;
}
void SePuedeVenderKitPracticaEtc(SiscomOperaciones *pSiscomOpePtrDato,
				 SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
char lchrArrBuffer[512];
SiscomRegistroProL *lSiscomRegProLPtrDefProducto,
		   *lSiscomRegProLPtrDefBase;
lSiscomRegProLPtrDefProducto=SiscomObtenRegistrosCampoProL("Productos",pSiscomRegProLPtrProducto);
AgregaCampoClaveProducto(lSiscomRegProLPtrDefProducto);
if((lSiscomRegProLPtrDefBase=ExistenciaProductosDefinicion(pSiscomOpePtrDato,lSiscomRegProLPtrDefProducto)))
if(ValidandoExistenciaProductosDefinicion(lSiscomRegProLPtrDefBase,lSiscomRegProLPtrDefProducto))
    SiscomActualizaCampo2("SePuedeVender","1",pSiscomRegProLPtrProducto);
 else
 {
    if(SePuedeVenderPorTipoOrden(pSiscomOpePtrDato)) 
    SiscomActualizaCampo2("SePuedeVender","1",pSiscomRegProLPtrProducto);
    else
    SiscomActualizaCampo2("SePuedeVender","0",pSiscomRegProLPtrProducto);
 }
}
void SePuedeVender(SiscomOperaciones *pSiscomOpePtrDato,
		   SiscomRegistroProL *pSiscomRegProLPtrProdBase,
		   SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
char lchrArrBuffer[512];
int lintTipoProducto;
const char *lchrPtrTipoProducto;

lchrPtrTipoProducto=SiscomObtenCampoRegistroProLChar("TipoProducto",pSiscomRegProLPtrProducto);
if(SePuedeVenderProducto4(pSiscomOpePtrDato,pSiscomRegProLPtrProdBase,pSiscomRegProLPtrProducto))
{
  if(lchrPtrTipoProducto)
  { 
     if(EsProductoSiscom(pSiscomRegProLPtrProducto))
     {
       LogSiscom("Es un producto Siscom , no se valida la existencia de la definicion");
     }
     else
     if(EsProductoKitPracticaEtc(pSiscomRegProLPtrProducto))
      SePuedeVenderKitPracticaEtc(pSiscomOpePtrDato,pSiscomRegProLPtrProducto);
  }
}
}
void AjustaImporteTotal4(float pfltImpTotal,
		        char *pchrPtrImporteTotal)
{
float lfltEntero;
float lfltFraccion=(float )(pfltImpTotal-(lfltEntero=(int )pfltImpTotal));
	 if(lfltFraccion>0.5)
	  sprintf(pchrPtrImporteTotal,"%.2f",lfltEntero+1);
	  else
	 if(lfltFraccion<0.5)
	 sprintf(pchrPtrImporteTotal,"%.2f",lfltEntero);
	 else
	 sprintf(pchrPtrImporteTotal,"%.2f",pfltImpTotal);
}

int NoJuegosInvalido(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrJuegos,
     *lchrPtrJuegosNuevo;
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrRegPrim=0,
		   *lSiscomRegProLPtrRegAct=0;
lchrPtrJuegos=SiscomCampoAsociadoEntradaOperacion("Envio","Juegos",pSiscomOpePtrDato);
lchrPtrJuegosNuevo=SiscomCampoAsociadoEntradaOperacion("Envio","JuegosNuevo",pSiscomOpePtrDato);
LogSiscom("Juegos (%s) Juegos Nuevo (%s)",lchrPtrJuegos,lchrPtrJuegosNuevo);
	   
SiscomAnexaRegistroPro(&lSiscomRegProLPtrRegPrim,
		       &lSiscomRegProLPtrRegAct,
		       lchrArrBuffer,
		       "Estado,Mensaje,",
		       "1",
		       "Numero de Juegos Invalido");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  lSiscomRegProLPtrRegPrim);
 return 0;
}
int DescuentoInvalido(SiscomOperaciones *pSiscomOpePtrDato)
{
 LogSiscom("");
 return 0;
}

int ProductoSinPrecioExistencia(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrJuegos,
     *lchrPtrJuegosNuevo;
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrRegPrim=0,
		   *lSiscomRegProLPtrRegAct=0;
	   
SiscomAnexaRegistroPro(&lSiscomRegProLPtrRegPrim,
		       &lSiscomRegProLPtrRegAct,
		       lchrArrBuffer,
		       "Estado,Mensaje,SePuedeVender,",
		       "3",
		       "Producto Sin precio, y sin registro en existencias",
		       "0");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			  lchrArrBuffer,
			  lSiscomRegProLPtrRegPrim);

return 0;
}

int EsOrdenCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato)
{
 return !SiscomComparaCampoAsociadoEntradaCadena("Envio",
 						"IdTipoOrden",
						"6",
						pSiscomOpePtrDato);
}


const char *SiElClienteEsNuloUsaPublicoGeneral(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrIdPersona;
const char *lchrPtrSqlIdPersona="select idpersona	\n\
				 from personas 		\n\
				 where rfc='GENERAL'";
const char *lchrPtrTipoPersona;
SiscomRegistroProL *lSisRegProLPtrCliente;
char lchrArrBuffer[128];
if((lSisRegProLPtrCliente=SiscomRegistroAsociadoEntradaOperacion("Envio","Cliente",pSiscomOpePtrDato)))
{
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrCliente);
  if((lchrPtrTipoPersona=SiscomObtenCampoRegistroProLChar("TipoPersona",lSisRegProLPtrCliente)) &&
     (lchrPtrIdPersona=SiscomObtenCampoRegistroProLChar("IdPersona",lSisRegProLPtrCliente)))
  return lchrPtrIdPersona;
  else
  return lchrPtrSqlIdPersona;
}
else
return lchrPtrSqlIdPersona;

}
int SePagaConCorrecto(float pfltImporte,
		      float pfltSePagaCon,
		      char *pchrPtrEdo,
		      char *pchrPtrDsc)
{
char *lchrPtrDscS[]={"Se paga con es menor que el importe de la orden","",0};
int lintRegreso;
 lintRegreso=pfltSePagaCon>=pfltImporte;
 sprintf(pchrPtrEdo,"%d",lintRegreso);
 strcpy(pchrPtrDsc,lchrPtrDscS[lintRegreso]);
 return lintRegreso;
}
int CalculandoCambioPago(SiscomOperaciones *pSisOpePtrDato)
{
float lfltPagaCon=SiscomCampoAsociadoEntradaOperacionFloat("Envio",
							       "PagaCon",
							       pSisOpePtrDato),
     lfltImporte=SiscomCampoAsociadoEntradaOperacionFloat("Envio",
     							  "Importe",
							  pSisOpePtrDato),
     lfltCambio;
char lchrArrCambio[25],lchrArrBuffer[128],lchrArrEdo[14],lchrArrDsc[128];
SiscomRegistroProL *lSisRegProLPtrResPrim=0,*lSisRegProLPtrResAct=0;
SePagaConCorrecto(lfltImporte,lfltPagaCon,lchrArrEdo,lchrArrDsc);
lfltCambio=lfltPagaCon-lfltImporte;
sprintf(lchrArrCambio,"%.2f",lfltCambio);
SiscomAnexaRegistroPro(&lSisRegProLPtrResPrim,
		       &lSisRegProLPtrResAct,
		       lchrArrBuffer,
		       "Cambio,Estado,Descripcion,",
		       lchrArrCambio,
		       lchrArrEdo,
		       lchrArrDsc);
SiscomEnviaRegistrosSocket(pSisOpePtrDato->intSocket,
			  lchrArrBuffer,
			  lSisRegProLPtrResPrim);
return 0;
}
int AsignaFechaHoraCotizacion(SiscomOperaciones *pSisOpePtrDato)
{
SiscomAsignaFechaHoraAsociadoEntrada("Envio","Fecha",pSisOpePtrDato);
return 0;
}
