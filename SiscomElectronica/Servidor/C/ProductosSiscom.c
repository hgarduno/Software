#include <ProductosSiscom.h>
#include <ImpresionTicketVenta.h>
#include <PedidosExpendio.h> 

#include <SqlProductosSiscom.h>


#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdlib.h>

void ValidandoCompraProductoSiscom(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{

SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSiscomOpDatError={0,NoSeRegistraNoAlcanza,0};
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ValidandoExistenciaParaCompraSiscom,&lSiscomProDat);
SiscomAgregaOperacion(EnviaComprandoProductoSiscom,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSiscomOpDatError,lSiscomProDat);
}


void IdCompraProductoSiscom(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSiscomOpDatError={0,NoSeRegistraNoAlcanza,0};
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFechaSinHora,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistroCompraProductosSiscom,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdentificadorCompraSiscom,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSiscomOpDatError,lSiscomProDat);

}

void ComprandoProductoSiscom(int pintSocket,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct)
{

SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
SiscomOperacionErrores lSiscomOpDatError={0,NoSeRegistraNoAlcanza,0};
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ValidandoExistenciaParaCompraSiscom,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoProductoSiscom,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFechaSinHora,&lSiscomProDat);
SiscomAgregaOperacion(SqlComprandoProductoSiscom,&lSiscomProDat);
SiscomAgregaOperacion(EnviaComprandoProductoSiscom,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSiscomOpDatError,lSiscomProDat);

}
int ArgumentoProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlProductoSiscom",
                                  pSiscomOpePtrDato->chrArrBaseDatos,
                                  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
                                  lchrArrBuffer,
                                  pSiscomOpePtrDato);
return 0;
}
int EnviaComprandoProductoSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadosArgumentoLog("SqlProductoSiscom",
                            "SentenciasSql",
                            lchrArrBuffer,
                            pSiscomOpePtrDato);
SiscomEnviaAsociadoEntradaCliente("Envio",lchrArrBuffer,pSiscomOpePtrDato);
return 0;
}
float ExistenciaExBoProductoSiscom(SiscomRegistroProL *pSisRegProLPtrProducto,
				 SiscomRegistroProL *pSisRegProLPtrExistencia)
{
  if(!SiscomComparaCadenaCampoRegistroProL("Bodega","Origen",pSisRegProLPtrProducto))
     return SiscomObtenCampoRegistroProLFloat("exbodegas",pSisRegProLPtrExistencia); 
  else
  if(!SiscomComparaCadenaCampoRegistroProL("Expendio","Origen",pSisRegProLPtrProducto))
     return SiscomObtenCampoRegistroProLFloat("existencia",pSisRegProLPtrExistencia); 
}
/* CDMX Lunes 27 abril 2020 
 * En medio de la pandemia de Coronavirus COVID-19
 *
 * Los dispositivos para los productos siscom se toman de la 
 * bodega no del expendio.
 *
 * Se debe agregar una regla de negocio e integrar la funcionalidad
 * en la interfaz para descontar del expendio el material  
 */
/* CDMX Lunes 12 Julio 2021 
 * Seguimos en la pandemia :( 
 *
 * Se genera una regla de negocio para tomar los productos de donde
 * haya existencia, puede ser de la bodega o del expendio 
 *
 */
int AlcanzaExistenciaProductoSiscom(float pfltCantidadAComprar,
				    SiscomRegistroProL *pSisRegProLPtrProducto,
				    SiscomRegistroProL *pSisRegProLPtrExistencias,
				    float *pfltPtrCantidadAComprar,
				    float *pfltPtrExistencia)
{
float lfltCantidad;
while(pSisRegProLPtrExistencias)
{
   if(!SiscomComparaCampoRegistrosProL2("cveproducto",
   				      "cveproducto",
				      pSisRegProLPtrProducto,
				      pSisRegProLPtrExistencias))
   {
      lfltCantidad=SiscomObtenCampoRegistroProLFloat("cantidad",pSisRegProLPtrProducto);
      *pfltPtrExistencia=ExistenciaExBoProductoSiscom(pSisRegProLPtrProducto,
      						      pSisRegProLPtrExistencias);
      *pfltPtrCantidadAComprar=lfltCantidad*pfltCantidadAComprar;
      if(*pfltPtrCantidadAComprar>*pfltPtrExistencia)
	 return 0;
      else
	return 1;
   }
  pSisRegProLPtrExistencias=pSisRegProLPtrExistencias->SiscomRegProLPtrSig; 
 }
}
void AgregaRegistroNoAlcanza(SiscomRegistroProL *pSisRegProLPtrProducto,
			     float pfltCantidadParaComprar,
			     float pfltExistencia)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrPrim=0,
		   *lSisRegProLPtrAct=0;
SiscomAnexaRegistroPro(&lSisRegProLPtrPrim,
		       &lSisRegProLPtrAct,
		       lchrArrBuffer,
		       "AComprar,Existencia,",
		       (const char *)0,
		       (const char *)0);
SiscomActualizaCampoFloatRegistroActual("AComprar",
				  "%.2f",
				  pfltCantidadParaComprar,
				  lSisRegProLPtrPrim);

SiscomActualizaCampoFloatRegistroActual("Existencia",
				  "%.2f",
				  pfltExistencia,
				  lSisRegProLPtrPrim);
SiscomAgregaCampoRegistro("NoAlcanza",0,pSisRegProLPtrProducto);
SiscomRegistrosAlCampo("NoAlcanza",
			lSisRegProLPtrPrim,
			lSisRegProLPtrAct,
			pSisRegProLPtrProducto);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrPrim);
}
int ValidandoExistenciaParaCompraSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrCondicion;
int lintAlgunoNoAlcanza=0;
float lfltCantidadAComprar=SiscomCampoAsociadoEntradaOperacionFloat("Envio",
								    "CantidadAComprar",
								    pSiscomOpePtrDato);
float lfltCantidadParaComprar,lfltExistencia;
SiscomRegistroProL *lSiscomRegProLPtrProductos,
		   *lSiscomRegProLPtrExistencias;
if((lSiscomRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio",
								     "Productos",
								     pSiscomOpePtrDato)))
{
lchrPtrCondicion=CondicionExistenciaDefinicionProducto(lSiscomRegProLPtrProductos);
SqlExistenciasDefinicionProducto(lchrPtrCondicion,pSiscomOpePtrDato);
lSiscomRegProLPtrExistencias=SiscomObtenRegistrosCampoRespuesta("ExisDefinicionProd",
								pSiscomOpePtrDato);
while(lSiscomRegProLPtrProductos)
{
  LogSiscom("%s",
  	    SiscomObtenCampoRegistroProLChar("cveproducto",lSiscomRegProLPtrProductos));
 if(!AlcanzaExistenciaProductoSiscom(lfltCantidadAComprar,
 				    lSiscomRegProLPtrProductos,
				    lSiscomRegProLPtrExistencias,
				    &lfltCantidadParaComprar,
				    &lfltExistencia))
  {
    AgregaRegistroNoAlcanza(lSiscomRegProLPtrProductos,
    			    lfltCantidadParaComprar,
			    lfltExistencia);
    lintAlgunoNoAlcanza=1;
  }

  lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig;
}
}
if(lintAlgunoNoAlcanza)
{
  SiscomAgregaCampoAsociadoEntrada("AlgunoNoAlcanza",0,"Envio",pSiscomOpePtrDato);
  return 1;
}
return 0;
}

char *CondicionExistenciaDefinicionProducto(SiscomRegistroProL *pSiscomRegProLPtrDato)
{
char *lchrPtrCondicion;
const char *lchrPtrDato;
char lchrArrPaso[128];
int lintTamanoBuffer;
lchrPtrCondicion=strdup("where cveproducto in(");

 while(pSiscomRegProLPtrDato)
 {
   lchrPtrDato=SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato);
   if(pSiscomRegProLPtrDato->SiscomRegProLPtrSig)
   sprintf(lchrArrPaso, "'%s',",lchrPtrDato);
   else
   sprintf(lchrArrPaso,"'%s');",lchrPtrDato);
   lintTamanoBuffer=strlen(lchrPtrCondicion)+strlen(lchrArrPaso)+1;
   lchrPtrCondicion=realloc((void *)lchrPtrCondicion,lintTamanoBuffer);
   strcat(lchrPtrCondicion,lchrArrPaso);
   pSiscomRegProLPtrDato=pSiscomRegProLPtrDato->SiscomRegProLPtrSig;
 }
return lchrPtrCondicion;
}

int NoSeRegistraNoAlcanza(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
 LogSiscom("Se Contesta con error porque no alcanza");
 SiscomEnviaAsociadoEntradaCliente("Envio",lchrArrBuffer,pSiscomOpePtrDato);
}

const char *HayRegistroProductoSiscomHoy(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128]; 
char lchrArrIdCompra[18];
SiscomRegistroProL *lSisRegProLPtrDato;

if((lSisRegProLPtrDato=SiscomRegistrosAsociadoRespuestaOperacion("RegistroCompProdSiscom",
								pSiscomOpePtrDato)))
{
SiscomAsociadoRespuestaLog("RegistroCompProdSiscom",
			  lchrArrBuffer,
			  pSiscomOpePtrDato);
return SiscomCampoAsociadoRespuesta("RegistroCompProdSiscom",
				     "idcompra",
				     pSiscomOpePtrDato);
}
else
{
SiscomObtenNumeroUnicoChar(lchrArrIdCompra);
return strdup(lchrArrIdCompra);
}
}

int EnviaIdentificadorCompraSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[56];
const char *lchrPtrIdCompra;

if((lchrPtrIdCompra=HayRegistroProductoSiscomHoy(pSiscomOpePtrDato)))
{ 
    /* CDMX a 31 Enero del 2019 
     * Esto esta MUY Mal , hay que hacer una funcion para 
     * liberar la lista 
     */
    pSiscomOpePtrDato->SiscomRegProLPtrPrimRes=0;
    pSiscomOpePtrDato->SiscomRegProLPtrActRes=0;
   SiscomFormaEnviaRegistroRespuesta(pSiscomOpePtrDato,
   				     lchrArrBuffer, 
				     "IdCompra,",
				     lchrPtrIdCompra);
}
return 0;
}
