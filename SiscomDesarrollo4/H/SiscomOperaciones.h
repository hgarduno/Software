#ifndef __SISCOMOPERACIONES_H__
#define __SISCOMOPERACIONES_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomRecibeArchivo.h>
typedef struct SiscomArgumento
{
  int intArgumentos;
  SiscomRegistroProL *SiscomRegProLPtrPrim;
  SiscomRegistroProL *SiscomRegProLPtrAct;
  
  char chrArrNombre[28];
}SiscomArgumento;
typedef struct SiscomOperaciones
{
    /* Sabado 12 de mayo del 2012 
     * Almacena la informacion de los registros de entrada
     */ 
    SiscomRegistroProL *SiscomRegProLPtrPrimEnt;
    SiscomRegistroProL *SiscomRegProLPtrActEnt;

    /* Sabado 12 de mayo del 2012
     * Alamacena la informacion de los registros de respuesta
     */
    SiscomRegistroProL *SiscomRegProLPtrPrimRes;
    SiscomRegistroProL *SiscomRegProLPtrActRes;
    int intSocket;
    int intSocketAD;
    void *vidPtrAncla;

    char chrArrBaseDatos[128];
    char chrArrPuertoBaseDatos[8];
    char chrArrDirIpSvrAccesoDatos[17];

    int intPuertoSvrAccesoDatos;

    SiscomArgumento *SiscomArgPtrDatos;
    /* Jueves 25 de diciembre 
     * Con la integracion de la funcionalidad de web,
     * se requiere llevar el control de las imagenes
     * por lo que se integro la funcionalidad de 
     * que permite manipular a traves de los sockets
     * de comunicaciones el envio de archivos, mediante
     * una lista simplemente ligada
     */
    SiscomBloqueArchivoL *SiscomBloArLArchivo;


}SiscomOperaciones;

typedef int (*SiscomOperacion)(SiscomOperaciones *pSiscomOpePtrDat);
typedef SiscomOperacion SiscomOperacionErrores[100];
typedef struct SiscomProcesos
{
   int intProcesos;
   int intCodigoRetorno;
   SiscomOperacion SiscomOpePtrProcesos;
}SiscomProcesos;
/*
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
				SiscomOperaciones *pSiscomOpePtrDato);
*/

void SiscomEjecutaProcesos(SiscomOperaciones *pSiscomOpePtrDat,
			   SiscomOperacionErrores pSiscomOpeErrores,
			   SiscomProcesos *pSiscomProPtrDat);
void SiscomAgregaOperacion(SiscomOperacion pSiscomOpePtrDat,
			    SiscomProcesos **pSiscomProPtrDat);

void SiscomArgumentoAPrimerActual(const char *pchrPtrArgumento,
				  SiscomOperaciones *);


const SiscomArgumento *SiscomObtenArgumento(const char *pchrPtrArgumento,
			  const SiscomArgumento *pSiscomArgPtrDat);
void SiscomAgregaArgumento(const char *pchrPtrNombre,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct,
			   SiscomArgumento **pSiscomArgPtrDato);

void SiscomAgregaArgumentoOperacion(const char *pchrPtrNombre,
			   SiscomRegistroProL *pSiscomRegProLPtrPrim,
			   SiscomRegistroProL *pSiscomRegProLPtrAct,
			   SiscomOperaciones *pSiscomOperPtrDat);
			
void SiscomIniciaDatosOperacion(int pintSocket,
				void *pvidPtrAncla,
				SiscomRegistroProL *pSiscomRegProLPtrPrim,
				SiscomRegistroProL *pSiscomRegProLPtrAct,
				SiscomOperaciones *pSiscomOpePtrDat);

void SiscomEnviaConsultaSqlAsignaArgumento(const char *pchrPtrDirIpSvr,
					   const char *pchrPtrBaseDatos,
					   const char *pchrPtrPuertoBaseDatos,
					   const char *pchrPtrSql,
					   const char *pchrPtrArgumento,
					   char *pchrPtrBuffer,
					   int pintPuertoSvr,
					   SiscomOperaciones *pSiscomOpePtrDatos);

void SiscomEnviaConsultaSqlAsignaArgumento2(const char *pchrPtrDirIpSvr,
					   const char *pchrPtrBaseDatos,
					   const char *pchrPtrPuertoBaseDatos,
					   const char *pchrPtrServidorBD,
					   const char *pchrPtrUsuarioBD,
					   const char *pchrPtrPasswordBD, 
					   const char *pchrPtrSql,
					   const char *pchrPtrArgumento,
					   char *pchrPtrBuffer,
					   int pintPuertoSvr,
					   SiscomOperaciones *pSiscomOpePtrDatos);

int SiscomEjecutaConsultaSql(const char *pchrPtrSql,
			     const char *pchrPtrNmbConsulta,
			     char *pchrPtrBuffer,
			     SiscomOperaciones *pSiscomOpePtrDato,
			     SiscomRegistroProL **,
			     SiscomRegistroProL **);

void SiscomConsultaSqlAArgumentoOperaciones(const char *pchrPtrSql,
					    const char *pchrPtrArgumento,
					    char *pchrPtrBuffer,
					    SiscomOperaciones *pSiscomOpePtrDatos);

void SiscomConsultasSql(char *pchrPtrBuffer,
			const char *pchrPtrDirIp,
			const char *pchrPtrBaseDatos,
			const char *pchrPtrPuertoBase,
			int pintPuerto,
			SiscomRegistroProL **pSiscomRegProLPtrPrim,
			SiscomRegistroProL **pSiscomRegProLPtrAct,
			int *pintPtrSocket,
			const char *pchrPtrFormato,
			...);

void SiscomConsultasSql2(char *pchrPtrBuffer,
			const char *pchrPtrDirIp,
			const char *pchrPtrBaseDatos,
			const char *pchrPtrPuertoBase,
			const char *pchrPtrServidor,
			const char *pchrPtrUsuario,
			const char *pchrPtrPassword,
			int pintPuerto,
			SiscomRegistroProL **pSiscomRegProLPtrPrim,
			SiscomRegistroProL **pSiscomRegProLPtrAct,
			int *pintPtrSocket,
			const char *pchrPtrFormato,
			...);

void SiscomConsultasSqlOperaciones(char *pchrPtrBuffer,
				   SiscomOperaciones *SiscomOpePtrDatos,
				   const char *pchrPtrFormato,
				   ...);
SiscomRegistroProL *SiscomRegistroProLObtenArgumentoPrim(
			const char *pchrPtrArgumento,
			const SiscomArgumento *pSiscomArgumentos);

SiscomRegistroProL *SiscomRegistroProLObtenArgumentoAct(
			const char *pchrPtrArgumento,
			const SiscomArgumento *pSiscomArgumentos);
SiscomRegistroProL *SiscomObtenArgumentoPrimOperaciones(const char *pchrPtrNombre,SiscomOperaciones *pSiscomOpePtrDatos);
SiscomRegistroProL *SiscomObtenArgumentoPrimAsociadoOperaciones(const char *pchrPtrArgumento,
								const char *pchrPtrAsociado,
								SiscomOperaciones *pSiscomOpePtrDatos);
const char *SiscomCampoArgumentoPrim(const char *pchrPtrArgumento,
				     const char *pchrPtrCampo,
				     SiscomOperaciones *pSiscomOpePtrDato);

const char *SiscomCampoArgumentoAct(const char *pchrPtrArgumento,
				     const char *pchrPtrCampo,
				     SiscomOperaciones *pSiscomOpePtrDato);
SiscomRegistroProL *SiscomObtenArgumentoActOperaciones(const char *pchrPtrNombre,SiscomOperaciones *pSiscomOpePtrDatos);

SiscomRegistroProL *SiscomObtenRegistrosCampoRespuesta(const char *pchrPtrCampo,
						       SiscomOperaciones *pSiscomOpePtrDatos);
SiscomRegistroProL *SiscomObtenRegistrosCampoEntrada(const char *pchrPtrCampo,
						       SiscomOperaciones *pSiscomOpePtrDatos);

void SiscomAsignaRegistrosArgumentoOperaciones(SiscomRegistroProL *pSisRegProLPtrPrim,
					       SiscomRegistroProL *pSisRegProLPtrAct,
					       const char *pchrPtrArgumento,
					       SiscomOperaciones *pSiscomOpeDatos);

SiscomRegistroProL *SiscomRegistrosAsociadoEntradaOperacion(const char *pchrPtrCampoAsociado,
						 SiscomOperaciones *pSiscomOpePtrDatos);


SiscomRegistroProL *SiscomRegistrosAsociadoRespuestaOperacion(const char *pchrPtrCampoAsociado,
						 SiscomOperaciones *pSiscomOpePtrDatos);
const char *SiscomCampoAsociadoEntradaOperacion(const char *pchrPtrCampoAsociado,
						 const char *PchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos);

const char *SiscomCampoAsociadoRespuesta(const char *pchrPtrCampoAsociado,
						 const char *PchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos);
SiscomRegistroProL *SiscomRegistroAsociadoEntradaOperacion(const char *pchrPtrCampoAsociado,
							   const char *pchrPtrCampo,
							   SiscomOperaciones *pSiscomOpePtrDatos);
SiscomRegistroProL *SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion(const char *pchrPtrAsociado,
							   const char *pchrPtrAsociado1,
							   const char *pchrPtrCampo,
							   SiscomOperaciones *pSiscomOpePtrDato);
const char *SiscomCampoAsociadoAsociadoEntradaOperacion(const char *pchrPtrCampoAsociado,
							const char *pchrPtrCampoAsociado1,
						 	const char *pchrPtrCampo,
						 	SiscomOperaciones *pSiscomOpePtrDatos);

int SiscomCampoAsociadoAsociadoInt(const char *pchrPtrCampoAsociado,
				const char *pchrPtrCampoAsociado1,
				const char *pchrPtrCampo,
				SiscomOperaciones *pSiscomOpePtrDatos);


float SiscomCampoAsociadoAsociadoEntradaOperacionFloat(
					const char *pchrPtrCampoAsociado,
					const char *pchrPtrCampoAsociado1,
					const char *pchrPtrCampo,
					SiscomOperaciones *pSiscomOpePtrDatos);

int SiscomCampoAsociadoEntradaOperacionInt(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos);
float SiscomCampoAsociadoEntradaOperacionFloat(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos);
const char *SiscomCampoAsociadoRespuestaOperacion(const char *pchrPtrCampoAsociado,
						 const char *PchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos);

SiscomRegistroProL *SiscomRegistroAsociadoRespuestaOperacion(const char *pchrPtrCampoAsociado,
						 const char *pchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos);

int SiscomCampoAsociadoRespuestaOperacionInt(const char *pchrPtrCampoAsociado,
						 const char *PchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos);
float SiscomCampoAsociadoRespuestaOperacionFloat(const char *pchrPtrCampoAsociado,
						 const char *PchrPtrCampo,
						 SiscomOperaciones *pSiscomOpePtrDatos);
const char *SiscomObtenCampoAsociadoArgumento(const char *pchrPtrArgumento,
					      const char *pchrPtrRegistroAsociado,
					      const char *pchrPtrCampo,
					      SiscomOperaciones *pSiscomOpePtrDatos);
/* Domingo 11 de enero del 2015
 * De pSiscomOpePtrDatos obtiene el el argumento pchrPtrArgumento del registro actual
 * del cual buscara el campo pchrPtrCampo, y regresara el valor
 */
const char *SiscomObtenCampoArgumento4(const char *pchrPtrArgumento,
					      const char *pchrPtrCampo,
					      SiscomOperaciones *pSiscomOpePtrDatos);

int SiscomObtenCampoArgumentoInt(const char *pchrPtrArgumento,
					      const char *pchrPtrCampo,
					      SiscomOperaciones *pSiscomOpePtrDatos);
float SiscomObtenCampoArgumentoFloat(const char *pchrPtrArgumento,
					      const char *pchrPtrCampo,
					      SiscomOperaciones *pSiscomOpePtrDatos);
SiscomCampoProL *SiscomFormaCamposSql(const char *pchrPtrFormato,
				      char *pchrPtrBuffer);


int SiscomEnviaArgumentoCliente(const char *pchrPtrArgumento,char *pchrPtrBuffer,SiscomOperaciones *pSiscomOpPtrDatos);

/* Miercoles 24 de diciembre del 2014
 * Es para el campo de respuesta 
 */
SiscomRegistroProL *SiscomRegistrosCampoO(const char *pchrPtrCampo,SiscomOperaciones *pSiscomOpPtrDatos);
void SiscomIdARegistrosAsociadosEntrada(const char *pchrPtrAsociado,
					const char *pchrPtrCampo,
				 	SiscomOperaciones *pSiscomOpPtrDatos);
void SiscomIdAsociadosCampoEntrada(const char *pchrPtrCampo,
				   const char *pchrPtrAsociado,
				   const char *pchrPtrIdCampo,
				   SiscomOperaciones *pSiscomOpPtrDatos);

void SiscomIdAsociadoAsociadosCampoEntrada(const char *pchrPtrAsociado,
					   const char *pchrPtrAsociados,
					   const char *pchrPtrCampo,
					   SiscomOperaciones *pSiscomOpePtrDatos);

void SiscomAgregaCampoRegistroEntrada(const char *pchrPtrNombre,
				      const char *pchrPtrCampo,
				      SiscomOperaciones *pSiscomOpPtrDatos);
void SiscomAgregaCampoRegistroRespuesta(const char *pchrPtrNombre,
				      const char *pchrPtrCampo,
				      SiscomOperaciones *pSiscomOpPtrDatos);



void SiscomAgregaCampoAsociadoRespuesta(const char *pchrPtrNombre,
				      const char *pchrPtrCampo,
				      const char *pchrPtrAsociado,
				      SiscomOperaciones *pSiscomOpPtrDatos);

void SiscomAgregaCampoAsociadoEntrada(const char *pchrPtrNombre,
				      const char *pchrPtrCampo,
				      const char *pchrPtrAsociado,
				      SiscomOperaciones *pSiscomOpPtrDatos);
void SiscomActualizaCampoAsociadoEntrada(const char *pchrPtrAsociado,
					 const char *pchrPtrCampo,
					 char *pchrPtrValor,
					 SiscomOperaciones *pSiscomOpePtrDatos);

void SiscomActualizaCampoAsociadoAsociadoEntrada(const char *pchrPtrAsociado,
						 const char *pchrPtrAsociadoA,
						 const char *pchrPtrCampo,
						 const char *pchrPtrDato,
						 SiscomOperaciones *pSiscomOpePtrDatos);

void SiscomActualizaCampoAsociadoEntradaFloat(const char *pchrPtrAsociado,
					 const char *pchrPtrCampo,
					 float pfltValor,
					 SiscomOperaciones *pSiscomOpePtrDato);
/* Domingo 11 de enero 2015
 * Busca en pSiscomOpePtrDatos el argumento pchrPtrArgumento, y busca el campo pchrPtrCampo 
 * del registro actual, y le asigna pchrPtrValor asignando memoria para el campo
 *
 */
void SiscomActualizaCampoArgumento(const char *pchrPtrArgumento,
					 const char *pchrPtrCampo,
					 char *pchrPtrValor,
					 SiscomOperaciones *pSiscomOpePtrDatos);
/* Domingo 11 de Enero 2015 
 * En pSiscomOpePtrDatos obtendra el  argumento pchrPtrArgumento y  buscara el 
 * campo pchrPtrCampo, del registro actual y asignara pchrPtrValor mediante 
 * memoria dinamica para el campo, solo en el nodo actual de la lista del 
 * argumento, no todos los registros 
 */
void SiscomActualizaCampoArgumento2(const char *pchrPtrArgumento,
					 const char *pchrPtrCampo,
					 char *pchrPtrValor,
					 SiscomOperaciones *pSiscomOpePtrDatos);

/* Domingo 11 de Enero 2015 
 * En pSiscomOpePtrDatos, se busca el argumento pchrPtrArgumento, para actualizar
 * el campo pchrPtrCampo, con pfltDato. Si pchrPtrFormato es diferente de 0, 
 * se pasa este argumento como formato a sprintf, para formatear el numero
 * float. El campo se asigna via strdup
 *
 */
void SiscomActualizaCampoFloatArgumentoActual(const char *pchrPtrArgumento,
					     const char *pchrPtrCampo,
			  		     const char *pchrPtrFormato,
			  		     float pfltDato,
					     SiscomOperaciones *pSiscomOpePtrDatos);

void SiscomRegistroEnvioBaseDatosAArgumento(const char *pchrPtrOperacion,
				     const char *pchrPtrArgumento,
				     char *pchrPtrBuffer,
				     SiscomOperaciones *pSiscomOpePtrDatos);

void SiscomRegistroASentenciasSqlAArgumento(char *pchrPtrBuffer,
					    const char *pchrPtrSql,
					    const char *pchrPtrArgumento,
					    SiscomOperaciones *pSiscomOpePtrDatos);


SiscomRegistroProL *SiscomRegistrosAsociadosCampoEntrada(const char *pchrPtrCampo,
						  const char *pchrPtrAsociado,
						  SiscomOperaciones *pSiscomOpePtrDato);

SiscomRegistroProL *SiscomRegistrosAsociadosCampoRespuesta(const char *pchrPtrCampo,
						  const char *pchrPtrAsociado,
						  SiscomOperaciones *pSiscomOpePtrDato);
void SiscomAsignaFechaHoraAsociadoEntrada(const char *pchrPtrAsociado,
					  const char *pchrPtrCampo,
					  SiscomOperaciones *pSiscomOpePtrDato);

void SiscomAsignaFechaAsociadoEntrada(const char *pchrPtrAsociado,
					  const char *pchrPtrCampo,
					  SiscomOperaciones *pSiscomOpePtrDato);

void SiscomAsignaFechaAsociadoAsociadoEntrada(const char *pchrPtrAsociado,
					      const char *pchrPtrAsociado1,
					      const char *pchrPtrCampoFecha,
					      SiscomOperaciones *pSiscomOperaciones);


void SiscomFechaAsociadosCampoEntrada(const char *pchrPtrCampo,
				      const char *pchrPtrAsociado,
				      const char *pchrPtrCampoFecha,
				      SiscomOperaciones *pSiscomOpPtrDatos);

void SiscomRegistrosAlCampoAsociadoRespuesta(const char *pchrPtrAsociado,
					     const char *pchrPtrCampo,
				     const SiscomRegistroProL *pSisRegProLPtrDatoPrim,
				     const SiscomRegistroProL *pSisRegProLPtrDatoAct,
				     SiscomOperaciones *pSiscomOpPtrDatos);

void SiscomRegistrosAlCampoEntrada(const char *pchrPtrCampo,
				     const SiscomRegistroProL *pSisRegProLPtrDatoPrim,
				     const SiscomRegistroProL *pSisRegProLPtrDatoAct,
				     SiscomOperaciones *pSiscomOpPtrDatos);


int SiscomEnviaAsociadoRespuestaCliente(const char *pchrPtrAsociado,
				char *pchrPtrBuffer,
				SiscomOperaciones *pSiscomOpPtrDatos);

int SiscomEnviaAsociadoEntradaCliente(const char *pchrPtrAsociado,
				char *pchrPtrBuffer,
				SiscomOperaciones *pSiscomOpPtrDatos);

int SiscomEnviaRegistrosRespuesta(SiscomOperaciones *pSiscomOpePtrDatos,char *pchrPtrBuffer);
int SiscomEnviaRegistrosEntrada(SiscomOperaciones *pSiscomOpePtrDatos,char *pchrPtrBuffer);

int SiscomFormaEnviaRegistroRespuesta(SiscomOperaciones *pSiscomOpePtrDatos,
				 char *pchrPtrBuffer,
				 const char *pchrPtrFormato,
				 ...);
void SiscomCambiaAMayusculasCampoAsociadoEntrada(const char *pchrPtrAsociado,
					  const char *pchrPtrCampo,
					  SiscomOperaciones *pSiscomOpePtrDatos);

int SiscomComparaCampoAsociadoEntradaCadena(const char *pchrPtrAsociado,
					     const char *pchrPtrCampo,
					     const char *pchrPtrCadena,
					     SiscomOperaciones *pSiscomOpePtrDatos);
int SiscomComparaCamposAsociadoEntrada(const char *pchrPtrAsociado,
					     const char *pchrPtrCampo1,
					     const char *pchrPtrCampo2,
					     SiscomOperaciones *pSiscomOpePtrDatos);

int SiscomAnexaRegistroRespuesta(SiscomOperaciones *pSiscomOpePtrDatos);
int SiscomAnexaRegistroEntrada(SiscomOperaciones *pSiscomOpePtrDatos);
int SiscomActualizaCampoRespuesta(const char *pchrPtrCampo,
				  char *pchrPtrDato,
				  SiscomOperaciones *pSiscomOpePtrDatos);

int SiscomActualizaCampoEntrada(const char *pchrPtrCampo,
				  char *pchrPtrDato,
				  SiscomOperaciones *pSiscomOpePtrDatos);

int SiscomActualizaCampoRespuestaFloat(const char *pchrPtrCampo,
				 	const char *pchrPtrFormato,
					float pfltValor,
				  SiscomOperaciones *pSiscomOpePtrDatos);

int SiscomActualizaCampoEntradaFloat(const char *pchrPtrCampo,
				     const char *pchrPtrFormato,
				     float pfltValor,
				  SiscomOperaciones *pSiscomOpePtrDatos);
int SiscomEstaElCampoAsociado(const char *pchrPtrAsociado,
			      const char *pchrPtrCampo,
			      SiscomOperaciones *pSiscomOpePtrDatos);
int SiscomNoRegistrosAsociado(const char *pchrPtrAsociado,				
				      const char *pchrPtrCampo,
				      SiscomOperaciones *pSiscomOpePtrDato);
int SiscomMultiplicaCamposACampoEntrada(const char *pchrPtrAsociado,
				 const char *pchrPtrCampoA,
				 const char *pchrPtrCampoB,
				 const char *pchrPtrResultado,
				 const char *pchrPtrCadenaFormato,
				 SiscomOperaciones *pSiscomOpePtrDato);
#endif
