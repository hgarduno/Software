#ifndef __SISCOMMODULOOPERACIONES_H__
#define __SISCOMMODULOOPERACIONES_H__
#include <SiscomProtocolo2.h> 
#include <SiscomProtocolo2SubRegistros.h>
#include <stdio.h>
/*!
 * \file 
 * \brief Funciones comunes para los procesos de operaciones 
 * de acuerdo a la segunda version
 */
typedef struct Operaciones
{
	const char *chrPtrOperacion;
	void (*Operacion)(int,int);
	int intNumOperaciones;

}SSiscomOperaciones;
typedef struct RegistroOperaciones
{
	char chrArrNombre[50];
	int intNumArgumentos;
	int intNumRegistros;
	LCamposSiscomPro2 *LCSiscomPro2Prim;
	LCamposSiscomPro2 *LCSiscomPro2Act;



}SArgumentoOperacion;
/*!
 * \sa
 * \brief Estructura comun para los modulos 
 *
 */
typedef struct ArgOperaciones2
{
	
	/*!
	 * \brief Informacion de entrada, son los datos que el <br>
	 * cliente envia a el servidor
	 */

        LCamposSiscomPro2 *LCSiscomPro2Dat;

	/*
	 * Con la integracion del manejo con subregistros en las operaciones
	 * se agrega el campo donde se almacenara la informacion que se lee
	 * mediante este formato en la estructura de las operaciones
	 * El campo de configuracion se toma del campo ya existente
	 */

	  LCamposSiscomPro2ConSubReg *LCSiscomPro2SREntrada;

	/*!
	 * Se observo en el desarrollo del modulo de cajas del sistema 		<br>
	 * SISCOMElectronica (CorteCaja.c), que informacion requerida para 	<br>
	 * se tiene en el primer registro de la lista que se envia desde el  	<br>
	 * cliente, y otro dato se encuentra al final de la lista, por el 	<br>
	 * concepto de lista simplemente ligada, no se podia acceder al ultimo 	<br>
	 * elemento, por lo que, se agrego este elemento a la estructura, para que<br>
	 * una vez que se lea los datos mediante SiscomLeeEntradaOperaciones2, se <br>
	 * copie en este elemento el ultimo registro que se leyo	
	 */
	LCamposSiscomPro2 *LCSiscomPro2DatUltimo;
	
	/*!
	 * Bloque de informacion correspondiente a los registros de <br>
	 * configuracion que se envian del cliente.<br>
	 */
	LCamposSiscomPro2 *LCSiscomPro2DatConfig;
	/*!
	 * \brief  Con el desarrollo del nuevo soporte, en la <br>
	 *  nueva estructura SArgumentoOperacion, se considerara <br>
	 *  que las estructuras Actual,Prim,SQLInsercion y Argumentos <br>
	 *  ya no  se utilizaran, solo quedaran para la compatibilidad 
	 */
	LCamposSiscomPro2 *LCSiscomPro2Actual;
	LCamposSiscomPro2 *LCSiscomPro2Prim;
	LCamposSiscomPro2 *LCSiscomPro2SQLInsercion;
	LCamposSiscomPro2 *LCSiscomPro2Argumentos;

	/*!
	 * En este elemento de las estructura se colocara la informacion<br>
	 * que se debera regresar al cliente una vez que se complete<br>
	 * el proceso, esta informacion puede ser conformada de dos <br>
	 * fases del proceso:<br>
	 *
	 * 1 En caso de que el proceso haya concluido de manera<br>
	 * correcta o en el caso de que el proceso haya terminado <br>
	 * con un error.<br>
	 *
	 */

	LCamposSiscomPro2 *LCSiscomPro2Regreso;
	LCamposSiscomPro2 *LCSiscomPro2RegAct;

	/*! Variable que se utilizara para almacenar el numero de 
	 * registros que se deberan de enviar al cliente una vez
	 * que el proceso haya concluido.
	 *
	 */

	int intNumRegRegreso;

	/*!
	 * Para simplificar el proceso de evaluacion del estado de 
	 * ejecucion de las funciones, se anexo a esta estructura 
	 * la variable CodigoRetorno, la cual solo podra mantener
	 * el ultimo estado de ejecucion de la funcion.
	 *
	 * En un futuro, se debera buscar que cada una de las 
	 * funciones que se ejecutan, tenga su codigo de retorno
	 *
	 */
	int intCodigoRetorno;
	/*!
	 * Viernes 18 De enero del 2008 Queretaro  <br>
	 * <br>
	 * Se agrega esta variable para manejar el flujo <br>
	 * de la ejecucion en caso de que en una funcion <br>
	 * del arreglo de apuntadores a funciones que  <br>
	 * resolvera la operacion, se detecte un error <br>
	 * <br>
	 * Es importante comentar que el flujo de la  <br>
	 * ejecucion de la operacion se interrumpira <br>
	 * y no se podra ejecutar la funcion siguiente <br>
	 * del proceso si la funcion precedente termino <br>
	 * con error (intCodigoRetorno!=0). <br>
	 *
	 * Para esto la variable SicomError, se debera <br>
	 * iniciar con cada uno de los errores posibles <br>
	 * errores que podran detener el proceso. <br>
	 *
	 * Cada entrada del arreglo representara con el <br>
	 * indice el error que se genero. <br>
	 *
	 * Es decir, la entrada en la posicion 1 referenciara <br>
	 * al error 1 en el proceso de ejecucion, la entrada <br>
	 * 2 referenciara al error 2 del proceso, y asi  <br>
	 * sucesivamente, para identificar el error se  <br>
	 * debera colocar en intCodigoRetorno, el numero  <br>
	 * de error que se genero, y con este indice se <br>
	 * ejecutara el elemento de error adecuado. <br>
	 * <br>
	 *
	 */
	void (*SiscomError[100])(struct ArgOperaciones2 *);

	/*!
	 *  El siguiente apuntador a funcion se debera iniciar 			   <br>
	 *  con la direccion de la rutina que debera obtener los datos 		   <br>
	 *  de comunicacion con el servidor de acceso a datos.		           <br>
	 *  En el proceso de actualizacion del modulo de Sepomex en el             <br>
	 *  servidor, se agregaron las rutinas SepomexEstados, SepomexMunicipios   <br>
	 *  el problema que se observo en la aplicacion del modulo de Sepomex,     <br>
	 *  en la SISCOMElectronica, fue que al cargar las rutinas no se llenaron  <br>
	 *  las variables que almacenan los datos de comunicacion con el servidor  <br>
	 *  de acceso a datos, por tal motivo se agrega esta variable		   <br>
	 *
	 *
	 */

	void (*ComunicacionAccesoDatos)(struct ArgOperaciones2 *);

	SArgumentoOperacion *SArgOperacion;
	int intNRegistrosDat;
	int intNRegistrosRes;
	void **vidPtrArgumentos;
	int intSocketCliente;
	int intSocketAccesoDatos;


	/*! Para realizar el proceso de consulta se agregan 
	 * las siguientes variables
	 *
	 */

	char **chrPtrArgConsulta;

	int intPtoComAD;
	char chrArrDirIpAD[25];

	/* Miercoles 17 de abril del 2013
	 * En las distintas funciones sobre todo del SQL
	 * no se pueden generalizar porque la forma del registro
	 * de entrada es especifico para cada modulo, con esta 
	 * funcion se buscara obtenter el dato particular y 
	 * asi poder obtener el dato de SArgsSiscom 
	 */
	const char *(*Condicion)(struct ArgOperaciones2 *);

	/* Miercoles 17 de abril del 2013 
	 * Para formar una condicion en registro y asi poder 
	 * utilizar varios datos.
	 */
	LCamposSiscomPro2 *(*CondicionRegistro)(struct ArgOperaciones2*);

	/* Miercoles 17 de abril del 2013 
	 * Lo mismo, para generalizar las funciones del SQL
	 * debo poner de forma externa el argumento al que 
	 * se van asignar
	 */
	 
	const char *(*AAlArgumento)(struct ArgOperaciones2 *);


}SArgsSiscom;
typedef struct Operaciones2
{
	const char *chrPtrOperacion;
	void (**SiscomOperaciones2)(SArgsSiscom *);
	int intNumOperaciones;
}SSiscomOperaciones2;
typedef void (*SiscomOperaciones2)(SArgsSiscom *);
void SiscomIniciaOperaciones(int,
			     SSiscomOperaciones **);

void SiscomAnexaOperacion(const char *,
			  void (*Operacion)(int,int),
			  SSiscomOperaciones **);

void SiscomAnexaOperacionesAlFinal(SSiscomOperaciones *,
			    SSiscomOperaciones **);
/*
void SiscomAnexaOperacion2A(const char *pchrPtrOperacion,
			   void (**Operaciones)(SArgsSiscom *),
			   void (*Configuracion)(SArgSiscom *),
			   int ,
			   SSiscomOperaciones2 **pSSOperaciones2);
*/
void SiscomAnexaOperacion2(const char *pchrPtrOperacion,
			   void (**Operaciones)(SArgsSiscom *),
			   SSiscomOperaciones2 **pSSOperaciones2);
SiscomOperaciones2 *SiscomOperaciones2CualEjecuta(const char *pchrPtrOperacion,
					       SSiscomOperaciones2 *pSSOperaciones2,
					       SiscomOperaciones2 pSOperaciones2Error,
					       SArgsSiscom *pSArgsSiscom);
SiscomOperaciones2 *SiscomIniciaMemoriaOperaciones2(int pintNOperaciones);
void SiscomOperaciones2Ejecuta(SiscomOperaciones2 *pSOperaciones2,
			       SArgsSiscom *pSArgsSiscom);

void SiscomLeeEntradaOperaciones2(SArgsSiscom *);
/*!
 * Funcion que permite leer informacion del cliente en dos bloques  <br>
 * el primer bloque esta delimitado por el campo "Configuracion", y el otro <br>
 * son los datos sin ningun analisis del campo, esto permitira enviar desde el <br>
 * 
 */
void SiscomLeeEntradaOperaciones2ConConfiguracion(SArgsSiscom *);
void SiscomCopiaArgumentosConsulta(SArgsSiscom *);
void SiscomCopiaArgumentosConsultaSubRegistros(SArgsSiscom *pSAgsSiscom);
void SiscomAnexaArgumentoConsulta(const char *,SArgsSiscom *);
void SiscomAnexaOperacionAlArreglo(SiscomOperaciones2 pSisOp,
				   SiscomOperaciones2 **pSisOps2);
void SiscomAnexaOperacionAlArreglo2(SiscomOperaciones2 ,SiscomOperaciones2 *);
void SiscomAnexaOperacionAlArreglo21(SiscomOperaciones2 ,SiscomOperaciones2 *,int *);
void SiscomAsignaMemoriaArgumentosOperaciones(int ,SArgsSiscom *);
void SiscomIniciaMemoriaArgumentoOperacion(int,const char *,SArgsSiscom *);
LCamposSiscomPro2 *SiscomArgumentoOperacionPrim(const char *,SArgsSiscom *);
LCamposSiscomPro2 *SiscomArgumentoOperacionAct(const char *,SArgsSiscom *);
int SiscomArgumentosNumeroRegistros(const char *,SArgsSiscom *);
void SiscomAsignaArgumentoOperacionPrim(const char *,LCamposSiscomPro2 *,SArgsSiscom *);
void SiscomAsignaArgumentoOperacionAct(const char *,LCamposSiscomPro2 *,SArgsSiscom *);
void SiscomAsignaArgumentoNumeroRegistros(const char *,int ,SArgsSiscom *);
void SiscomEjecutaRegistroInformacion(SArgsSiscom *,
				      const char *,
				      LCamposSiscomPro2 **,
				      int *);

char *SiscomEjecutaRegistroInformacion2(int pintPtoComAD,
				      const char *pchrPtrDirIpSvrAd,
				      SArgsSiscom *,
				      const char *,
				      LCamposSiscomPro2 **,
				      int *);
void SiscomObtenInformacionArgumento(const char *,
				     SArgsSiscom *,
				     LCamposSiscomPro2 **,
				     LCamposSiscomPro2 **,
				     int *);
void SiscomAsignaInformacionArgumento(const char *,
				      SArgsSiscom *,
				      LCamposSiscomPro2 *,
				      LCamposSiscomPro2 *,
				      int);
const char *SiscomObtenCampoArgumento(const char *pchrPtrArgumento,
				      const char *pchrPtrCampo,
				      SArgsSiscom *pSAgsSiscom);

float SiscomObtenCampoArgumentoFloat2(const char *pchrPtrArgumento,
				      const char *pchrPtrCampo,
				      SArgsSiscom *pSAgsSiscom);
void SiscomPonPrimerRegistroArgumento(const char *pchrPtrArgumento,
				      SArgsSiscom *pSAgsSiscom);
LCamposSiscomPro2 *SiscomSiguienteRegistroArgumento(const char *pchrPtrArgumento,
				      SArgsSiscom *pSAgsSiscom);

float SiscomObtenCampoArgumentoFloat(const char *pchrPtrArgumento,
				      const char *pchrPtrCampo,
				      SArgsSiscom *pSAgsSiscom);

const char *SiscomCampoDatosEntrada(const char *pchrPtrCampo,
				    SArgsSiscom *pSAgsSiscom);

float SiscomCampoDatosEntradaFloat(const char *pchrPtrCampo,
				    SArgsSiscom *pSAgsSiscom);
void SiscomEjecutaConsultaYResponde(SArgsSiscom *,const char *); 

void SiscomGeneraInsercionActualizacion(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumento,
				  void (*GeneraSQL)(LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 **,
				  		    LCamposSiscomPro2 **,
						    int *));

void SiscomGeneraInsercionActualizacionCiclo(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumento,
				  void (*GeneraSQL)(LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 **,
				  		    LCamposSiscomPro2 **,
						    int *));

void SiscomGeneraInsercionActualizacion2(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumento,
				  void (*GeneraSQL)(LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 **,
				  		    LCamposSiscomPro2 **,
						    int *));
void SiscomGeneraInsercionActualizacion2A(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumentoEnt,
				  const char *pchrPtrArgumentoSal,
				  void (*GeneraSQL)(LCamposSiscomPro2 *,
				  		    LCamposSiscomPro2 **,
				  		    LCamposSiscomPro2 **,
						    int *));

void SiscomGeneraInsercionActualizacionReCorreArgEntrada(SArgsSiscom *pSAgsSiscom,
				  const char *pchrPtrArgumentoEnt,
				  const char *pchrPtrArgumentoSal,
				  char *pchrPtrBufferSql,
				  void (*GeneraSQL)(SArgsSiscom *,
				  		    LCamposSiscomPro2 *,
						    char *));

/*!
 * Toma el argumento pchrPtrArgumento de SArgsSiscom lo envia <br>
 * al Servidor, y regresa la respuesta al cliente en 
 * pSAgsSiscom->LCSiscomPro2Dat
 *
 * \param[in] SArgsSiscom *pSAgsSiscom Estructura comun 
 * \param[in] const char *pchrPtrArgumento Nombre del argumento a enviar
 *
 */
void SiscomEnviaServidorArgumento(SArgsSiscom *pSAgsSiscom,const char *pchrPtrArgumento);
void SiscomMemoriaOperaciones2(int ,SiscomOperaciones2 **);
void SiscomGeneraIdRegistro(SArgsSiscom *,const char *);
/*!
 * \brief Ejecuta una consulta al servidor de Accesso A datos <br>
 * tomando la informacion de comunicaciones de pSAgsSiscom, de tal forma <br>
 * que en el servidor de AD se ejecutara la consulta pchrPtrSql <br>
 * el numero de registros en la consulta se almacenaran en pintPtrNRegRespuesta<br>
 * los registros de la consulta se almacenaran en pLSiscomPro2Reg
 * \param[in] pchrPtrSql Consulta a ejecutar
 * \param[in] pSAgsSiscom Informacion general del proceso de consulta. 
 * \param[out] pintPtrNRegRespuesta Numero de registros en la consulta
 * \param[out] pLCSiscomPro2Reg Resultado de la consulta
 */
void SiscomConsultaBaseSinEnvio(const char *pchrPtrSql,
				SArgsSiscom *pSAgsSiscom,
				int *pintPtrNRegRespuesta,
				LCamposSiscomPro2 **pLCSiscomPro2Reg);

/*!
 * \brief Ejecuta una consulta al servidor de Accesso A datos <br>
 * tomando la informacion de comunicaciones de pSAgsSiscom, de tal forma <br>
 * que en el servidor de AD se ejecutara la consulta pchrPtrSql <br>
 * el numero de registros en la consulta se almacenaran en pSAgsSiscom->intNumRegRegreso <br>
 * los registros de la consulta se almacenaran en pSAgsSiscom->LCSiscomPro2Regreso 
 * \param[in] pchrPtrSql Consulta a ejecutar
 * \param[in] pSAgsSiscom Informacion general del proceso de consulta. 
 */
void SiscomConsultaBaseSinEnvio2(const char *pchrPtrSql,
				SArgsSiscom *pSAgsSiscom);

/*!
 *
 */
void SiscomConsultaBaseDatos2(const char *pchrPtrBase,
			      const char *pchrPtrPuertoBD,
			      const char *pchrPtrSql,
			      SArgsSiscom *pSAgsSiscom);

/*!
 *Toma los pSAgsSiscom->LCSiscomPro2Regreso y el numero de registros pSAgsSiscom->intNumRegRegreso <br>
 *los envia por el socket de la conexion actual
 */

void SiscomEnviaRegreso(SArgsSiscom *pSAgsSiscom);
void SiscomEnviaRegreso2(SArgsSiscom *pSAgsSiscom,const char *pchrPtrRespuesta);
/*!
 * Ejecuta la consulta pchrPtrSql al servidor de acceso a datos <br>
 * pSAgsSiscom->intPtoComAD y pSAgsSiscom->chrArrDirIpAD, copia el <br>
 * resultado en el argumento pchrPtrArgumento de pSAgsSiscom
 * \param[in] pchrPtrArgumento Nombre del argumento donde se almacenara el resultado
 * \param[in] pchrPtrSql, sentencia Sql
 * \param[in] pSAgsSiscom Argumentos para el proceso en el servidor
 */
int SiscomConsultaBaseAsignaArgumento(const char *pchrPtrArgumento,
				       const char *pchrPtrSql,
				       SArgsSiscom *pSAgsSiscom);
/*!
 * Agrega un registro al campo LCSiscomPro2Regreso de pSAgsSiscom  <br>
 * (Observarcion) .  Una modificacion que se debera hacer a todas  <br>
 * las funciones que trabajan con los campos de regreso, tiene que <br>
 * ver con el hecho de poder poder pasar el tipo de dato (igual que <br>
 * en el sprintf, ya que al momento de pasar un dato que es float o int <br>
 * se tiene que hacer la conversion a char por fuera, para despues pasar <br>
 * el argumento al tipo de dato.
 * El formato podria ser el siguiente:
 *
 * "Campo1%.2f,Campo2%d,Campo3%s" ...
 *
 */
void SiscomAnexaRegistroRegreso(SArgsSiscom *,const char *,...);
/*!
 * Busca el argumento pchrPtrArgumento en pSAgsSiscom, y agrega el registro<br>
 * que se especifica, en pchrPtrRegistros.
 */
void SiscomAnexaRegistroArgumento(const char *pchrPtrArgumento,
				  SArgsSiscom *,
				  const char *,...);


void SiscomAnexaRegistroRegreso2(SArgsSiscom *pSAgsSiscom,
				 LCamposSiscomPro2 *pLCSiscomPro2Dat);

void SiscomAsignaEdoRegistroEnvio(LCamposSiscomPro2 *pLCSiscomPro2Resp,
					LCamposSiscomPro2 *pLCSiscomPro2Dat);
void SiscomEnviaArgumentoCliente(const char *pchrPtrArgumento,
				 SArgsSiscom *);

void SiscomEnviaArgumentosCliente(SArgsSiscom *pSAgsSiscom);

void SiscomEnviaArgumentosPorNombreParaRegistro(char *pchrPtrArgumentos[],
						SArgsSiscom *pSAgsSiscom);
void SiscomEnviaArgumentosParaRegistro(SArgsSiscom *pSAgsSiscom);
void SiscomEnviaArgumentoParaRegistro(const char *pchrPtrArgumento,SArgsSiscom *pSAgsSiscom);
void SiscomCopiaArgumentosAArgumento(const char *pchrPtrArgSalida,
				     int pintNArgumentosACopiar,
				     SArgsSiscom *pSAgsSiscom);
void SiscomLeeEntradaOpSubRegistros(SArgsSiscom *pSAgsSiscom);
/*
 * Jueves 07 De Abril 2011 
 * Esta funcion debera de escribirse ya que puede resultar muy util
 * poder agregar el resultado de otra consulta SQL a un argumento,
 * en este punto ya esta claro que es posible mezclar los registros
 * que pueden ser con estructuras diferentes solo hay que saber la 
 * el numero de registro para poder acceder al campo
 *
 *
void SiscomEjecutaConsultaAgregaArgumento(const char *pchrPtrArgumento,
					  const char *pchrPtrSql,
					  SArgsSiscom *pSAgsSiscom);

*/
int SiscomRegistrosTotalesEnArgumentos(SArgsSiscom *pSAgsSiscom);
void SiscomRegistrosTAAsignaRegreso(SArgsSiscom *pSAgsSiscom);
/*!
 * Sabado 30 Abril 2011
 * Hay que cambiar esta macro, desarrollando una funcion
 * que imprima el contenido del argumento, pero que tome 
 * como argumentos el Archivo, la funcion y la linea 
 * despuesta se invocara esta funcion desde la macro
 */

const char *SiscomCadenaInsercionSql(SArgsSiscom *pSAgsSiscom,const char *pchrPtrFormato,...);

void AsignaEstadoInsercion(LCamposSiscomPro2 *pLCSiscomPro2SQL,
			   LCamposSiscomPro2 *pLCSiscomPro2RegSQL);
#define SiscomImprimeArgumento(pchrPtrArgumento,pSAgsSiscom)				\
{											\
	LCamposSiscomPro2 *lLCSiscomPro2;						\
	lLCSiscomPro2=SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom);	\
	SiscomContenidoProtocolo(lLCSiscomPro2);					\
}
#define SiscomImprimeArgumentosConsulta(pSAgsSiscom)					\
{											\
int lintContador=0;									\
while(pSAgsSiscom->chrPtrArgConsulta[lintContador])					\
{											\
   SiscomLog("%d.-%s",lintContador,pSAgsSiscom->chrPtrArgConsulta[lintContador]);	\
   lintContador++;									\
}											\
}

extern FILE *gPtrFleArchivoLog;
#endif
