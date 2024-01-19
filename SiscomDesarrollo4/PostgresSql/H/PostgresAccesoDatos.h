#ifndef __POSTGRESACCESODATOS_H__
#define __POSTGRESACCESODATOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomRecibeArchivo.h>
#include <libpq-fe.h>

typedef struct PostgresSql
{
  PGconn *PGConPtrConexion;
  PGresult *PGresPtrEdoComando;
  const char *chrPtrBaseDatos;
  const char *chrPtrPuertoBaseDatos;

  int intNumCampos;
  int intNumRegistros;
}PostgresSql; 

void *SiscomOperacionBD(int pintSocket,
			void *pvidPtrAncla,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);

void *SiscomOperacionBinariaBD(int pintSocket,
			void *pvidPtrAncla,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);
void *SiscomConsultaBD(int pintSocket,
			void *pvidPtrAncla,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);

void *SiscomConsultaArchivosBD(int pintSocket,
			void *pvidPtrAncla,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);
/*

char *SiscomConectateBD(PostgresSql *pPosSqlPtrRegreso,
			const char *pchrPtrPuertoBaseDatos,
			const char *pchrPtrBaseDatos,
			const char *pchrPtrServidorBD,
			const char *pchrPtrUsuario,
			const char *pchrPtrPassword)

*/
char *SiscomConectateBD(PostgresSql *pPosSqlPtrRegreso,
			const char *pchrPtrPuertoBaseDatos,
			const char *pchrPtrBaseDatos,
			const char *pchrPtrServidorBD,
			const char *pchrPtrUsuario,
			const char *pchrPtrPassword);

const char *PostgresEjecutaComando(PGconn *pPGCPtrConexion,
				   const char *pchrPtrComandoSQL,
				   int pintEvaluaEstatus,
				   PGresult **pPGRRegreso);

const char *PostgresEjecutaComando2(PGconn *pPGCPtrConexion,
				    const char *pchrPtrComandoSql,
				    int pintEvaluaEstatus,
				    SiscomBloqueArchivoL *pSiscomBloArLPtrDato,
				    PGresult **pPGRRegreso);
/* Lunes 29 de Diciembre del 2014 
 * Para poder trabajar con los archivos que se insertan en la base de datos
 * en los que se integra un campo binario, modifico la funcion para pasar 
 * el parametro que indicara si el cursor regresara columnas binarias o 
 * texto
 */
const char *PostgresEjecutaConsulta(PGconn *pPGCPtrConexion,
				    const char *pchrPtrTipoCursor,
				      const char *pchrPtrNmbConsulta,
				      const char *pchrPtrConsulta,
				      int *pintPtrNumColumnas,
				      int *pintPtrNumReg,
				      PGresult **pPGRPtrResul);


char *SiscomObtenRegistrosConsulta(PostgresSql *pPosSqlPtrRegreso,
				   const char *pchrPtrTipoCursor,
				   const SiscomRegistroProL *pSiscomRegProLPtrAct,
				   SiscomRegistroProL **pSiscomRegProLPtrPrimReg,
				   SiscomRegistroProL **pSiscomRegProLPtrActReg);


char *SiscomObtenRegistrosArchivosBD(PostgresSql *pPosSqlPtrRegreso,
				   const SiscomRegistroProL *pSiscomRegProLPtrAct);
void PostgresFormaRespuestaConsulta(PostgresSql *pPosSqlPtrRegreso,
				    const char *pchrPtrConsulta,
				    SiscomRegistroProL *pSiscomRegProLPtrPrimReg);
#endif
