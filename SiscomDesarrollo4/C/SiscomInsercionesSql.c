#include <SiscomInsercionesSql.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomDesarrolloMacros.h>
#include <unistd.h>
void SiscomAgregaArgumentoInsercionSql2(const char *pchrPtrNombre,
					char *pchrPtrBuffer,
					SiscomOperaciones *pSiscomOpePtrDat)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "SentenciasSql,"
		       "BaseDatos,"
		       "Puerto,"
		       "Operacion,"
		       "EstadoOperacion,",
		       (char *)0,
		       pSiscomOpePtrDat->chrArrBaseDatos,
		       pSiscomOpePtrDat->chrArrPuertoBaseDatos,
		       "EjecutaOperacion",
		       (char *)0); 
SiscomAgregaArgumentoOperacion(pchrPtrNombre,
			       lSiscomRegProLPtrPrim,
			       lSiscomRegProLPtrAct,
			       pSiscomOpePtrDat);



}
void SiscomAgregaArgumentoInsercionSql(const char *pchrPtrNombre,
				       const char *pchrPtrBaseDatos,
				       const char *pchrPtrPuertoDB,
				       char *pchrPtrBuffer,
				       SiscomOperaciones *pSiscomOperPtrDat)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "SentenciasSql,"
		       "BaseDatos,"
		       "Puerto,"
		       "Operacion,"
		       "EstadoOperacion,",
		       (char *)0,
		       pchrPtrBaseDatos,
		       pchrPtrPuertoDB,
		       "EjecutaOperacion",
		       (char *)0); 
SiscomAgregaArgumentoOperacion(pchrPtrNombre,
			       lSiscomRegProLPtrPrim,
			       lSiscomRegProLPtrAct,
			       pSiscomOperPtrDat);
}

void SiscomAgregaSentenciasSqlDelAsociado(
		const char *pchrPtrArgumento,
		const char *pchrPtrAsociado,
		char *pchrPtrBuffer,
		char *pchrPtrBufferSql,
		SiscomOperaciones *pSiscomOperPtrDat,
		void (SiscomSql)(SiscomOperaciones *,SiscomRegistroProL *,char *))
{
SiscomRegistroProL *lSiscomRegProLPtrSqlAct;
SiscomRegistroProL *lSiscomRegProLPtrAsociado;
if((lSiscomRegProLPtrSqlAct=SiscomObtenArgumentoActOperaciones(pchrPtrArgumento,
							   pSiscomOperPtrDat)))
{
if((lSiscomRegProLPtrAsociado=SiscomObtenRegistrosCampoProL(
				 pchrPtrAsociado,
				 pSiscomOperPtrDat->SiscomRegProLPtrActEnt)))
{
while(lSiscomRegProLPtrAsociado)
{
  SiscomSql(pSiscomOperPtrDat,lSiscomRegProLPtrAsociado,pchrPtrBufferSql);
  SiscomAnexaRegistrosAlCampo(
  	"SentenciasSql",
	lSiscomRegProLPtrSqlAct,
	pchrPtrBuffer,
	"Sql,"
	"Estado,",
	pchrPtrBufferSql,
	"");
  lSiscomRegProLPtrAsociado=lSiscomRegProLPtrAsociado->SiscomRegProLPtrSig;
}
}
else
LogSiscom("El Campo:%s no forma parte del Registro",pchrPtrAsociado);
}
else
LogSiscom("El Argumento %s,NO Existe o esta vacio ",pchrPtrArgumento);
}


void SiscomAgregaSentenciasSqlCampoAsociadoAsociado(
		const char *pchrPtrArgumento,
		const char *pchrPtrAsociado,
		const char *pchrPtrAsociado1,
		const char *pchrPtrCampo,
		char *pchrPtrBuffer,
		char *pchrPtrBufferSql,
		SiscomOperaciones *pSiscomOperPtrDat,
		void (SiscomSql)(SiscomOperaciones *,SiscomRegistroProL *,char *))
{
SiscomRegistroProL *lSiscomRegProLPtrSqlAct;
SiscomRegistroProL *lSiscomRegProLPtrAsociado;
if((lSiscomRegProLPtrSqlAct=SiscomObtenArgumentoActOperaciones(pchrPtrArgumento,
							   pSiscomOperPtrDat)))
{
if((lSiscomRegProLPtrAsociado=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion(
						pchrPtrAsociado,
						pchrPtrAsociado1,
						pchrPtrCampo,
						pSiscomOperPtrDat)))
{
while(lSiscomRegProLPtrAsociado)
{
  SiscomSql(pSiscomOperPtrDat,lSiscomRegProLPtrAsociado,pchrPtrBufferSql);
  SiscomAnexaRegistrosAlCampo(
  	"SentenciasSql",
	lSiscomRegProLPtrSqlAct,
	pchrPtrBuffer,
	"Sql,"
	"Estado,",
	pchrPtrBufferSql,
	"");
  lSiscomRegProLPtrAsociado=lSiscomRegProLPtrAsociado->SiscomRegProLPtrSig;
}
}
else
LogSiscom("El Campo:%s no forma parte del Registro",pchrPtrAsociado);
}
else
LogSiscom("El Argumento %s,NO Existe o esta vacio ",pchrPtrArgumento);
}


/* Lunes 5 de Enero del 2015 
 * Toma el registro actual de pSiscomOpePtrDat->SiscomRegProLPtrActEnt 
 * y busca el campo pchrPtrCampo, para obtener los registros asociados
 * al campo pchrPtrAsociado, regresando el apuntador con la informacion
 */
void SiscomAgregaSentenciasSqlCampoAsociado(
		const char *pchrPtrArgumento,
		const char *pchrPtrCampo,
		const char *pchrPtrAsociado,
		char *pchrPtrBuffer,
		char *pchrPtrBufferSql,
		SiscomOperaciones *pSiscomOperPtrDat,
		void (SiscomSql)(SiscomOperaciones *,SiscomRegistroProL *,char *))
{
SiscomRegistroProL *lSiscomRegProLPtrSqlAct;
SiscomRegistroProL *lSiscomRegProLPtrAsociado;
*pchrPtrBufferSql=0;
if((lSiscomRegProLPtrSqlAct=SiscomObtenArgumentoActOperaciones(pchrPtrArgumento,
							   pSiscomOperPtrDat)))
{
if((lSiscomRegProLPtrAsociado=SiscomRegistrosAsociadosCampo(pchrPtrCampo,
				 pchrPtrAsociado,
				 pSiscomOperPtrDat->SiscomRegProLPtrActEnt)))
{
while(lSiscomRegProLPtrAsociado)
{
  SiscomSql(pSiscomOperPtrDat,lSiscomRegProLPtrAsociado,pchrPtrBufferSql);
  if(*pchrPtrBufferSql)
  SiscomAnexaRegistrosAlCampo(
  	"SentenciasSql",
	lSiscomRegProLPtrSqlAct,
	pchrPtrBuffer,
	"Sql,"
	"Estado,",
	pchrPtrBufferSql,
	"");
  lSiscomRegProLPtrAsociado=lSiscomRegProLPtrAsociado->SiscomRegProLPtrSig;
}
}
else
LogSiscom("El Campo:%s no forma parte del Registro",pchrPtrAsociado);
}
else
LogSiscom("El Argumento %s, no esta en los argumentos generados",pchrPtrArgumento);
}

/*  Queretaro Lunes 24 de Marzo del 2015
 *
 * Toma cada uno de los registros de pSiscomRegProLPtrDatos ,
 * invoca a SiscomSql, agregando cada cadena a pchrPtrArgumento
 *
 */
void SiscomAgregaSentenciasSqlRegistros(const char *pchrPtrArgumento,
					char *pchrPtrBuffer,
					char *pchrPtrBufferSql,
					SiscomRegistroProL *pSiscomRegProLPtrDatos,
					SiscomOperaciones *pSiscomOpePtrDat,
					void (SiscomSql)(SiscomOperaciones *,SiscomRegistroProL *,char *))
{
SiscomRegistroProL *lSiscomRegProLPtrSqlAct;
SiscomRegistroProL *lSiscomRegProLPtrAsociado;
if((lSiscomRegProLPtrSqlAct=SiscomObtenArgumentoActOperaciones(pchrPtrArgumento,
							   pSiscomOpePtrDat)))
{
while(pSiscomRegProLPtrDatos)
{
  SiscomSql(pSiscomOpePtrDat,pSiscomRegProLPtrDatos,pchrPtrBufferSql);
  SiscomAnexaRegistrosAlCampo(
  	"SentenciasSql",
	lSiscomRegProLPtrSqlAct,
	pchrPtrBuffer,
	"Sql,"
	"Estado,",
	pchrPtrBufferSql,
	"");
  pSiscomRegProLPtrDatos=pSiscomRegProLPtrDatos->SiscomRegProLPtrSig;
}
}
else
LogSiscom("El Argumento %s, no esta en los argumentos generados",pchrPtrArgumento);
}

void SiscomAgregaSentenciaSqlArgumento(
	const char *pchrPtrArgumentoSql,
	const char *pchrPtrArgumento,
	char *pchrPtrBuffer,
	char *pchrPtrBufferSql,
	SiscomOperaciones *pSisOpePtrDato,
	void (SiscomSql)(SiscomOperaciones *,SiscomRegistroProL *,char *))
{
SiscomRegistroProL *lSiscomRegProLPtrSqlAct;
SiscomRegistroProL *lSisRegProLPtrArgumento;
if((lSiscomRegProLPtrSqlAct=SiscomObtenArgumentoActOperaciones(pchrPtrArgumentoSql,
							   pSisOpePtrDato)))
{
if((lSisRegProLPtrArgumento=SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,pSisOpePtrDato)))
{
	while(lSisRegProLPtrArgumento)
	{
  		SiscomSql(pSisOpePtrDato,lSisRegProLPtrArgumento,pchrPtrBufferSql);
  		SiscomAnexaRegistrosAlCampo("SentenciasSql",
					    lSiscomRegProLPtrSqlAct,
					    pchrPtrBuffer,
					    "Sql,"
					    "Estado,",
					    pchrPtrBufferSql,
					   "");
  lSisRegProLPtrArgumento=lSisRegProLPtrArgumento->SiscomRegProLPtrSig;
}
}
else
LogSiscom("El Argumento %s, no esta en los argumentos generados",pchrPtrArgumento);

}
else
LogSiscom("El argumento SQL %s no esta ",pchrPtrArgumentoSql);

}


void SiscomEnviaRegistrosAlServidorBD(const char *pchrPtrArgumento,
				      char *pchrPtrBuffer,
				      SiscomOperaciones *pSiscomOpPtrDat)
{
int lintSocket;
char *lchrPtrEdoConexion;
char lchrArrDirIpSvrAccesoDatos[28];
SiscomRegistroProL *lSiscomRegProLEnvio;
if((lintSocket=SiscomConectateCliente(
			pSiscomOpPtrDat->chrArrDirIpSvrAccesoDatos,
			pSiscomOpPtrDat->intPuertoSvrAccesoDatos,
			&lchrPtrEdoConexion))>0)
{
if((lSiscomRegProLEnvio=SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,pSiscomOpPtrDat)))
{
SiscomEnviaRegistrosSocket(lintSocket,
			   pchrPtrBuffer,
			   lSiscomRegProLEnvio);
SiscomLeeRegistrosSocket(lintSocket,
                         pchrPtrBuffer,
			 &pSiscomOpPtrDat->SiscomRegProLPtrPrimRes,
			 &pSiscomOpPtrDat->SiscomRegProLPtrActRes);
}
else
LogSiscom("No se encontro el argumento:%s",pchrPtrArgumento);
}
else
LogSiscom("NO se pudo conectar al servidor %s:%d",
	  lchrArrDirIpSvrAccesoDatos,
	  SiscomVariableIniAInt("PuertoSvrAccesoDatos",&gSiscomDatIni));
close(lintSocket);
}

void SiscomEnviaRegistrosAlServidorBD2(SiscomRegistroProL *pSisRegProLPtrDat,
				      char *pchrPtrBuffer,
				      SiscomOperaciones *pSiscomOpPtrDat)
{
int lintSocket;
char *lchrPtrEdoConexion;
char lchrArrDirIpSvrAccesoDatos[28];
SiscomVariableIniAChar("DirIpSvrAccesoDatos",
			&gSiscomDatIni,
			lchrArrDirIpSvrAccesoDatos);
if((lintSocket=SiscomConectateCliente(
			lchrArrDirIpSvrAccesoDatos,	
			SiscomVariableIniAInt("PuertoSvrAccesoDatos",&gSiscomDatIni),
			&lchrPtrEdoConexion))>0)
{
if(pSisRegProLPtrDat)
SiscomEnviaRegistrosSocket(lintSocket,
			   pchrPtrBuffer,
			   pSisRegProLPtrDat);
else
LogSiscom("Registro vacio");
}
else
LogSiscom("NO se pudo conectar al servidor %s:%d",
	  lchrArrDirIpSvrAccesoDatos,
	  SiscomVariableIniAInt("PuertoSvrAccesoDatos",&gSiscomDatIni));

close(lintSocket);


}
/* Martes 23 de diciembre del 2014
 * En el esquema actual de trabajo, en el cual 
 * la base de datos debera contener informacion 
 * en varios servidores, se desarrolla el concepto de 
 * replicacion, por lo que la insercion a la 
 * base de datos se realiza a varios servidores
 */
int SiscomEnviaRegistrosBD(const char *pchrPtrDirIp,
			    int pintPuerto,
			    const char *pchrPtrArgumento,
			    char *pchrPtrBuffer,
			    SiscomOperaciones *pSiscomOpPtrDat)
{
int lintSocket;
char *lchrPtrEdoConexion=0;
int lintRegreso=0;
SiscomRegistroProL *lSiscomRegProLEnvio;
if((lintSocket=SiscomConectateClienteNoBloqueante(
			pchrPtrDirIp,	
			pintPuerto,
			5,
			&lchrPtrEdoConexion))>0)
{
  if((lSiscomRegProLEnvio=SiscomObtenArgumentoPrimOperaciones(pchrPtrArgumento,pSiscomOpPtrDat)))
 {
	SiscomEnviaRegistrosSocket(lintSocket,
			   pchrPtrBuffer,
			   lSiscomRegProLEnvio);
	SiscomLeeRegistrosSocket(lintSocket,
                         pchrPtrBuffer,
			 &pSiscomOpPtrDat->SiscomRegProLPtrPrimRes,
			 &pSiscomOpPtrDat->SiscomRegProLPtrActRes);
       lintRegreso=1;
 }
  else
  LogSiscom("No se encontro el argumento:%s",pchrPtrArgumento);
}
else
LogSiscom("NO se pudo conectar al servidor %s:%d",
	  pchrPtrDirIp,
	  pintPuerto);
close(lintSocket);
return lintRegreso;
}


void SiscomRegistroEnvioBaseDatos(const char *pchrPtrBaseDatos,
				  const char *pchrPtrPuertoBase,
				  const char *pchrPtrOperacion,
				  char *pchrPtrBuffer,
				  SiscomRegistroProL **pSiscomRegProLPtrPrim,
				  SiscomRegistroProL **pSiscomRegProLPtrAct)
{
    SiscomAnexaRegistroPro(pSiscomRegProLPtrPrim,
    			   pSiscomRegProLPtrAct,
			  pchrPtrBuffer,
			  "SentenciasSql,"
			  "BaseDatos,"
			  "Puerto,"
			  "Operacion,"
			  "EstadoOperacion,",
			  (char *)0,
			  pchrPtrBaseDatos,
			  pchrPtrPuertoBase,
			  pchrPtrOperacion,
			 (char *)0);
}

void SiscomRegistroASentenciasSql(const char *pchrPtrSql,
				  const char *pchrPtrEstado,
				  char *pchrPtrBuffer,
				  SiscomRegistroProL *pSiscomRegProLPtrAct)
{
     SiscomAnexaRegistrosAlCampo("SentenciasSql",
     				 pSiscomRegProLPtrAct,
				 pchrPtrBuffer,
				 "Sql,Estado,",
				 pchrPtrSql,
				 pchrPtrEstado);
}

