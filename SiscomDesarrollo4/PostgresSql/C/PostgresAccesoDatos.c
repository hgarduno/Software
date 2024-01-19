#include <PostgresAccesoDatos.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
/* Miercoles 9 de Mayo 2012
 * Se debera  plantear una area comun global para gestionar 
 * la comunicacion , por ejemplo el postgres utiliza PGConnect 
 * y en general todo lo que se necesite para gestionar el acceso
 * a la base de datos
 *
 * CDMX a 9 de Diciembre del 2022 
 *
 * Para la integracion con las consultas de la tienda en linea , y 
 * se agregan los parametros de Servidor remoto de base de datos
 * usuario y password en la conexion a la base
 */

char *SiscomConectateBD(PostgresSql *pPosSqlPtrRegreso,
			const char *pchrPtrPuertoBaseDatos,
			const char *pchrPtrBaseDatos,
			const char *pchrPtrServidorBD,
			const char *pchrPtrUsuario,
			const char *pchrPtrPassword)
{
PGresult *lPGresPtrRegreso;
char *lchrPtrRegreso=0;
/*
LogSiscom("Conectandose a :%s %s",
	 pchrPtrPuertoBaseDatos,
	 pchrPtrBaseDatos);
*/
/*
 *  CDMX 9 de Diciembre del 2022 
 *  Para realizar la integracion con la tienda en linea, y pueda gestionar las 
 *  conexiones a la base de datos del servidor de la tienda en linea , modifico
 *  la llamada a la conexion de la base de datos
pPosSqlPtrRegreso->PGConPtrConexion=PQsetdb(0,
  					      pchrPtrPuertoBaseDatos,
					      0,
					      0,
					      pchrPtrBaseDatos);

*/
pPosSqlPtrRegreso->PGConPtrConexion=PQsetdbLogin(pchrPtrServidorBD,
						 pchrPtrPuertoBaseDatos,
						 0,
						 0,
						 pchrPtrBaseDatos,
						 pchrPtrUsuario,
						 pchrPtrPassword);
if(PQstatus(pPosSqlPtrRegreso->PGConPtrConexion)==CONNECTION_BAD)
{
  lchrPtrRegreso=PQerrorMessage(pPosSqlPtrRegreso->PGConPtrConexion);
  LogSiscom("%s",lchrPtrRegreso);

}

return lchrPtrRegreso;
}



const char *PostgresEjecutaComando(PGconn *pPGCPtrConexion,
				   const char *pchrPtrComandoSQL,
				   int pintEvaluaEstatus,
				   PGresult **pPGRRegreso)
{
const char *lchrPtrRegreso=0;
	*pPGRRegreso=PQexec(pPGCPtrConexion,
			    pchrPtrComandoSQL);

	if(PQresultStatus(*pPGRRegreso)!=PGRES_COMMAND_OK)
	{
		if(pintEvaluaEstatus) 
	     	       lchrPtrRegreso=PQerrorMessage(pPGCPtrConexion);
	}
	return lchrPtrRegreso;
}


const char *PostgresEjecutaConsulta(PGconn *pPGCPtrConexion,
				    const char *pchrPtrTipoCursor,
				      const char *pchrPtrNmbConsulta,
				      const char *pchrPtrConsulta,
				      int *pintPtrNumColumnas,
				      int *pintPtrNumReg,
				      PGresult **pPGRPtrResul)
{
const char *lchrPtrRegreso=0;
char *lchrPtrCadConsulta;
char lchrArrNmbCursor[256];
char lchrArrFetch[256];
lchrPtrCadConsulta=(char *)malloc(strlen(pchrPtrConsulta)+256);

	if(!(lchrPtrRegreso=PostgresEjecutaComando(pPGCPtrConexion,
						       "begin",
							1,
						       pPGRPtrResul)))
	{
	  sprintf(lchrArrNmbCursor,
		  "Cursor%s",pchrPtrNmbConsulta);
	  sprintf(lchrPtrCadConsulta,
		  "declare %s %s cursor for %s",
		  lchrArrNmbCursor,
		  pchrPtrTipoCursor ? pchrPtrTipoCursor : "" ,
		  pchrPtrConsulta);
              
	  sprintf(lchrArrFetch,
		  "fetch all in %s",
		  lchrArrNmbCursor);
	   PQclear(*pPGRPtrResul);
	  if(!(lchrPtrRegreso=PostgresEjecutaComando(pPGCPtrConexion,
					  		 lchrPtrCadConsulta,
							 1,
							 pPGRPtrResul)))
	  {
	      PQclear(*pPGRPtrResul);
	      LogSiscom("(%s)\n%s",
	      		 pchrPtrNmbConsulta,
	      		 lchrPtrCadConsulta);
	     if(!(lchrPtrRegreso=PostgresEjecutaComando(pPGCPtrConexion,
					  		 lchrArrFetch,
							 0,
							 pPGRPtrResul)))
	     {
	        *pintPtrNumColumnas=PQnfields(*pPGRPtrResul);
		*pintPtrNumReg=PQntuples(*pPGRPtrResul);
		return lchrPtrRegreso;
	     }
	     else
	     {
		LogSiscom( "%s [Fallo %s]",lchrPtrRegreso,lchrArrFetch);
	     return lchrPtrRegreso;
	     }
	  }
	  else
	  {
		LogSiscom("Consulta:%s \n\
			   SQL [%s]",
			lchrPtrRegreso,
			lchrPtrCadConsulta);

	     return lchrPtrRegreso;
	  }
	}
	else
	{
	     LogSiscom("%s",lchrPtrRegreso);
	     return lchrPtrRegreso;
	}
    
}

void *SiscomConsultaBD(int pintSocket,
			void *pvidPtrAncla,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct)
{
char lchrArrBuffer[4192];
char *lchrPtrEdoConexion;
PostgresSql lPosSqlRegreso;
const char *lchrPtrBaseDatos;
const char *lchrPtrPuertoBaseDatos,
	   *lchrPtrServidorBD=0,
	   *lchrPtrUsuario=0,
	   *lchrPtrPassword=0;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
lchrPtrBaseDatos=SiscomCampoRegistro("BaseDatos",pSiscomRegProLPtrPrim);
lchrPtrPuertoBaseDatos=SiscomCampoRegistro("PuertoBaseDatos",pSiscomRegProLPtrPrim);
lchrPtrServidorBD=SiscomCampoRegistro("ServidorBaseDatos",pSiscomRegProLPtrPrim);
lchrPtrUsuario=SiscomCampoRegistro("UsuarioBaseDatos",pSiscomRegProLPtrPrim);
lchrPtrPassword=SiscomCampoRegistro("PasswordBaseDatos",pSiscomRegProLPtrPrim);
if(!(lchrPtrEdoConexion=SiscomConectateBD(&lPosSqlRegreso,
					 lchrPtrPuertoBaseDatos,
					 lchrPtrBaseDatos,
					 lchrPtrServidorBD,
					 lchrPtrUsuario,
					 lchrPtrPassword)))
{
SiscomObtenRegistrosConsulta(&lPosSqlRegreso,
			     0,
			     pSiscomRegProLPtrAct,
			     &lSiscomRegProLPtrPrim,
			     &lSiscomRegProLPtrAct);
SiscomEnviaRegistrosSocket(pintSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
PQfinish(lPosSqlRegreso.PGConPtrConexion);
}
else
LogSiscom("No se conecto a:%s Error(%s)",lchrPtrBaseDatos,lchrPtrEdoConexion);
}
void GeneraNombreConsulta(const SiscomCampoProL *pSiscomCamProLPtrDat,
			  char *pchrPtrNmbConsulta)
{
sprintf(pchrPtrNmbConsulta,"Sql%s",pSiscomCamProLPtrDat->chrPtrNmbCampo);
}
char *SiscomObtenRegistrosConsulta(PostgresSql *pPosSqlPtrRegreso,
				   const char *pchrPtrTipoCursor,
				   const SiscomRegistroProL *pSiscomRegProLPtrAct,
				   SiscomRegistroProL **pSiscomRegProLPtrPrimReg,
				   SiscomRegistroProL **pSiscomRegProLPtrActReg)
{
SiscomCampoProL *lSiscomCamProLPtrDato;
SiscomCampoProL *lSiscomCamProLPtrRegreso;
const char *lchrPtrSql;
char lchrArrNmbConsulta[256];
lSiscomCamProLPtrDato=pSiscomRegProLPtrAct->SiscomCamProLPtrDato;
lSiscomCamProLPtrRegreso=SiscomDuplicaEstructuraRegistro(pSiscomRegProLPtrAct);
SiscomNodoRegistroPro(lSiscomCamProLPtrRegreso,
		      pSiscomRegProLPtrPrimReg,
		      pSiscomRegProLPtrActReg);
while(lSiscomCamProLPtrDato)
{
  GeneraNombreConsulta(lSiscomCamProLPtrDato,lchrArrNmbConsulta);
  lchrPtrSql=SiscomCampoRegistroAsociado(lSiscomCamProLPtrDato->chrPtrNmbCampo,
  					 "Sql",
					 pSiscomRegProLPtrAct);
  PostgresEjecutaConsulta(pPosSqlPtrRegreso->PGConPtrConexion,
  			  pchrPtrTipoCursor,
  			  lchrArrNmbConsulta,
			  lchrPtrSql,
			  &pPosSqlPtrRegreso->intNumCampos,
			  &pPosSqlPtrRegreso->intNumRegistros,
			  &pPosSqlPtrRegreso->PGresPtrEdoComando);
  PostgresFormaRespuestaConsulta(pPosSqlPtrRegreso,
  				 lSiscomCamProLPtrDato->chrPtrNmbCampo,
  			   	 *pSiscomRegProLPtrPrimReg);
  lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
}

}


char *SiscomObtenRegistrosArchivosBD(PostgresSql *pPosSqlPtrRegreso,
				   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomCampoProL *lSiscomCamProLPtrDato;
const char *lchrPtrSql;
char lchrArrNmbConsulta[512];
lSiscomCamProLPtrDato=pSiscomRegProLPtrAct->SiscomCamProLPtrDato;
if(lSiscomCamProLPtrDato)
{
  GeneraNombreConsulta(lSiscomCamProLPtrDato,lchrArrNmbConsulta);
  lchrPtrSql=SiscomCampoRegistroAsociado(lSiscomCamProLPtrDato->chrPtrNmbCampo,
  					 "Sql",
					 pSiscomRegProLPtrAct);
  PostgresEjecutaConsulta(pPosSqlPtrRegreso->PGConPtrConexion,
  			  "binary",
  			  lchrArrNmbConsulta,
			  lchrPtrSql,
			  &pPosSqlPtrRegreso->intNumCampos,
			  &pPosSqlPtrRegreso->intNumRegistros,
			  &pPosSqlPtrRegreso->PGresPtrEdoComando);
}

}

SiscomCampoProL *FormaRegistroRespuesta(PostgresSql *pPosSqlPtrRegreso,
					int pintNRegistro)

{
int lintContador;
SiscomCampoProL *lSiscomCamProLPtrPrim=0,
   		*lSiscomCamProLPtrAct=0;
for(lintContador=0;
    lintContador<pPosSqlPtrRegreso->intNumCampos;
    lintContador++)
SiscomNodoCampoPro2(
  PQfname(pPosSqlPtrRegreso->PGresPtrEdoComando,lintContador),
  PQgetvalue(pPosSqlPtrRegreso->PGresPtrEdoComando,pintNRegistro,lintContador),
  &lSiscomCamProLPtrPrim,
  &lSiscomCamProLPtrAct);
return lSiscomCamProLPtrPrim;
}
void PostgresFormaRespuestaConsulta(PostgresSql *pPosSqlPtrRegreso,
				    const char *pchrPtrNmbConsulta,
				    SiscomRegistroProL *pSiscomRegProLPtrPrimReg)
{
int lintContador;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
	
for(lintContador=0;
    lintContador<pPosSqlPtrRegreso->intNumRegistros;
    lintContador++)
  SiscomNodoRegistroPro(FormaRegistroRespuesta(pPosSqlPtrRegreso,lintContador),
  			&lSiscomRegProLPtrPrim,
			&lSiscomRegProLPtrAct);
SiscomRegistrosAlCampo(pchrPtrNmbConsulta,
		       lSiscomRegProLPtrPrim,
		       lSiscomRegProLPtrAct,
		       pSiscomRegProLPtrPrimReg);
}

void *SiscomOperacionBD(int pintSocket,
			void *pvidPtrAncla,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct)
{
char lchrArrBuffer[2048];
SiscomRegistroProL *lSiscomRegProLPtrSqls;
const char *lchrPtrBaseDatos;
const char *lchrPtrPuertoBD,
	   *lchrPtrServidor=0,
	   *lchrPtrUsuario=0,
	   *lchrPtrPassword=0;
char *lchrPtrEdoConexion;
const char *lchrPtrEdoSentencia;
const char *lchrPtrSql;
int lintEstado=0;
PostgresSql lPosSqlRegreso;
lchrPtrBaseDatos=SiscomCampoRegistro("BaseDatos",pSiscomRegProLPtrPrim);
lchrPtrPuertoBD=SiscomCampoRegistro("Puerto",pSiscomRegProLPtrPrim);
if(!(lchrPtrEdoConexion=SiscomConectateBD(&lPosSqlRegreso,
					  lchrPtrPuertoBD,
					  lchrPtrBaseDatos,
					  lchrPtrServidor,
					  lchrPtrUsuario,
					  lchrPtrPassword)))
{
					   
if((lSiscomRegProLPtrSqls=SiscomObtenRegistrosCampoProL(
				"SentenciasSql",
				pSiscomRegProLPtrPrim)))
while(lSiscomRegProLPtrSqls)
{
  lchrPtrSql=SiscomCampoRegistro("Sql",lSiscomRegProLPtrSqls);
  LogSiscom("%s",lchrPtrSql);
  if((lchrPtrEdoSentencia=PostgresEjecutaComando(
  			   lPosSqlRegreso.PGConPtrConexion,
			   lchrPtrSql,
			   1,
			   &lPosSqlRegreso.PGresPtrEdoComando)))
   {
	 SiscomActualizaCampoRegistro("Estado",(char *)lchrPtrEdoSentencia,lSiscomRegProLPtrSqls);
	 lintEstado=1;

   }
  lSiscomRegProLPtrSqls=lSiscomRegProLPtrSqls->SiscomRegProLPtrSig;
}
if(lintEstado)
SiscomActualizaCampoRegistro("EstadoOperacion","Error",pSiscomRegProLPtrPrim);
else
SiscomActualizaCampoRegistro("EstadoOperacion","Exitosa",pSiscomRegProLPtrPrim);
SiscomEnviaRegistrosSocket(pintSocket,lchrArrBuffer,pSiscomRegProLPtrPrim); 
}
else
LogSiscom("Error al conectarse a la base %s (%s)",
	   lchrPtrBaseDatos,
	   lchrPtrEdoConexion);

}
const char *PostgresEjecutaComando2(PGconn *pPGCPtrConexion,
				    const char *pchrPtrComandoSql,
				    int pintEvaluaEstatus,
				    SiscomBloqueArchivoL *pSiscomBloArLPtrDato,
				    PGresult **pPGRRegreso)
{
const char *lchrPtrParametros[1];
int lintTamanoParametro[1];
int lintFormatoParametro[1];

lchrPtrParametros[0]=SiscomDatoBloqueArchivo(pSiscomBloArLPtrDato);
lintTamanoParametro[0]=SiscomTamanoBloque(pSiscomBloArLPtrDato);
lintFormatoParametro[0]=1;

*pPGRRegreso=PQexecParams(pPGCPtrConexion,
			  pchrPtrComandoSql,
			  1,
			  0,
			  lchrPtrParametros,
			  lintTamanoParametro,
			  lintFormatoParametro,
			  1);
        if(PQresultStatus(*pPGRRegreso)!=PGRES_COMMAND_OK)
	return PQerrorMessage(pPGCPtrConexion);

return (char *)0; 
}
/* Viernes 26 de diciembre  2014
 * se agrega el manejo de insercion de datos binarios, 
 * principalmente para el registro de archivos , los
 * cuales se realizaran en bloques de 1024 bytes
 * almacenados en SiscomBloqueArchivoL
 */
void *SiscomOperacionBinarioBD(int pintSocket,
			void *pvidPtrAncla,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct)
{
char lchrArrBuffer[2048];
SiscomRegistroProL *lSiscomRegProLPtrSqls;
const char *lchrPtrBaseDatos;
const char *lchrPtrPuertoBD,
	   *lchrPtrServidorBD=0,
	   *lchrPtrUsuario=0,
	   *lchrPtrPassword=0;
char *lchrPtrEdoConexion;
const char *lchrPtrEdoSentencia=0;
const char *lchrPtrSql;
int lintEstado=0;
SiscomBloqueArchivoL *lSiscomBloArLPtrBloques;
PostgresSql lPosSqlRegreso;
lchrPtrBaseDatos=SiscomCampoRegistro("BaseDatos",pSiscomRegProLPtrPrim);
lchrPtrPuertoBD=SiscomCampoRegistro("Puerto",pSiscomRegProLPtrPrim);
if(!(lchrPtrEdoConexion=SiscomConectateBD(&lPosSqlRegreso,
					  lchrPtrPuertoBD,
					  lchrPtrBaseDatos,
					  lchrPtrServidorBD,
					  lchrPtrUsuario,
					  lchrPtrPassword)))
{
SiscomRecibeArchivo(pintSocket,&lSiscomBloArLPtrBloques);
if((lSiscomRegProLPtrSqls=SiscomObtenRegistrosCampoProL(
				"SentenciasSql",
				pSiscomRegProLPtrPrim)))
while(lSiscomRegProLPtrSqls)
{
  lchrPtrSql=SiscomCampoRegistro("Sql",lSiscomRegProLPtrSqls);
  LogSiscom("%s",lchrPtrSql);
  if((lchrPtrEdoSentencia=PostgresEjecutaComando2(
  			   lPosSqlRegreso.PGConPtrConexion,
			   lchrPtrSql,
			   1,
			   lSiscomBloArLPtrBloques,
			   &lPosSqlRegreso.PGresPtrEdoComando)))
   {
	 LogSiscom("%s",lchrPtrEdoSentencia);
	 SiscomActualizaCampoRegistro("Estado",(char *)lchrPtrEdoSentencia,lSiscomRegProLPtrSqls);
	 lintEstado=1;

   }
  lSiscomRegProLPtrSqls=lSiscomRegProLPtrSqls->SiscomRegProLPtrSig;
  lSiscomBloArLPtrBloques=lSiscomBloArLPtrBloques->SiscomBloArcPtrSig;
}
if(lintEstado)
SiscomActualizaCampoRegistro("EstadoOperacion","Error",pSiscomRegProLPtrPrim);
else
SiscomActualizaCampoRegistro("EstadoOperacion","Exitosa",pSiscomRegProLPtrPrim);
SiscomEnviaRegistrosSocket(pintSocket,lchrArrBuffer,pSiscomRegProLPtrPrim); 
}
else
LogSiscom("Error al conectarse a la base %s (%s)",
	   lchrPtrBaseDatos,
	   lchrPtrEdoConexion);


}
void MuestraCadena(const unsigned char *pchrPtrCadena,
		   int pintTamano)
{
int lintContador;
for(lintContador=0;
    lintContador<pintTamano;
    lintContador++,
    pchrPtrCadena++)
printf("%d",*pchrPtrCadena);

printf("\n");
}
void EnviaBloqueArchivo(int pintSocket,
			int pintRegistro,
			int pintBytes,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			PGresult *pPGresult)
{
int lintNColumna=PQfnumber(pPGresult,SiscomObtenCampoRegistroProLChar("Bloque",pSiscomRegProLPtrPrim)),
    lintNEnviados,
    lintContador ;
unsigned char *lchrPtrBloque=PQgetvalue(pPGresult,
					pintRegistro,
					lintNColumna);
SiscomEnviaIntSocket(pintSocket,10,pintBytes); 
if((lintNEnviados=write(pintSocket,lchrPtrBloque,pintBytes))!=pintBytes)
LogSiscom("Solo se enviaron %d bytes",lintNEnviados);
}
int TamanoBloqueArchivo(int pintNumeroRegistro,
				PGresult *pPGresult,
				SiscomRegistroProL *pSiscomRegProLPrim)
{
int lintNColumna=PQfnumber(pPGresult,SiscomObtenCampoRegistroProLChar("ColumnaBloque",pSiscomRegProLPrim)),
    lintRegreso;
char *lchrPtrRegreso= PQgetvalue(pPGresult,
				 pintNumeroRegistro,
				 lintNColumna);
return ntohl(*(uint32_t *)lchrPtrRegreso);
}
void *SiscomConsultaArchivosBD(int pintSocket,
			void *pvidPtrAncla,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct)
{
char lchrArrBuffer[2048];
char *lchrPtrEdoConexion;
PostgresSql lPosSqlRegreso;
const char *lchrPtrBaseDatos;
const char *lchrPtrPuertoBaseDatos,
	   *lchrPtrServidor=0,
	   *lchrPtrUsuario=0,
	   *lchrPtrPassword=0;
int lintContador,lintBytes;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
lchrPtrBaseDatos=SiscomCampoRegistro("BaseDatos",pSiscomRegProLPtrPrim);
lchrPtrPuertoBaseDatos=SiscomCampoRegistro("PuertoBaseDatos",pSiscomRegProLPtrPrim);
if(!(lchrPtrEdoConexion=SiscomConectateBD(&lPosSqlRegreso,
					 lchrPtrPuertoBaseDatos,
					 lchrPtrBaseDatos,
					 lchrPtrServidor,
					 lchrPtrUsuario,
					 lchrPtrPassword)))
{
SiscomObtenRegistrosArchivosBD(&lPosSqlRegreso,
			     pSiscomRegProLPtrAct);
LogSiscom("Se enviaran %d bloques ",SiscomObtenCampoRegistroProLInt("NBloques",pSiscomRegProLPtrPrim));
LogSiscom("La consulta es en binario :%d",PQbinaryTuples(lPosSqlRegreso.PGresPtrEdoComando));
SiscomEnviaIntSocket(pintSocket,10,SiscomObtenCampoRegistroProLInt("NBloques",pSiscomRegProLPtrPrim)); 
for(lintContador=0;
    lintContador<lPosSqlRegreso.intNumRegistros;
    lintContador++)
{
  lintBytes=TamanoBloqueArchivo(lintContador,lPosSqlRegreso.PGresPtrEdoComando,pSiscomRegProLPtrPrim);
  EnviaBloqueArchivo(pintSocket,
  		     lintContador,
		     lintBytes,
		     pSiscomRegProLPtrPrim,
		     lPosSqlRegreso.PGresPtrEdoComando);
}
PQfinish(lPosSqlRegreso.PGConPtrConexion);
}
else
LogSiscom("No se conecto a:%s Error(%s)",lchrPtrBaseDatos,lchrPtrEdoConexion);
}

