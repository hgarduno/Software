#include <ExistenciaExpendios.h>

#include <SqlSiscomElectronica.h>
#include <SqlExistenciaExpendios.h>
#include <SqlProductosSE.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomReplicacion.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#include <stdarg.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>



void ExistenciaExpendios(int pintSocket,
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
SiscomAgregaOperacion(CreaArgumentosExistenciaExpendios,&lSiscomProDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlComunicacionMatrizAArgumento,&lSiscomProDat); 
SiscomAgregaOperacion(AccesoDatosSiscomMatriz,&lSiscomProDat);
SiscomAgregaOperacion(SqlComunicacionExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ActualizaMatrizConsultaExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlExistenciaExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ExistenciaProductoExpendios,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}




void ExistenciaSiscom(int pintSocket,
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
SiscomAgregaOperacion(CreaArgumentosExistenciaExpendios,&lSiscomProDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlComunicacionMatrizAArgumento,&lSiscomProDat); 
SiscomAgregaOperacion(AccesoDatosSiscomMatriz,&lSiscomProDat);
SiscomAgregaOperacion(SqlComunicacionExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ActualizaMatrizConsultaExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlExistenciasVentasExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ExistenciasVentasExpendios,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void ExistenciaSiscomT(int pintSocket,
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
SiscomAgregaOperacion(CreaArgumentosExistenciaExpendios,&lSiscomProDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlComunicacionMatrizAArgumento,&lSiscomProDat); 
SiscomAgregaOperacion(AccesoDatosSiscomMatriz,&lSiscomProDat);
SiscomAgregaOperacion(SqlComunicacionExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ActualizaMatrizConsultaExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlExistenciasVentasExpendiosT,&lSiscomProDat);
SiscomAgregaOperacion(ExistenciasVentasExpendiosT,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void SiscomAgrupaConsultaSistema(int pintDatosOrdenados,
				 const char *pchrPtrCampo,  
				 const char *pchrPtrArgRegServsSistema,
				 const char *pchrPtrArgRegCampoServsSistema,
				 const char *pchrPtrCampoSistema,
				 const char *pchrPtrCampoRespConsulta,
				char *pchrPtrNombreAsociado,
				char **pchrPtrCamposRegistroAgrupado,
				char **pchrPtrCamposRegistro,
				const char *pchrPtrArgSalida,
				SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
const char *lchrPtrCampoSistema;
int lintNRegistros=0;
SiscomRegistroProL *lSiscomRegProLPtrExpendios,
		   *lSiscomRegProLPtrConsulta;
SiscomRegistroProL *lSiscomRegProLPtrRegreso=0,
		  *lSiscomRegProLPtrUltimoProducto,
		  *lSiscomRegProLPtrAgrupadoPrim=0,
		  *lSiscomRegProLPtrAgrupadoAct=0;
SiscomRegistroProL *lSiscomRegProLPtrDatosOrdenadosPrim=0,
		   *lSiscomRegProLPtrDatosOrdenadosAct=0,
		   *lSiscomRegProLPtrEnvio;
lSiscomRegProLPtrExpendios=SiscomObtenArgumentoPrimAsociadoOperaciones(
				pchrPtrArgRegServsSistema,
				pchrPtrArgRegCampoServsSistema,
				pSiscomOpePtrDato);

for(;
    lSiscomRegProLPtrExpendios;
    lSiscomRegProLPtrExpendios=lSiscomRegProLPtrExpendios->SiscomRegProLPtrSig)
{
     lchrPtrCampoSistema=SiscomObtenCampoRegistroProLChar(pchrPtrCampoSistema,
     							lSiscomRegProLPtrExpendios);
    
    LogSiscom("%s %s",lchrPtrCampoSistema,pchrPtrCampoRespConsulta);
    
     lSiscomRegProLPtrConsulta=SiscomRegistrosMaquinaConsulta(lchrPtrCampoSistema,
     							  pchrPtrCampoRespConsulta,
							  pSiscomOpePtrDato);
	
     LogSiscom("Informacion de %s %d Registros(%s)",
     		lchrPtrCampoSistema,
		lSiscomRegProLPtrConsulta->intNRegistros,
		pchrPtrCampoRespConsulta);
     lintNRegistros+=lSiscomRegProLPtrConsulta->intNRegistros;
     if(!lSiscomRegProLPtrRegreso)
      lSiscomRegProLPtrRegreso=lSiscomRegProLPtrConsulta;
      else
      {
      lSiscomRegProLPtrUltimoProducto=SiscomUltimoNodoLista(lSiscomRegProLPtrRegreso);
      lSiscomRegProLPtrUltimoProducto->SiscomRegProLPtrSig=lSiscomRegProLPtrConsulta;
      }

}
lSiscomRegProLPtrRegreso->intNRegistros=lintNRegistros;
if(!pintDatosOrdenados &&
    lSiscomRegProLPtrRegreso->intNRegistros>1)
{
 SiscomOrdenaRegistroProL(pchrPtrCampo,
 			  lSiscomRegProLPtrRegreso,
			  &lSiscomRegProLPtrDatosOrdenadosPrim,
			  &lSiscomRegProLPtrDatosOrdenadosAct);
lSiscomRegProLPtrEnvio=lSiscomRegProLPtrDatosOrdenadosPrim;
}
else
lSiscomRegProLPtrEnvio=lSiscomRegProLPtrRegreso;
SiscomAgrupaPorCampo(pchrPtrCampo,
		     pchrPtrNombreAsociado,
		     pchrPtrCamposRegistroAgrupado,
		     pchrPtrCamposRegistro,
		     lSiscomRegProLPtrEnvio,
		     &lSiscomRegProLPtrAgrupadoPrim,
		     &lSiscomRegProLPtrAgrupadoAct);
SiscomAgregaArgumentoOperacion(pchrPtrArgSalida,
				lSiscomRegProLPtrAgrupadoPrim,
				lSiscomRegProLPtrAgrupadoAct,
				pSiscomOpePtrDato);
}
int ExistenciaProductoExpendios(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
const char *lchrPtrExpendio;
char *lchrPtrCamposRegAgrupado[]={"cveproducto",0};
char *lchrPtrCamposRegistro[]={"idexpendio",
			       "existencia",
			       "precio",
			       "eximinima",
			       "razonsocial",
			       "bodega",
			       "existenciab",
			       0};
SiscomRegistroProL *lSiscomRegProLPtrRegreso;

SiscomAgrupaConsultaSistema(0,
			    "cveproducto",
			    "Expendios",  
			    "Servidores",
			    "idempresa", 
			    "Existencia",
			    "Expendio",
			    lchrPtrCamposRegAgrupado,
			    lchrPtrCamposRegistro,
			    "Existencias",
			    pSiscomOpePtrDato);
lSiscomRegProLPtrRegreso=SiscomObtenArgumentoPrimOperaciones("Existencias",pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrRegreso);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,lchrArrBuffer,lSiscomRegProLPtrRegreso);
return 0;
}
SiscomRegistroProL *VentasSiscomElectronica(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
const char *lchrPtrExpendio;
char *lchrPtrCamposRegAgrupado[]={"cveproducto",0};
char *lchrPtrCamposRegistro[]={"totalventas",
			       0};
SiscomRegistroProL *lSiscomRegProLPtrRegreso;
LogSiscom("Agrupando Ventas");
SiscomAgrupaConsultaSistema(0,
			    "cveproducto",
			    "Expendios",
			    "Servidores",
			    "idempresa",
			    "Ventas",
			    "Ventas",
			    lchrPtrCamposRegAgrupado,
			    lchrPtrCamposRegistro,
			    "VentasTotales",
			    pSiscomOpePtrDato);
	
LogSiscom("Termino de agrupar Ventas (%d Registros agrupados)",
	  SiscomObtenArgumentoPrimOperaciones("VentasTotales",pSiscomOpePtrDato)->intNRegistros);
return SiscomObtenArgumentoPrimOperaciones("VentasTotales",pSiscomOpePtrDato);
}
SiscomRegistroProL *ExistenciasSiscomElectronica(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrExpendio;
char *lchrPtrCamposRegAgrupado[]={"cveproducto",0};
char *lchrPtrCamposRegistro[]={"existenciat",
			       0};
SiscomRegistroProL *lSiscomRegProLPtrRegreso;
LogSiscom("Agrupando las existencias ");
SiscomAgrupaConsultaSistema(0,
			    "cveproducto",
			    "Expendios",
			    "Servidores",
			    "idempresa",
			    "Existencia",
			    "Existencias",
			    lchrPtrCamposRegAgrupado,
			    lchrPtrCamposRegistro,
			    "ExistenciasTotales",
			    pSiscomOpePtrDato);
LogSiscom("Termino de agrupar Existencias (%d Registros Agrupados)",
	  SiscomObtenArgumentoPrimOperaciones("ExistenciasTotales",pSiscomOpePtrDato)->intNRegistros);
return SiscomObtenArgumentoPrimOperaciones("ExistenciasTotales",pSiscomOpePtrDato);
}

float SumaVentasPorProducto(SiscomRegistroProL *pSiscomRegProLPtrVentas,
			    char *pchrPtrTotalVentas)
{
SiscomRegistroProL *lSiscomRegProLPtrVentas;
float lfltVentas=0;
lSiscomRegProLPtrVentas=SiscomObtenRegistrosCampoProL("Ventas",pSiscomRegProLPtrVentas);

for(;
    lSiscomRegProLPtrVentas;
    lSiscomRegProLPtrVentas=lSiscomRegProLPtrVentas->SiscomRegProLPtrSig)
  lfltVentas+=SiscomObtenCampoRegistroProLFloat("totalventas",lSiscomRegProLPtrVentas);
sprintf(pchrPtrTotalVentas,"%.2f",lfltVentas);

return lfltVentas;
}

float SumaExistenciasPorProducto(SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			    char *pchrPtrTotalExistencias)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrExistencias;
float lfltExistencias=0;
lSiscomRegProLPtrExistencias=SiscomObtenRegistrosCampoProL("Existencias",pSiscomRegProLPtrExistencias);

for(;
    lSiscomRegProLPtrExistencias;
    lSiscomRegProLPtrExistencias=lSiscomRegProLPtrExistencias->SiscomRegProLPtrSig)
  lfltExistencias+=SiscomObtenCampoRegistroProLFloat("existenciat",lSiscomRegProLPtrExistencias);
sprintf(pchrPtrTotalExistencias,"%.2f",lfltExistencias);
return lfltExistencias;
}

const char *SumandoExistenciasPorProducto(const char *pchrPtrCveProducto,
				   SiscomRegistroProL *pSiscomRegProLPtrExistencias,
				   char *pchrPtrExistencias)
{
SiscomRegistroProL *lSiscomRegProLPtrProducto;
   if((lSiscomRegProLPtrProducto=SiscomBuscaRegistroLista("cveproducto",
   							  pchrPtrCveProducto,
							  pSiscomRegProLPtrExistencias)))
    {
          for( ;
	  	lSiscomRegProLPtrProducto; 
		lSiscomRegProLPtrProducto=lSiscomRegProLPtrProducto->SiscomRegProLPtrSig)
	  if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrCveProducto,
	  					   "cveproducto",
						   lSiscomRegProLPtrProducto))
	  {
          SumaExistenciasPorProducto(lSiscomRegProLPtrProducto,pchrPtrExistencias); 
	  break;
	  }
    }
   else
   LogSiscom("El Producto (%s) No tiene registros en Existencias");

}

void GenerandoRespuestaVentasExistencias(SiscomRegistroProL *pSiscomRegProLPtrVentas,
				         SiscomRegistroProL *pSiscomRegProLPtrExistencias,
					 SiscomRegistroProL **pSiscomRegProLPtrPrimRes,
					 SiscomRegistroProL **pSiscomRegProLPtrActRes)
{
char lchrArrBuffer[256],
	lchrArrVentas[28],
	lchrArrExistencias[28];
const char *lchrPtrProducto;
*pSiscomRegProLPtrPrimRes=*pSiscomRegProLPtrActRes=0;
LogSiscom("Registros Existencias (%d) Registros Ventas(%d)",
	  pSiscomRegProLPtrExistencias->intNRegistros,
	  pSiscomRegProLPtrVentas->intNRegistros);
for(;
    pSiscomRegProLPtrVentas;
    pSiscomRegProLPtrVentas=pSiscomRegProLPtrVentas->SiscomRegProLPtrSig)
{
   lchrPtrProducto=SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrVentas);
    SumaVentasPorProducto(pSiscomRegProLPtrVentas,lchrArrVentas);
    SumandoExistenciasPorProducto(lchrPtrProducto,pSiscomRegProLPtrExistencias,lchrArrExistencias);
    SiscomAnexaRegistroPro(pSiscomRegProLPtrPrimRes,
    			   pSiscomRegProLPtrActRes,
			   lchrArrBuffer,
			   "CveProducto,"
			   "Ventas,"
			   "Existencia,"
			   "Diferencia",
			    SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrVentas),
			    lchrArrVentas,
			    lchrArrExistencias);
}
}

int ExistenciasVentasExpendios(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrExistencias,
		   *lSiscomRegProLPtrVentas,
		   *lSiscomRegProLPtrResPrim,
		   *lSiscomRegProLPtrResAct;
lSiscomRegProLPtrVentas=VentasSiscomElectronica(pSiscomOpePtrDato);
lSiscomRegProLPtrExistencias=ExistenciasSiscomElectronica(pSiscomOpePtrDato);
/*
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrVentas);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrExistencias);

*/
GenerandoRespuestaVentasExistencias(lSiscomRegProLPtrVentas,
				    lSiscomRegProLPtrExistencias,
				    &lSiscomRegProLPtrResPrim,
				    &lSiscomRegProLPtrResAct);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrResPrim);
return 0;
}
void ExistenciaExpendiosAlLog(const char *pchrPtrArchivo,
			  const char *pchrPtrFuncion,
			  int pintLineaN,
			  SiscomRegistroProL *pSisRegProLPtrDatos)
{
const char *lchrPtrCveProducto;
for(;
	pSisRegProLPtrDatos;
	pSisRegProLPtrDatos=pSisRegProLPtrDatos->SiscomRegProLPtrSig)
{
   lchrPtrCveProducto=SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrDatos);
   if(lchrPtrCveProducto)
   SiscomMensajesLog4(pchrPtrArchivo,
   		      pchrPtrFuncion,
		      pintLineaN,
		      "%s %s",
		      lchrPtrCveProducto,
		      SiscomObtenCampoRegistroProLChar("existenciat",pSisRegProLPtrDatos));
   else
   SiscomMensajesLog4(pchrPtrFuncion,
   		      pchrPtrFuncion,
		      pintLineaN,
		      "Registro con producto null");

}

}
int ExistenciasVentasExpendiosT(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrExistencias,
		   *lSiscomRegProLPtrVentas,
		   *lSiscomRegProLPtrResPrim,
		   *lSiscomRegProLPtrResAct;
lSiscomRegProLPtrVentas=VentasSiscomElectronica(pSiscomOpePtrDato);
lSiscomRegProLPtrExistencias=ExistenciasSiscomElectronica(pSiscomOpePtrDato);
GenerandoRespuestaVentasExistencias(lSiscomRegProLPtrVentas,
				    lSiscomRegProLPtrExistencias,
				    &lSiscomRegProLPtrResPrim,
				    &lSiscomRegProLPtrResAct);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrResPrim);
return 0;
}

int CreaArgumentosExistenciaExpendios(SiscomOperaciones *pSiscomOpePtrDato)
{

SiscomAgregaArgumentoOperacion("Expendios",
				(SiscomRegistroProL *)0,
				(SiscomRegistroProL *)0,
				pSiscomOpePtrDato);
SiscomAgregaArgumentoOperacion("Matriz",
				(SiscomRegistroProL *)0,
				(SiscomRegistroProL *)0,
				pSiscomOpePtrDato);
return 0;
}

void AgregandoProductoParaConsulta(SiscomRegistroProL *pSiscomRegProLPtrProducto,
				   char **pchrPtrCondicion)
{
char lchrArrCadena[256];
int lintTamano;
sprintf(lchrArrCadena,
	"'%s',",
	SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrProducto));
lintTamano=strlen(*pchrPtrCondicion)+strlen(lchrArrCadena)+1;
*pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,lintTamano);
strcat(*pchrPtrCondicion,lchrArrCadena);
}
void AgregandoFinalParaConsulta(SiscomRegistroProL *pSiscomRegProLPtrProducto,
				char **pchrPtrCondicion)
{
char lchrArrCadena[256];
int lintTamano;
sprintf(lchrArrCadena,
	"'%s') and 				\n\
	nmbtipoprecio='DEFAULT' and		\n\
        idpersona in(select idpersona		\n\
                     from personas		\n\
                     where rfc='GENERAL')",
	SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrProducto));

lintTamano=strlen(*pchrPtrCondicion)+strlen(lchrArrCadena)+1;
*pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,lintTamano);
strcat(*pchrPtrCondicion,lchrArrCadena);
}
void CondicionConsultaProductos(SiscomRegistroProL *pSiscomRegProLPtrProductos,
				char **pchrPtrCondicion)
{
 for(;
     pSiscomRegProLPtrProductos;
     pSiscomRegProLPtrProductos=pSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
{
    if(pSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
    AgregandoProductoParaConsulta(pSiscomRegProLPtrProductos,pchrPtrCondicion);
    else
    AgregandoFinalParaConsulta(pSiscomRegProLPtrProductos,pchrPtrCondicion);
}
}

void AgregaRegistroExistencia(SiscomRegistroProL **pSiscomRegProLPtrPrim,
			   SiscomRegistroProL **pSiscomRegProLPtrAct)
{
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(pSiscomRegProLPtrPrim,
		       pSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "Existencia,",
		       (const char *)0);
}
void AgregaRegistroVentaExistencia(SiscomRegistroProL **pSisRegProLPtrPrim,
				   SiscomRegistroProL **pSisRegProLPtrAct)
{
char lchrArrBuffer[255];
SiscomAnexaRegistroPro(pSisRegProLPtrPrim,
		       pSisRegProLPtrAct,
		       lchrArrBuffer,
		       "Existencia,Ventas,",
		       (const char *)0,
		       (const char *)0);
}
void AgregaRegistroDatosExistencia(SiscomRegistroProL **pSiscomRegProLPtrPrim,
				   SiscomRegistroProL **pSiscomRegProLPtrAct,
				   const char *pchrPtrCampo,
				   SiscomRegistroProL *pSiscomRegProLPtrMaquina,
				   SiscomRegistroProL *pSiscomRegProLPtrProducto)
{
char lchrArrBuffer[256];
SiscomAnexaRegistroPro(
	pSiscomRegProLPtrPrim,
	pSiscomRegProLPtrAct,
	lchrArrBuffer,
	"cveproducto,existencia,idexpendio,eximinima,precio,razonsocial,",
	SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrProducto),
	"0",
	pchrPtrCampo, 
	"0",
	"0",
	SiscomObtenCampoRegistroProLChar("razonsocial",pSiscomRegProLPtrMaquina));

}
void AgregaRegistroCeroVenta(SiscomRegistroProL **pSisRegProLPtrPrim,
			     SiscomRegistroProL **pSisRegProLPtrAct,
			const char *pchrPtrCveProducto)
{
char lchrArrBuffer[256];
SiscomAnexaRegistroPro(pSisRegProLPtrPrim,
		       pSisRegProLPtrAct,
		       lchrArrBuffer,
		       "totalventas,cveproducto,",
		       "0",
		       pchrPtrCveProducto);

}

void AgregaRegistroCeroVExistencia(SiscomRegistroProL **pSisRegProLPtrPrim,
			     SiscomRegistroProL **pSisRegProLPtrAct,
			const char *pchrPtrCveProducto)
{
char lchrArrBuffer[256];
SiscomAnexaRegistroPro(pSisRegProLPtrPrim,
		       pSisRegProLPtrAct,
		       lchrArrBuffer,
		       "cveproducto,existenciat,",
		       pchrPtrCveProducto,
		       "0");

}
int EstadoConsultaSistemaSiscom(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
				const char *pchrPtrCampo,
				SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrExistencia;
const char *lchrPtrIdExpendio;
lchrPtrIdExpendio=SiscomObtenCampoRegistroProLChar("idempresa",pSiscomRegProLPtrMaquinas);

/*
lSiscomRegProLPtrExistencia=SiscomRegistrosAsociadosCampo(lchrPtrIdExpendio,
							  "Existencia",
							  pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
*/
/*SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrExistencia); 
SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomOpePtrDato->SiscomRegProLPtrPrimRes); 
*/
lSiscomRegProLPtrExistencia=SiscomObtenRegistrosCampoProL(lchrPtrIdExpendio,
						pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrExistencia);
return !lSiscomRegProLPtrExistencia;
}

int EstadoConsultaVentasExistenciaSiscom(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
				const char *pchrPtrCampo,
				SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrExistencia;
const char *lchrPtrIdExpendio;
lchrPtrIdExpendio=SiscomObtenCampoRegistroProLChar("idempresa",pSiscomRegProLPtrMaquinas);

/*
lSiscomRegProLPtrExistencia=SiscomRegistrosAsociadosCampo(lchrPtrIdExpendio,
							  "Existencia",
							  pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
*/
/*SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrExistencia); 
SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomOpePtrDato->SiscomRegProLPtrPrimRes); 
*/
lSiscomRegProLPtrExistencia=SiscomObtenRegistrosCampoProL(lchrPtrIdExpendio,
						pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrExistencia);
return !lSiscomRegProLPtrExistencia;
}

int EstadoConsultaSistemaSiscomT(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
				const char *pchrPtrCampo,
				SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrExistencia;
const char *lchrPtrIdExpendio;
lchrPtrIdExpendio=SiscomObtenCampoRegistroProLChar("idempresa",pSiscomRegProLPtrMaquinas);

/*
lSiscomRegProLPtrExistencia=SiscomRegistrosAsociadosCampo(lchrPtrIdExpendio,
							  "Existencia",
							  pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
*/
lSiscomRegProLPtrExistencia=SiscomObtenRegistrosCampoProL(lchrPtrIdExpendio,
						 	pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrExistencia);
return !lSiscomRegProLPtrExistencia;
}

int ErrorConexionExpendio(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
			  const char *pchrPtrCampo,
			  SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrimInfoExp=0,
		   *lSiscomRegProLPtrActInfoExp=0,
		   *lSiscomRegProLPtrProductos,
		   *lSiscomRegProLPtrPrimExistencia=0,
		   *lSiscomRegProLPtrActExistencia=0;
LogSiscom("Se proceso consulta con error");
lSiscomRegProLPtrProductos=SiscomRegistrosAsociadoEntradaOperacion("Envio",
								pSiscomOpePtrDato);

AgregaRegistroExistencia(&lSiscomRegProLPtrPrimExistencia,
			 &lSiscomRegProLPtrActExistencia);
for(;
     lSiscomRegProLPtrProductos;
     lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
   AgregaRegistroDatosExistencia(&lSiscomRegProLPtrPrimInfoExp,
   				 &lSiscomRegProLPtrActInfoExp,
				 pchrPtrCampo,
				 pSiscomRegProLPtrMaquinas,
				 lSiscomRegProLPtrProductos);

SiscomRegistrosAlCampo("Existencia",
			lSiscomRegProLPtrPrimInfoExp,
			lSiscomRegProLPtrActInfoExp,
			lSiscomRegProLPtrPrimExistencia);
SiscomRegistrosAlCampo(pchrPtrCampo,
		      lSiscomRegProLPtrPrimExistencia,
		      lSiscomRegProLPtrActExistencia,
		      pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);



}

int ErrorConexionVentasExistenciaSiscom(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
			  const char *pchrPtrCampo,
			  SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrPrimVentas=0,
		   *lSiscomRegProLPtrActVentas=0,
		   *lSiscomRegProLPtrPrimExistencia=0,
		   *lSiscomRegProLPtrActExistencia=0,
		   *lSiscomRegProLPtrProductos,
		   *lSiscomRegProLPtrPrimExiVentas=0,
		   *lSiscomRegProLPtrActExiVentas=0;
const char *lchrPtrCveProducto;
LogSiscom("Se proceso consulta con error");
lSiscomRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio",
								  "Productos",
								  pSiscomOpePtrDato);

AgregaRegistroVentaExistencia(&lSiscomRegProLPtrPrimExiVentas,
			      &lSiscomRegProLPtrActExiVentas);

for(;
     lSiscomRegProLPtrProductos;
     lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
{
  lchrPtrCveProducto=SiscomObtenCampoRegistroProLChar("cveproducto",lSiscomRegProLPtrProductos);
   AgregaRegistroCeroVenta(&lSiscomRegProLPtrPrimVentas,
   			   &lSiscomRegProLPtrActVentas,
			   lchrPtrCveProducto);

   
   AgregaRegistroCeroVExistencia(&lSiscomRegProLPtrPrimExistencia,
   			   &lSiscomRegProLPtrActExistencia,
			   lchrPtrCveProducto);

   			
}
SiscomRegistrosAlCampo("Existencia",
			lSiscomRegProLPtrPrimExistencia,
			lSiscomRegProLPtrActExistencia,
			lSiscomRegProLPtrPrimExiVentas);

SiscomRegistrosAlCampo("Ventas",
			lSiscomRegProLPtrPrimVentas,
			lSiscomRegProLPtrActVentas,
			lSiscomRegProLPtrPrimExiVentas);



SiscomRegistrosAlCampo(pchrPtrCampo,
		      lSiscomRegProLPtrPrimExiVentas,
		      lSiscomRegProLPtrActExiVentas,
		      pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
}

SiscomRegistroProL *ProductosRegistradosSiscom(SiscomOperaciones *pSisOpePtrDato)
{
SiscomOperaciones lSisOpeDato=*pSisOpePtrDato;
  SqlProductosSE(&lSisOpeDato);

return SiscomObtenRegistrosCampoRespuesta("Productos",&lSisOpeDato);
 

}
int ErrorConexionVentasExistenciaSiscomT(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
			  const char *pchrPtrCampo,
			  SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrPrimVentas=0,
		   *lSiscomRegProLPtrActVentas=0,
		   *lSiscomRegProLPtrPrimExistencia=0,
		   *lSiscomRegProLPtrActExistencia=0,
		   *lSiscomRegProLPtrProductos,
		   *lSiscomRegProLPtrPrimExiVentas=0,
		   *lSiscomRegProLPtrActExiVentas=0;
const char *lchrPtrCveProducto;
LogSiscom("Se proceso consulta con error");
lSiscomRegProLPtrProductos=ProductosRegistradosSiscom(pSiscomOpePtrDato);

AgregaRegistroVentaExistencia(&lSiscomRegProLPtrPrimExiVentas,
			      &lSiscomRegProLPtrActExiVentas);

for(;
     lSiscomRegProLPtrProductos;
     lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
{
  lchrPtrCveProducto=SiscomObtenCampoRegistroProLChar("cveproducto",lSiscomRegProLPtrProductos);
   AgregaRegistroCeroVenta(&lSiscomRegProLPtrPrimVentas,
   			   &lSiscomRegProLPtrActVentas,
			   lchrPtrCveProducto);

   
   AgregaRegistroCeroVExistencia(&lSiscomRegProLPtrPrimExistencia,
   			   &lSiscomRegProLPtrActExistencia,
			   lchrPtrCveProducto);

   			
}
SiscomRegistrosAlCampo("Existencia",
			lSiscomRegProLPtrPrimExistencia,
			lSiscomRegProLPtrActExistencia,
			lSiscomRegProLPtrPrimExiVentas);
SiscomRegistrosAlCampo("Ventas",
			lSiscomRegProLPtrPrimVentas,
			lSiscomRegProLPtrActVentas,
			lSiscomRegProLPtrPrimExiVentas);
SiscomRegistrosAlCampo(pchrPtrCampo,
		      lSiscomRegProLPtrPrimExiVentas,
		      lSiscomRegProLPtrActExiVentas,
		      pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
}



int ConexionExpendioConsultaSiscom(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
				   const char *pchrPtrCampoParaNombre,
				   SiscomOperaciones *pSiscomOpePtrDato)
{

LogSiscom("******** Consultando Expendio  %s  %s:%s ******* ",
	   SiscomObtenCampoRegistroProLChar("idempresa",pSiscomRegProLPtrMaquinas),
	   SiscomObtenCampoRegistroProLChar("dirip",pSiscomRegProLPtrMaquinas),
	   SiscomObtenCampoRegistroProLChar("puerto",pSiscomRegProLPtrMaquinas));
return 0;
}
char *AgregandoUnaCadena(const char *pchrPtrAgrega,char *pchrPtrCadena)
{
int lintTamano=strlen(pchrPtrAgrega)+strlen(pchrPtrCadena)+1;
pchrPtrCadena=(char *)realloc(pchrPtrCadena,lintTamano);
strcat(pchrPtrCadena,pchrPtrAgrega);
return pchrPtrCadena;
}
		    
char *ClausulaInProductos(SiscomRegistroProL *pSisRegProLPtrProductos,
			 char **pchrPtrClausula)
{
char lchrArrPaso[128];
*pchrPtrClausula=strdup("in(");
for(;
    pSisRegProLPtrProductos;
    pSisRegProLPtrProductos=pSisRegProLPtrProductos->SiscomRegProLPtrSig)
{
    if(pSisRegProLPtrProductos->SiscomRegProLPtrSig) 
    sprintf(lchrArrPaso,
    	    "'%s',",
    	    SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrProductos));
    else
    sprintf(lchrArrPaso,
    	    "'%s'",
    	    SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrProductos));
    *pchrPtrClausula=AgregandoUnaCadena(lchrArrPaso,*pchrPtrClausula);
}
strcat(*pchrPtrClausula,")");
return *pchrPtrClausula;
}
