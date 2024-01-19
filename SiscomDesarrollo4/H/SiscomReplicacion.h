#ifndef __SISCOMREPLICACION_H__
#define __SISCOMREPLICACION_H__
#include <SiscomOperaciones.h>
typedef int (*SiscomLogConsultaSistema)(SiscomRegistroProL *pSiscomPtrRegProLMaquinas,
					const char *pchrPtrCampo,
					SiscomOperaciones *pSiscomOpePtrDato);
int SiscomDatosComunicacionMemoria(const char *pchrPtrMaquina,
				    char **pchrPtrDirIp,
				    int *pintPtrPuerto);
int SiscomReplicacionEnvioServidor(const char *pchrPtrMaquina,
				    const char *pchrPtrArgumentoEnvio,
				    char *pchrPtrBuffer,
			      		SiscomOperacion pSiscomOpAccionErrorRep,
				    SiscomOperaciones *pSiscomOpPtrDat);
int SiscomReplicaServidorWeb(const char *pchrPtrArgumentoEnvio,
			      char *pchrPtrBuffer,
			      SiscomOperacion pSiscomOpAccionErrorRep,
			      SiscomOperaciones *pSiscomOpPtrDat);
int SiscomReplicaMatriz(const char *pchrPtrArgumentoEnvio,
			       char *pchrPtrBuffer,
			 SiscomOperaciones *pSiscomOpPtrDat);
int SiscomReplicaExpendios(const char *pchrPtrArgumentoEnvio,
			       char *pchrPtrBuffer,
			      SiscomOperacion pSiscomOpAccionErrorRep,
			    SiscomOperaciones *pSiscomOpPtrDat);

int SiscomReplicaMaquinaLocal(const char *pchrPtrArgumentoEnvio,
			       char *pchrPtrBuffer,
			      SiscomOperacion pSiscomOpAccionErrorRep,
			    	SiscomOperaciones *pSiscomOpPtrDat);
/*  Jueves 21 de Mayo del 2015
 *  La variable pSiscomRegProLPtrMemoria, se tomara de la variable 
 *  global que inicializa la memoria comun para los servidores, o 
 *  el indice en el caso que aplique como arreglo
 */
int SiscomReplicaMaquinasSistema(const char *pchrPtrTipoEquipo,
				 const char *pchrPtrArgumentoEnvio,
			         char *pchrPtrBuffer,
				 SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			         SiscomOperacion pSiscomOpAccionErrorRep,
			    	 SiscomOperaciones *pSiscomOpPtrDat);


int SiscomReplicaMaquinaSistema(const char *pchrPtrIdMaquina,
				 const char *pchrPtrArgumentoEnvio,
			         char *pchrPtrBuffer,
				 SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			         SiscomOperacion pSiscomOpAccionErrorRep,
			    	 SiscomOperaciones *pSiscomOpPtrDat);

int SiscomReplicaMaquinaPorCampo(const char *pchrPtrNmbCampo,
				 const char *pchrPtrValorCampo,
			         const char *pchrPtrArgumentoEnvio,
			         char *pchrPtrBuffer,
				 SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			         SiscomOperacion pSiscomOpAccionErrorRep,
			    	 SiscomOperaciones *pSiscomOpPtrDat);


int SiscomErrorOperacionBase(SiscomOperaciones *pSiscomOpePtrDato);

int SiscomServidorPorIdMaquina(const char *pchrPtrIdMaquina,
			       SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			       int *pintPtrPuerto,
			       const char **pchrPtrDirIp);

int SiscomServidorPorTipoMaquina(const char *pchrPtrTipoMaquina,
			       SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			       int *pintPtrPuerto,
			       const char **pchrPtrDirIp,
			       const char **pchrPtrBaseDatos);

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
			       ...);

void SiscomConsultasSqlServidorPorIdMaquina(const char *pchrPtrIdServidor,
				            SiscomRegistroProL *pSiscomRegProLPtrMemoria,
				            char *pchrPtrBuffer,
				            SiscomOperaciones *pSiscomOpePtrDatos,
				            const char *pchrPtrFormato,
				            ...);

int SiscomConsultasSqlServidorPorIdMaquina3(const char *pchrPtrIdServidor,
					     const char *pchrPtrArgumento,
					     SiscomOperaciones *pSiscomOpePtrDatos,
					     int (*Servivdor)(const char *pchrPtrIdServidor,
					     		      const char *pchrPtrArgumento,
							      SiscomOperaciones *pSiscomOpePtrDato,
							      int *pintPuerto,
							      char **pchrPtrDirIp),
					     char *pchrPtrBuffer,
					     const char *pchrPtrFormato,
					     ...);

void SiscomConsultasSqlServidorPorIdMaquina2(const char *pchrPtrIdServidor,
				     SiscomRegistroProL *pSiscomRegProLPtrMemoria,
				     char *pchrPtrBuffer,
				     char **pchrPtrNombres,
				     char **pchrPtrConsultas,
				     SiscomOperaciones *pSiscomOpePtrDatos);

SiscomRegistroProL *SiscomRegistrosMaquinaConsulta(const char *pchrPtrDatoConsultar,
						   const char *pchrPtrNombreConsulta,
						   SiscomOperaciones *pSiscomOpePtrDato);

const char *SiscomCampoServidorPorId(const char *pchrPtrCampoRegreso,
				     const char *pchrPtrCampo,
				     const char *pchrPtrValorCampo,
				     const char *pchrPtrArgumento,
				     const char *pchrPtrAsociado,
				     SiscomOperaciones *pSiscomOpePtrDato);

extern SiscomRegistroProL *gSiscomRegProLPtrMemoria;

#endif
