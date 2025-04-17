#include <SiscomReplicacion.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

/* Lunes 22 de diciembre del 2014 
 * Con la implementacion de la nueva plataforma de trabajo
 * se agrega el manejo de dos conceptos importantes , por 
 * un lado tendremos el servidor web, que la mayoria de las
 * aplicaciones tendran, la matriz y los expendios,  en cada
 * proceso de insercion se debera identificar si la informacion
 * 
 *
 */

int SiscomDatosComunicacionMemoria(const char *pchrPtrMaquina,
				    char **pchrPtrDirIp,
				    int *pintPtrPuerto)
{

 if((*pchrPtrDirIp=(char *)SiscomBuscaDatoRegistros("Servidores",
 					"tipoequipo",
					pchrPtrMaquina,
					"dirip",
					gSiscomRegProLPtrMemoria)))
{
*pintPtrPuerto=SiscomBuscaDatoRegistrosInt("Servidores",
					   "tipoequipo",
					   pchrPtrMaquina,
					   "puerto",
					   gSiscomRegProLPtrMemoria);
return 1;
}
else
return 0;
}
				    
int SiscomReplicaServidorWeb(const char *pchrPtrArgumentoEnvio,
			      char *pchrPtrBuffer,
			      SiscomOperacion pSiscomOpAccionErrorRep,
			      SiscomOperaciones *pSiscomOpPtrDat)
{

/*
 * Aqui se recorre cada una se las sentencias, esto sera util
 * para el caso en que no se pueda realizar la insercion 
 * se debera crear en la base local del servidor, una tabla
 * con la informacion necesaria que permita reenviar las 
 * sentencias sql que no puedieron registrarse
 *
SiscomRegistroProL *lSiscomRegProLPtrDato=SiscomObtenArgumentoPrimAsociadoOperaciones(pchrPtrArgumentoEnvio,
									"SentenciasSql",
									pSiscomOpPtrDat);
SiscomDatosComunicacionMemoria("Web",&lchrPtrDirIp,&lintPuerto);
LogSiscom("Enviando %s %d",lchrPtrDirIp,lintPuerto);
if((lSiscomRegProLPtrDato))
{
for( ;
     lSiscomRegProLPtrDato;
     lSiscomRegProLPtrDato=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrDato))
{
LogSiscom("%s",SiscomObtenCampoRegistroProLChar("Sql",lSiscomRegProLPtrDato));
}

}
*/

return SiscomReplicacionEnvioServidor("Web",
				   pchrPtrArgumentoEnvio,
				   pchrPtrBuffer,
				   pSiscomOpAccionErrorRep,
				   pSiscomOpPtrDat);
}

int SiscomReplicaServidorMatriz(const char *pchrPtrArgumentoEnvio,
			       char *pchrPtrBuffer,
			      SiscomOperacion pSiscomOpAccionErrorRep,
			      SiscomOperaciones *pSiscomOpPtrDat)
{

SiscomReplicacionEnvioServidor("Matriz",
				   pchrPtrArgumentoEnvio,
				   pchrPtrBuffer,
				   pSiscomOpAccionErrorRep,
				   pSiscomOpPtrDat);
}
int SiscomReplicaServidorExpendios(const char *pchrPtrArgumentoEnvio,
			       char *pchrPtrBuffer,
			      SiscomOperacion pSiscomOpAccionErrorRep,
			      SiscomOperaciones *pSiscomOpPtrDat)
{
SiscomReplicacionEnvioServidor("Expendio",
				pchrPtrArgumentoEnvio,
				pchrPtrBuffer,
				pSiscomOpAccionErrorRep,
				pSiscomOpPtrDat);
}

int SiscomReplicaMaquinaLocal(const char *pchrPtrArgumentoEnvio,
			       char *pchrPtrBuffer,
			      SiscomOperacion pSiscomOpAccionErrorRep,
			    	SiscomOperaciones *pSiscomOpPtrDat)
{
return SiscomReplicacionEnvioServidor("MaquinaLocal",
				   pchrPtrArgumentoEnvio,
				   pchrPtrBuffer,
				   pSiscomOpAccionErrorRep,
				   pSiscomOpPtrDat);
}


int SiscomReplicacionEnvioServidor(const char *pchrPtrMaquina,
				    const char *pchrPtrArgumentoEnvio,
				    char *pchrPtrBuffer,
			      		SiscomOperacion pSiscomOpAccionErrorRep,
				    SiscomOperaciones *pSiscomOpPtrDat)
{
char *lchrPtrDirIp;
int lintPuerto;
if(SiscomDatosComunicacionMemoria(pchrPtrMaquina,&lchrPtrDirIp,&lintPuerto))
{
if(SiscomEnviaRegistrosBD(lchrPtrDirIp,
			  lintPuerto,
			  pchrPtrArgumentoEnvio,
			  pchrPtrBuffer,
			pSiscomOpPtrDat))
{
   if(SiscomErrorOperacionBase(pSiscomOpPtrDat))
  {
  if(pSiscomOpAccionErrorRep)
  pSiscomOpAccionErrorRep(pSiscomOpPtrDat); 
  return 0;
  }
  else
  return 1;
}
else
{
LogSiscom("No se pudo conecta a %s:%d",
	  lchrPtrDirIp,
	  lintPuerto);

return 0;
}
}
else
return 0;
}

int SiscomErrorOperacionBase(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrCampoEdoOperacion;
if((lchrPtrCampoEdoOperacion=SiscomObtenCampoRegistroProLChar("EstadoOperacion",
				  pSiscomOpePtrDato->SiscomRegProLPtrPrimRes)))
   return !strcmp("Error",lchrPtrCampoEdoOperacion);
else
{
LogSiscom("No se encontro el Campo \"EstadoOperacion\"");
return 0;
}
}

int SiscomReplicaMaquinasSistema(const char *pchrPtrTipoEquipo,
			         const char *pchrPtrArgumentoEnvio,
			         char *pchrPtrBuffer,
				 SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			         SiscomOperacion pSiscomOpAccionErrorRep,
			    	 SiscomOperaciones *pSiscomOpPtrDat)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrMaquinas;
int lintPuerto;
const char *lchrPtrDirIp;
lSisRegProLPtrMaquinas=SiscomObtenRegistrosCampoProL("Servidores",pSiscomRegProLPtrMemoria);
for(;
    lSisRegProLPtrMaquinas;
    lSisRegProLPtrMaquinas=SiscomSiguienteNodoRegistroProL(lSisRegProLPtrMaquinas))
{
if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrTipoEquipo,"tipoequipo",lSisRegProLPtrMaquinas))
{
  lintPuerto=SiscomObtenCampoRegistroProLInt("puerto",lSisRegProLPtrMaquinas);
  lchrPtrDirIp=SiscomObtenCampoRegistroProLChar("dirip",lSisRegProLPtrMaquinas);
if(SiscomEnviaRegistrosBD(lchrPtrDirIp,
			  lintPuerto,
			  pchrPtrArgumentoEnvio,
			  pchrPtrBuffer,
			pSiscomOpPtrDat))
{
   if(SiscomErrorOperacionBase(pSiscomOpPtrDat))
  {
  if(pSiscomOpAccionErrorRep)
  pSiscomOpAccionErrorRep(pSiscomOpPtrDat); 
  }
}
else
{
LogSiscom("No se pudo conecta a %s:%d",
	  lchrPtrDirIp,
	  lintPuerto);

}
}

}

}
int SiscomServidorPorIdMaquina(const char *pchrPtrIdMaquina,
			       SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			       int *pintPtrPuerto,
			       const char **pchrPtrDirIp)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrMaquinas;
int lintPuerto;
const char *lchrPtrDirIp;
lSisRegProLPtrMaquinas=SiscomObtenRegistrosCampoProL("Servidores",pSiscomRegProLPtrMemoria);
for(;
    lSisRegProLPtrMaquinas;
    lSisRegProLPtrMaquinas=SiscomSiguienteNodoRegistroProL(lSisRegProLPtrMaquinas))
{
if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrIdMaquina,"idmaquina",lSisRegProLPtrMaquinas))
{
  *pintPtrPuerto=SiscomObtenCampoRegistroProLInt("puerto",lSisRegProLPtrMaquinas);
  *pchrPtrDirIp=SiscomObtenCampoRegistroProLChar("dirip",lSisRegProLPtrMaquinas);
  return 1;
}
}

return 0;
}

int SiscomServidorPorTipoMaquina(const char *pchrPtrTipoMaquina,
			       SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			       int *pintPtrPuerto,
			       const char **pchrPtrDirIp,
			       const char **pchrPtrBaseDatos)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrMaquinas;
int lintPuerto;
const char *lchrPtrDirIp;
lSisRegProLPtrMaquinas=SiscomObtenRegistrosCampoProL("Servidores",pSiscomRegProLPtrMemoria);
for(;
    lSisRegProLPtrMaquinas;
    lSisRegProLPtrMaquinas=SiscomSiguienteNodoRegistroProL(lSisRegProLPtrMaquinas))
{
if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrTipoMaquina,"tipoequipo",lSisRegProLPtrMaquinas))
{
  *pintPtrPuerto=SiscomObtenCampoRegistroProLInt("puerto",lSisRegProLPtrMaquinas);
  *pchrPtrDirIp=SiscomObtenCampoRegistroProLChar("dirip",lSisRegProLPtrMaquinas);
  *pchrPtrBaseDatos=SiscomObtenCampoRegistroProLChar("basedatos",lSisRegProLPtrMaquinas);
  return 1;
}
}

return 0;
}


int SiscomReplicaMaquinaSistema(const char *pchrPtrIdMaquina,
			         const char *pchrPtrArgumentoEnvio,
			         char *pchrPtrBuffer,
				 SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			         SiscomOperacion pSiscomOpAccionErrorRep,
			    	 SiscomOperaciones *pSiscomOpPtrDat)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrMaquinas;
int lintPuerto;
const char *lchrPtrDirIp;
lSisRegProLPtrMaquinas=SiscomObtenRegistrosCampoProL("Servidores",pSiscomRegProLPtrMemoria);
for(;
    lSisRegProLPtrMaquinas;
    lSisRegProLPtrMaquinas=SiscomSiguienteNodoRegistroProL(lSisRegProLPtrMaquinas))
{
if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrIdMaquina,"idmaquina",lSisRegProLPtrMaquinas))
{
  lintPuerto=SiscomObtenCampoRegistroProLInt("puerto",lSisRegProLPtrMaquinas);
  lchrPtrDirIp=SiscomObtenCampoRegistroProLChar("dirip",lSisRegProLPtrMaquinas);
if(SiscomEnviaRegistrosBD(lchrPtrDirIp,
			  lintPuerto,
			  pchrPtrArgumentoEnvio,
			  pchrPtrBuffer,
			pSiscomOpPtrDat))
{
   if(SiscomErrorOperacionBase(pSiscomOpPtrDat))
  {
  if(pSiscomOpAccionErrorRep)
  pSiscomOpAccionErrorRep(pSiscomOpPtrDat); 
  }
  return 1;
}
else
{
LogSiscom("No se pudo conecta a %s:%d",
	  lchrPtrDirIp,
	  lintPuerto);
return 0;
}
}
}
}

int SiscomReplicaMaquinaPorCampo(const char *pchrPtrNmbCampo,
				 const char *pchrPtrValorCampo,
			         const char *pchrPtrArgumentoEnvio,
			         char *pchrPtrBuffer,
				 SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			         SiscomOperacion pSiscomOpAccionErrorRep,
			    	 SiscomOperaciones *pSiscomOpPtrDat)
{
SiscomRegistroProL *lSisRegProLPtrMaquinas;
int lintPuerto;
const char *lchrPtrDirIp;
if(!(lSisRegProLPtrMaquinas=SiscomObtenRegistrosCampoProL("Servidores",pSiscomRegProLPtrMemoria)))
LogSiscom("La informacion de de los servidores no trae el campo \"Servidores\"");
else
{
for(;
    lSisRegProLPtrMaquinas;
    lSisRegProLPtrMaquinas=SiscomSiguienteNodoRegistroProL(lSisRegProLPtrMaquinas))
{
if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrValorCampo,pchrPtrNmbCampo,lSisRegProLPtrMaquinas))
{
  lintPuerto=SiscomObtenCampoRegistroProLInt("puerto",lSisRegProLPtrMaquinas);
  lchrPtrDirIp=SiscomObtenCampoRegistroProLChar("dirip",lSisRegProLPtrMaquinas);
if(SiscomEnviaRegistrosBD(lchrPtrDirIp,
			  lintPuerto,
			  pchrPtrArgumentoEnvio,
			  pchrPtrBuffer,
			pSiscomOpPtrDat))
{
   if(SiscomErrorOperacionBase(pSiscomOpPtrDat))
  {
  if(pSiscomOpAccionErrorRep)
  pSiscomOpAccionErrorRep(pSiscomOpPtrDat); 
  }
  return 1;
}
else
{
LogSiscom("No se pudo conecta a %s:%d",
	  lchrPtrDirIp,
	  lintPuerto);
return 0;
}
}
}
}
}
void SiscomConsultasSqlServidorPorIdMaquina(const char *pchrPtrIdServidor,
				     SiscomRegistroProL *pSiscomRegProLPtrMemoria,
				     char *pchrPtrBuffer,
				     SiscomOperaciones *pSiscomOpePtrDatos,
				     const char *pchrPtrFormato,
				     ...)

{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
	 	*lSiscomCamProLPtrPaso,
		*lSiscomCamProLPtrCampo;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;

char *lchrPtrSql;
char *lchrPtrEdoConexion;
char lchrArrBuffer[256];
const char *lchrPtrDirIp;
int lintPuerto;
va_list lvaListInfo;
va_start(lvaListInfo,pchrPtrFormato);
SiscomServidorPorIdMaquina(pchrPtrIdServidor,
			   pSiscomRegProLPtrMemoria,
			   &lintPuerto,
			   &lchrPtrDirIp);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "Operacion,"
		       "EstadoOperacion,",
		       pSiscomOpePtrDatos->chrArrBaseDatos,
		       pSiscomOpePtrDatos->chrArrPuertoBaseDatos,
		       "EjecutaConsulta",
		       (char *)0);
lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaCamposSql(
						pchrPtrFormato,
						pchrPtrBuffer);

SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      &lSiscomRegProLPtrPrim,
		      &lSiscomRegProLPtrAct);
SiscomRegistroProtocoloLog(pchrPtrBuffer,lSiscomRegProLPtrPrim);
while(lSiscomCamProLPtrDato)
{
  lchrPtrSql=va_arg(lvaListInfo,char *);
  SiscomAnexaRegistrosAlCampo(lSiscomCamProLPtrDato->chrPtrNmbCampo,
  			      lSiscomRegProLPtrAct,
			      pchrPtrBuffer,
			      "Sql,",
			      lchrPtrSql);
  lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
va_end(lvaListInfo);
if((pSiscomOpePtrDatos->intSocketAD=SiscomConectateCliente(
				lchrPtrDirIp,
				lintPuerto,
				&lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			   pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			 pchrPtrBuffer,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
close(pSiscomOpePtrDatos->intSocketAD);
}

}

int SiscomConsultasSqlServidorPorIdMaquina3(const char *pchrPtrIdServidor,
					     const char *pchrPtrArgumento,
					     SiscomOperaciones *pSiscomOpePtrDatos,
		int (*SiscomExpendioServidor)(const char *pchrPtrIdServidor,
					     	const char *pchrPtrArgumento,
					        SiscomOperaciones *pSiscomOpePtrDato,
						int *pintPuerto,
						char **pchrPtrDirIp),
					     char *pchrPtrBuffer,
					     const char *pchrPtrFormato,
					     ...)
{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
	 	*lSiscomCamProLPtrPaso,
		*lSiscomCamProLPtrCampo;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;

char *lchrPtrSql;
char *lchrPtrEdoConexion;
char lchrArrBuffer[256];
const char *lchrPtrDirIp;
int lintPuerto;
va_list lvaListInfo;
va_start(lvaListInfo,pchrPtrFormato);
SiscomExpendioServidor(pchrPtrIdServidor,
		       pchrPtrArgumento,
		       pSiscomOpePtrDatos,
		       &lintPuerto,
		       (char **)&lchrPtrDirIp);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "Operacion,"
		       "EstadoOperacion,",
		       pSiscomOpePtrDatos->chrArrBaseDatos,
		       pSiscomOpePtrDatos->chrArrPuertoBaseDatos,
		       "EjecutaConsulta",
		       (char *)0);
lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaCamposSql(
						pchrPtrFormato,
						pchrPtrBuffer);

SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      &lSiscomRegProLPtrPrim,
		      &lSiscomRegProLPtrAct);
while(lSiscomCamProLPtrDato)
{
  lchrPtrSql=va_arg(lvaListInfo,char *);
  SiscomAnexaRegistrosAlCampo(lSiscomCamProLPtrDato->chrPtrNmbCampo,
  			      lSiscomRegProLPtrAct,
			      pchrPtrBuffer,
			      "Sql,",
			      lchrPtrSql);
  lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
va_end(lvaListInfo);
if((pSiscomOpePtrDatos->intSocketAD=SiscomConectateClienteNoBloqueante4(
				lchrPtrDirIp,
				lintPuerto,
				5,
				&lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			   pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			 pchrPtrBuffer,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
close(pSiscomOpePtrDatos->intSocketAD);
return 0;
}
else
return 1;





}



void SiscomConsultasSqlServidorPorIdMaquina2(const char *pchrPtrIdServidor,
				     SiscomRegistroProL *pSiscomRegProLPtrMemoria,
				     char *pchrPtrBuffer,
				     char **pchrPtrNombres,
				     char **pchrPtrConsultas,
				     SiscomOperaciones *pSiscomOpePtrDatos)

{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
		*lSiscomCamProLPtrDatoAct=0,
	 	*lSiscomCamProLPtrPaso,
		*lSiscomCamProLPtrCampo;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;

char *lchrPtrSql;
char *lchrPtrEdoConexion;
char lchrArrBuffer[256];
const char *lchrPtrDirIp;
int lintPuerto;
SiscomServidorPorIdMaquina(pchrPtrIdServidor,
			   pSiscomRegProLPtrMemoria,
			   &lintPuerto,
			   &lchrPtrDirIp);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "Operacion,"
		       "EstadoOperacion,",
		       pSiscomOpePtrDatos->chrArrBaseDatos,
		       pSiscomOpePtrDatos->chrArrPuertoBaseDatos,
		       "EjecutaConsulta",
		       (char *)0);
lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaRegistro(pchrPtrNombres,
								&lSiscomCamProLPtrDato,
								&lSiscomCamProLPtrDatoAct);

SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      &lSiscomRegProLPtrPrim,
		      &lSiscomRegProLPtrAct);
while(*pchrPtrConsultas)
{
  SiscomAnexaRegistrosAlCampo(lSiscomCamProLPtrDato->chrPtrNmbCampo,
  			      lSiscomRegProLPtrAct,
			      pchrPtrBuffer,
			      "Sql,",
			      *pchrPtrConsultas);
  lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
  pchrPtrConsultas++;
}
if((pSiscomOpePtrDatos->intSocketAD=SiscomConectateCliente(
				lchrPtrDirIp,
				lintPuerto,
				&lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			   pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			 pchrPtrBuffer,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
close(pSiscomOpePtrDatos->intSocketAD);
}

}


void SiscomFormaRegistroAsociadoConsultaSistema(const char *pchrPtrTipoEquipo,
					        const char *pchrPtrCampoParaNombre,
						SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
						char *pchrPtrBuffer,
						SiscomOperaciones *pSiscomOpePtrDatos)
{
SiscomCampoProL *lSiscomCampProLPtrPrim=0,
		 *lSiscomCampProLPtrAct=0;
const char *lchrPtrCampo;
 for(;
 	pSiscomRegProLPtrMaquinas;
	pSiscomRegProLPtrMaquinas=SiscomSiguienteNodoRegistroProL(pSiscomRegProLPtrMaquinas))
if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrTipoEquipo,"tipoequipo",pSiscomRegProLPtrMaquinas))
{
lchrPtrCampo=SiscomObtenCampoRegistroProLChar(pchrPtrCampoParaNombre,pSiscomRegProLPtrMaquinas);
SiscomNodoCampoPro2(lchrPtrCampo,
		    0,
		    &lSiscomCampProLPtrPrim,
		    &lSiscomCampProLPtrAct);
}
SiscomNodoRegistroPro(lSiscomCampProLPtrPrim,
		      &pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes,
		      &pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
}
void SiscomAsignaInformacionBaseDatos(SiscomRegistroProL *pSiscomRegProLPtrEnvio,
				      SiscomRegistroProL *pSiscomRegProLPtrMaquina)
{
const char *lchrPtrBaseDatos;

if((lchrPtrBaseDatos=SiscomObtenCampoRegistroProLChar("basedatos",pSiscomRegProLPtrMaquina)))
SiscomActualizaCampo2("BaseDatos",(char *)lchrPtrBaseDatos,pSiscomRegProLPtrEnvio);
}
/* Miercoles 14 de diciembre del 2016 
 * Esta funcion envia las consultas a todos los servidores 
 * almacenados en pSiscomRegProLPtrMemoria, el problema que tiene
 * por ejemplo para el caso del Sistema de Siscom Electronica, es 
 * que la base de datos se llama diferente en cada expendio, por lo
 * que hay que desarrollar otra funcion que tome de pSiscomRegProLPtrMemoria 
 * los datos de la base de datos 
 *
 * Martes 15 de agosto del 2017
 * Ciudad de Mexico
 * Se cambia el prototipo de la funcion para 
 * tener control de los errores que se generan
 * en el proceso de consulta a los servidores
 * 
 * Los codigos identificados al momento son 
 * los siguientes:
 * 
 * 1 Alguno de los Servidores no esta disponible
 *
 * Al final, no creo que tenga sentido hacer esto ..
 *
 *   
 *
 *
 */

int SiscomConsultasSqlSistema(const char *pchrPtrTipoEquipo,
			      const char *pchrPtrCampoParaNombre,
			      int pintTiempoEspera,
			      SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			      SiscomLogConsultaSistema pSiscomConexion,
			      SiscomLogConsultaSistema pSiscomErrorConsulta,
			      SiscomLogConsultaSistema pSiscomMensajesConsulta,
			      char *pchrPtrBuffer,
			      SiscomOperaciones *pSiscomOpePtrDatos,
			      const char *pchrPtrFormato,
			      ...)
{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
	 	*lSiscomCamProLPtrPaso,
		*lSiscomCamProLPtrCampo;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
SiscomRegistroProL *lSisRegProLPtrMaquinas,
		   *lSiscomRegProLPtrRegresoPrim=0,
		   *lSiscomRegProLPtrRegresoAct=0;
char *lchrPtrSql;
char *lchrPtrEdoConexion;
const char *lchrPtrDirIp,*lchrPtrCampoParaNombre;
int lintPuerto;
va_list lvaListInfo;
va_start(lvaListInfo,pchrPtrFormato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "Operacion,"
		       "EstadoOperacion,",
		       pSiscomOpePtrDatos->chrArrBaseDatos,
		       pSiscomOpePtrDatos->chrArrPuertoBaseDatos,
		       "EjecutaConsulta",
		       (char *)0);
lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaCamposSql(
						pchrPtrFormato,
						pchrPtrBuffer);
SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      &lSiscomRegProLPtrPrim,
		      &lSiscomRegProLPtrAct);
while(lSiscomCamProLPtrDato)
{
  lchrPtrSql=va_arg(lvaListInfo,char *);
  SiscomAnexaRegistrosAlCampo(lSiscomCamProLPtrDato->chrPtrNmbCampo,
  			      lSiscomRegProLPtrAct,
			      pchrPtrBuffer,
			      "Sql,",
			      lchrPtrSql);
  lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}
va_end(lvaListInfo);
lSisRegProLPtrMaquinas=SiscomObtenRegistrosCampoProL("Servidores",pSiscomRegProLPtrMemoria);
SiscomFormaRegistroAsociadoConsultaSistema(pchrPtrTipoEquipo,
					   pchrPtrCampoParaNombre,
					   lSisRegProLPtrMaquinas,
					   pchrPtrBuffer,
					   pSiscomOpePtrDatos);
for(;
    lSisRegProLPtrMaquinas;
    lSisRegProLPtrMaquinas=SiscomSiguienteNodoRegistroProL(lSisRegProLPtrMaquinas))
{
lchrPtrCampoParaNombre=SiscomObtenCampoRegistroProLChar(pchrPtrCampoParaNombre,lSisRegProLPtrMaquinas); 
if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrTipoEquipo,"tipoequipo",lSisRegProLPtrMaquinas))
{
  lintPuerto=SiscomObtenCampoRegistroProLInt("puerto",lSisRegProLPtrMaquinas);
  lchrPtrDirIp=SiscomObtenCampoRegistroProLChar("dirip",lSisRegProLPtrMaquinas);
  SiscomAsignaInformacionBaseDatos(lSiscomRegProLPtrPrim,lSisRegProLPtrMaquinas);
  if(pSiscomConexion)
  pSiscomConexion(lSisRegProLPtrMaquinas,lchrPtrCampoParaNombre,pSiscomOpePtrDatos);
  if((pSiscomOpePtrDatos->intSocketAD=SiscomConectateClienteNoBloqueante4(
				lchrPtrDirIp,
				lintPuerto,
				pintTiempoEspera,
				&lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocketAD, pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			 pchrPtrBuffer,
			 &lSiscomRegProLPtrRegresoPrim,
			 &lSiscomRegProLPtrRegresoAct);

SiscomRegistrosAlCampo(lchrPtrCampoParaNombre,
			lSiscomRegProLPtrRegresoPrim,
			lSiscomRegProLPtrRegresoAct,
			pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes);
close(pSiscomOpePtrDatos->intSocketAD);
if(pSiscomMensajesConsulta)
{
   if(pSiscomMensajesConsulta(lSisRegProLPtrMaquinas,lchrPtrCampoParaNombre,pSiscomOpePtrDatos))
    if(pSiscomErrorConsulta)
     pSiscomErrorConsulta(lSisRegProLPtrMaquinas,lchrPtrCampoParaNombre,pSiscomOpePtrDatos);
}
}
else
{
 if(pSiscomErrorConsulta)
    pSiscomErrorConsulta(lSisRegProLPtrMaquinas,lchrPtrCampoParaNombre,pSiscomOpePtrDatos);
}

lSiscomRegProLPtrRegresoPrim=lSiscomRegProLPtrRegresoAct=0;
}
}
}


SiscomRegistroProL *SiscomRegistrosMaquinaConsulta(const char *pchrPtrDatoConsultar,
						   const char *pchrPtrNombreConsulta,
						   SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrRegreso,
		   *lSiscomRegProLPtrInformacion;
const char *lchrPtrCampo;
LogSiscom("Aqui");
if(pSiscomOpePtrDato->SiscomRegProLPtrPrimRes)
{
LogSiscom("Aqui");
  lSiscomRegProLPtrInformacion=SiscomObtenRegistrosCampoProL(pchrPtrDatoConsultar,
  							     pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
LogSiscom("Aqui %x",lSiscomRegProLPtrInformacion);
   if(lSiscomRegProLPtrInformacion)
  lSiscomRegProLPtrRegreso=SiscomObtenRegistrosCampoProL(pchrPtrNombreConsulta,lSiscomRegProLPtrInformacion);
  else
  return 0;

  return lSiscomRegProLPtrRegreso;
}
}

const char *SiscomCampoServidorPorId(const char *pchrPtrCampoRegreso,
				     const char *pchrPtrCampo,
				     const char *pchrPtrValorCampo,
				     const char *pchrPtrArgumento,
				     const char *pchrPtrAsociado,
				     SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrServidores;
const char *lchrPtrRegreso;
if((lSisRegProLPtrServidores=SiscomObtenArgumentoPrimAsociadoOperaciones(
						pchrPtrArgumento,
						pchrPtrAsociado,
						pSiscomOpePtrDato)))
{
for(;
	lSisRegProLPtrServidores;
	lSisRegProLPtrServidores=lSisRegProLPtrServidores->SiscomRegProLPtrSig)
{
if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrValorCampo,pchrPtrCampo,lSisRegProLPtrServidores))
{
  if((lchrPtrRegreso=SiscomObtenCampoRegistroProLChar(pchrPtrCampoRegreso,lSisRegProLPtrServidores)))
  return lchrPtrRegreso;
}
}
return 0;
}
}
