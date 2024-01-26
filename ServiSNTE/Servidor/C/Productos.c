#include <Productos.h>
#include <SqlProductos.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
#include <stdio.h>
void AgregaPreciosProducto(int pintSocket,
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
SiscomAgregaOperacion(SqlPreciosProducto,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdPersonaRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat); }

void RegistraProducto(int pintSocket,
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
SiscomAgregaOperacion(GeneraIdProducto,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFecha,&lSiscomProDat);
SiscomAgregaOperacion(AgregaCodigoBarras,&lSiscomProDat);
SiscomAgregaOperacion(AgregaIdPrecio,&lSiscomProDat);
SiscomAgregaOperacion(IdDescuento,&lSiscomProDat);
SiscomAgregaOperacion(IdCosto,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraProducto,&lSiscomProDat);
SiscomAgregaOperacion(EstadoRegistroProducto,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void PreciosDescuentosProducto(int pintSocket,
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
SiscomAgregaOperacion(SqlPreciosDescuentosProducto,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPreciosDescuentosProducto,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ActualizandoStock(int pintSocket,
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
SiscomAgregaOperacion(SqlActualizandoStock,&lSiscomProDat);
SiscomAgregaOperacion(RespondeActualizaStock,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int RespondeActualizaStock(SiscomOperaciones *pSiscomOpePtrDato)
{
   RespondiendoEstadoInsercion("SqlInsertaProducto",pSiscomOpePtrDato);
   return 0;
}

int EnviaPreciosDescuentosProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
if(SiscomRegistrosAsociadoRespuestaOperacion("PreciosForaneos",pSiscomOpePtrDato) &&
   SiscomRegistrosAsociadoRespuestaOperacion("PreciosGeneral",pSiscomOpePtrDato) &&
   SiscomRegistrosAsociadoRespuestaOperacion("CostoBruto",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
else
RespondeConsultaSinRegistros(pSiscomOpePtrDato);
/*
SiscomAsociadoRespuestaLog("PreciosForaneos",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("PreciosGeneral",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("CostoBruto",lchrArrBuffer,pSiscomOpePtrDato);
*/
return 0;
}
int EstadoRegistroProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
const char *lchrPtrIdPersona;
lchrPtrIdPersona=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "IdPersona",
						     pSiscomOpePtrDato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdPersona,Mensajes,",
		       lchrPtrIdPersona,
		       "Registro Exitoso");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomAsociadosArgumentoLog("SqlInsertaProducto",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
}
int EnviaAnexarPrecioProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
const char *lchrPtrIdPersona;
lchrPtrIdPersona=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "IdPersona",
						     pSiscomOpePtrDato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdPersona,Mensajes,",
		       lchrPtrIdPersona,
		       "Registro Exitoso");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomAsociadosArgumentoLog("SqlInsertaProducto",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
}


void SumaProductosCodigoBarras(int pintSocket,
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
SiscomAgregaOperacion(EnviaProductosSumados,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int GeneraIdProducto(SiscomOperaciones *pSiscomOpePtrDato)
{
  SiscomIdARegistrosAsociadosEntrada("Envio","IdProducto",pSiscomOpePtrDato);
}
int AgregaCodigoBarras(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrCodigoBarras[25];
sprintf(lchrArrCodigoBarras,
	"%011d%03d",
	SiscomCampoAsociadoEntradaOperacionInt("Envio",
					       "IdProducto",
					       pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacionInt("Envio",
					       "IdProveedor",
					       pSiscomOpePtrDato));
SiscomAgregaCampoAsociadoEntrada("CodigoBarras",
				 lchrArrCodigoBarras,
				 "Envio",
				 pSiscomOpePtrDato);
}

int AgregaIdPrecio(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaCampoAsociadoEntrada("IdPrecio",
				 0,
				 "Envio",
				 pSiscomOpePtrDato);
SiscomIdARegistrosAsociadosEntrada("Envio",
				   "IdPrecio",
				   pSiscomOpePtrDato);
}
int AgregaFecha(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaCampoAsociadoEntrada("Fecha",
				 0,
				 "Envio",
				 pSiscomOpePtrDato);
SiscomAsignaFechaHoraAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
}
int IdDescuento(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdAsociadoAsociadosCampoEntrada("Envio",
				      "Descuento",
				      "iddescuentoempresa",
				      pSiscomOpePtrDato);
}

int IdCosto(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdAsociadoAsociadosCampoEntrada("Envio",
				      "Costo",
				      "idcostobruto",
				      pSiscomOpePtrDato);
}
int EnviaProductosSumados(SiscomOperaciones *pSiscomOpePtrDato)
{
    SiscomRegistroProL *lSiscomRegProLPtrDatos=0,
                       *lSiscomRegProLPtrPrim=0,
		               *lSiscomRegProLPtrAct=0,
                       *lSiscomRegProLPtrBusqueda=0,
                       *lSiscomRegProLPtrAux=0;
    char lchrArrBuffer[128],
         lchrArrContador[5];
    const char *lchrPtrIdPersona;
    int lintContador;
    lSiscomRegProLPtrDatos=SiscomRegistrosAsociadoEntradaOperacion("Envio",
                                pSiscomOpePtrDato);
    LogSiscom("Se recibe la sig. lista de productos ->");
    SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrDatos);
    /* HGarduno A esta funcion se le pasa una estructura SiscomCampoProL SiscomCamposProtocoloLog(pSiscomOpePtrDato); */
    lSiscomRegProLPtrBusqueda = lSiscomRegProLPtrAux = lSiscomRegProLPtrDatos;
    for(;
        lSiscomRegProLPtrDatos;
        lSiscomRegProLPtrDatos=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrDatos))
    {
        lintContador = AsignaCantidadEntrada(lSiscomRegProLPtrDatos);
        //Verificamos si este producto ya se contabilizo.
        for(lSiscomRegProLPtrBusqueda = lSiscomRegProLPtrPrim;
            lSiscomRegProLPtrBusqueda;
            lSiscomRegProLPtrBusqueda=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrBusqueda))
        { 
            if(SiscomRegistrosConCampoIguales("numproducto",
                                       lSiscomRegProLPtrDatos,
                                       lSiscomRegProLPtrBusqueda)){
                lintContador = -1;
                break;
            }
        }
        if(lintContador == -1) continue;
        for(lSiscomRegProLPtrBusqueda = lSiscomRegProLPtrAux;
            lSiscomRegProLPtrBusqueda;
            lSiscomRegProLPtrBusqueda=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrBusqueda))
        {
            if(SiscomRegistrosConCampoIguales("numproducto",
                                       lSiscomRegProLPtrDatos,
                                       lSiscomRegProLPtrBusqueda))
                lintContador++;
        }
        sprintf(lchrArrContador, "%d", lintContador);
        SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
               &lSiscomRegProLPtrAct,
               lchrArrBuffer,
               "idproducto,numproducto,nombreproducto,modelo,codigobarras,cantidad,esstock,",
               SiscomObtenCampoRegistroProLChar("idproducto",lSiscomRegProLPtrDatos),
               SiscomObtenCampoRegistroProLChar("numproducto",lSiscomRegProLPtrDatos),
               SiscomObtenCampoRegistroProLChar("nombreproducto",lSiscomRegProLPtrDatos),
               SiscomObtenCampoRegistroProLChar("modelo",lSiscomRegProLPtrDatos),
               SiscomObtenCampoRegistroProLChar("codigobarras",lSiscomRegProLPtrDatos),
               lchrArrContador,
	       SiscomObtenCampoRegistroProLChar("EsStock",lSiscomRegProLPtrDatos));
        /*LogSiscom("Producto: # %s Producto: %s Cantidad: %s",
        SiscomObtenCampoRegistroProLChar("numproducto",lSiscomRegProLPtrPrim),
        SiscomObtenCampoRegistroProLChar("nombreproducto",lSiscomRegProLPtrPrim),
        lchrArrContador);
        */
    }
    LogSiscom("Lista con productos sumados ->");
    SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
    SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
               lchrArrBuffer,
               lSiscomRegProLPtrPrim);
    //lSiscomRegProLPtrPrim=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrPrim);
    //SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
/*    lSiscomRegProLPtrProductos=SiscomObtenArgumentoPrimOperaciones("Envio",
                                pSiscomOpePtrDato);
    lSiscomRegProLPtrProductos=SiscomRegistrosAsociadosCampoEntrada("Envio",
                                "Productos",
                                pSiscomOpePtrDato);
    SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrProductos);
*/
}

int AsignaCantidadEntrada(SiscomRegistroProL *pSiscomRegProLProducto)
{
int lintCantidad=SiscomObtenCampoRegistroProLInt("Cantidad",pSiscomRegProLProducto);
  return lintCantidad ? lintCantidad-1:0;
}
