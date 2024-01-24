#include <ExistenciaExpendios.h>

#include <SqlSiscomElectronica.h>
#include <SqlExistenciaExpendios.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomReplicacion.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


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
char lchrArrBuffer[128];
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
     lSiscomRegProLPtrConsulta=SiscomRegistrosMaquinaConsulta(lchrPtrCampoSistema,
     							  pchrPtrCampoRespConsulta,
							  pSiscomOpePtrDato);
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
int EstadoConsultaSistemaSiscom(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
				const char *pchrPtrCampo,
				SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrExistencia;
const char *lchrPtrIdExpendio;
lchrPtrIdExpendio=SiscomObtenCampoRegistroProLChar("idempresa",pSiscomRegProLPtrMaquinas);
lSiscomRegProLPtrExistencia=SiscomRegistrosAsociadosCampo(lchrPtrIdExpendio,
							  "Existencia",
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
