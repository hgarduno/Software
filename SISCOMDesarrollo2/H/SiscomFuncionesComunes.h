/*! \file SiscomFuncionesComunes.h
 *  \brief SISCOM Electronica.
 *         Archivo desarrolloda por Heli Garduno Esquivel 2007
 *
 *         Archivo que contiene los prototipos de las funciones de 
 *         uso general que se emplean para el desarrollo basados en el 
 *         esquema SISCOM 
 */



#ifndef __SiscomFUNCIONESCOMUNES_H__
#define __SiscomFUNCIONESCOMUNES_H__
#include <stdio.h>
#include <SiscomProtocolo2.h>
#include <SiscomProtocolo2SubRegistros.h>


typedef struct SemanasAnual
{
  char chrArrFechaIni[12];
  char chrArrFechaFin[12];
}StcSiscomSemanasAnual;

typedef struct FechasSemana
{
   char chrArrInicio[12];
   char chrArrFin[12];
   StcSiscomSemanasAnual StcSisSemAnuFechas[7];
}StcFechasSema;

   
extern FILE *gPtrFleArchivoLog; 
/*!< Variable global (extern), que permite 
     escribir los mensajes de error
     a un archivo log, esta variable se declara 
*/

/*! \sa SiscomDatosConfiguracion
 *  \brief Estructura que contiene la informacion del archivo de
 *   	   configuracion para iniciar al servidor de las aplicaciones
 *
 *
 */

typedef struct DatosConfiguracion
{

	const char *chrPtrNmbDato;  
	/*!< Nombre del campo en el archivo de configuracion*/
	const char *chrPtrValorDato;
	/*!< Valor del campo en el archivo de configuracion*/
	int intNumEntradas;
	/*!< Numero de datos en el archivo de configuracion*/
}SiscomDatosConfiguracion;

/*! \sa
 *  \brief Estructura que contiene la informacion para 
 *         realizar operaciones entre los servidores de 
 *         la aplicacion.
 */
typedef struct OperacionesServidor
{



	int intSocket;
	/*!< Socket de conexion con el servidor */
	int intNRegistrosRes;
	/*!< Numero de registros en la respuesta del
	 *   servidor al cliente
	 */
	char *chrPtrEdoConexion;
	/*!< Cadena que contiene el estado de la conexion 
	 *   con el servidor, si esta direccion es nula
	 *   la conexion se realizo con exito, si no, 
	 *   trae el mensaje de error.
	 */
	char *chrPtrOperacionRes;

	/*!< Nombre de la operacion que regresa el servidor */
	
	LCamposSiscomPro2 *LCSiscomPro2; 
	/*!<  Informacion de la respuesta del 
	 *  servidor de acceso a datos
	 */



	LCamposSiscomPro2 *LCSiscomPro2Dat;  

	/*!<
	 * Informacion de entrada de la interfaz
	 * al servidor de reglas del negocio
	 */

	
	int intNRegistros;
	/*!<
	 * Numero de registros que se enviaran al servidor
	 */
	LCamposSiscomPro2 *LCSiscomPro2EPrim;

	/*!< Informacion que se enviara al servidor Primer Registro
	 */
	LCamposSiscomPro2 *LCSiscomPro2EAct;
	/*!< Informacion que se enviara al servidor Registro Actual
	 */
	

	const char *chrPtrComandoSQL;
	/*!<
	 * No se para que es esta variable
	 */

	char chrPtrOperacionServidor[256];
	/*!<
	 * No se para que es esta variable
	 */
	char chrPtrOperacionSQL[256];
	/*!<
	 * No se para que es esta variable
	 */
	int intPtoCom;
	/*!<
	 * Puerto de comunicaciones con el servidor
	 */
	char chrPtrDirIpSvr[25];
	/*!<
	 * Direccion Ip del servidor
	 */

	void (*EjecutaProcesoDespues)(struct OperacionesServidor *);
	/*!<
	 * Direccion de la funcion que se ejecutara despues
	 * de llamar a la funcion que ejecuta la operacion
	 */

	void (*EjecutaProcesoAntes)(struct OperacionesServidor *);
	/*!<
	 * Direcion de la funcion que se ejecutara antes
	 * de llamar a la funcion que ejecuta la operacion
	 */

	void **voidPtrArgumentos;

	/*
	 * Se observo, que en algunas casos, no se debe de ejecutar
	 * la funcion SiscomOperacionesServidores, ya que la informacion
	 * que se enviara....
	 */
	int intEjecutaSiscomOperacionesServidores;


}SiscomOperacionesServidor;
typedef struct ListaGeneral
{
	void *vidInformacion;
	struct ListaGeneral *LGenSig;
}StcListaGeneral;


void SiscomCreaNodoListaGeneral(void *pvidPtrInformacion,
			    void (*SiscomCreaNodoLista)(void *,StcListaGeneral **),	
			    StcListaGeneral **pLLGenPrim,
			    StcListaGeneral **pLLGenActual);

void SiscomOperacionesServidores(SiscomOperacionesServidor *);
void SiscomAnexaComandoSql(const char *,SiscomOperacionesServidor *);
void SiscomIniciaComunicacionesSrv(const char *,
				     int ,
				     SiscomOperacionesServidor *);
void SiscomInformacionOperaciones(const char *,
				  const char *,
				  SiscomOperacionesServidor *);


void SiscomConsultaBaseDeDatos(const char *,
			       const char *,
			       int ,
			       char **,
			       int *,
			       int *,
			       char **,
			       LCamposSiscomPro2 **);
				
			       
int SiscomAnalizaCadenas(const char *,
		   char ,
		   char *,
		   char ***);
void SiscomCopiaOtraCadena(int ,
		     const char *,
		     char ***);

void SiscomEliminaCaracteres(const char *,char *);
void SiscomEliminaCaracter(char ,char *);

void SiscomAnalizaArchivoConfiguracion(const char *,
				       void (*)(SiscomDatosConfiguracion *,void *),
				       void *);
int SiscomLeeLineaArchivo(FILE *,char *);
int SiscomBuscaSubCadena(const char *,const char *,int *,int*);
void SiscomEliminaCadenaDespuesCadena(const char *pchrPtrSubCadena,
				      char *pchrPtrCadena);

const char *SiscomObtenCadenaSeparador(const char *pchrPtrCadena,
						      char pchrSeparador);

const char *SiscomCadenaEntreSeparadores(
				  const char *pchrPtrEntrada,
				  char pchrSepInicio,
				  char pchrSepFin,
				  char *pchrPtrCadena);


void SiscomAsignaDatoConfiguracionINT(SiscomDatosConfiguracion *,
				   const char *,
				   int *);
void SiscomAsignaDatoConfiguracionFLOAT(SiscomDatosConfiguracion *,
				   const char *,
				   float *);
void SiscomAsignaDatoConfiguracionCHAR(SiscomDatosConfiguracion *,
				   const char *,
				   char **);
void SiscomObtenHoraActualChar(char *pchrPtrHora);

void SiscomObtenHoraActual(int *pintPtrHora,
                           int *pintPtrMinuto,
                           int *pintPtrSegundo);

void SiscomObtenFechaHoraActualAAAADDMM(char *pchrPtrFechaConHora);
void SiscomObtenFechaHoyCharAAAADDMM(char *pchrPtrFecha);

int SiscomObtenFechaHoyINT(int *pintPtrDia,
                           int *pintPtrMes,
                           int *pintPtrAno);
void SiscomObtenFechaHoy(char *pchrPtrFecha);
long SiscomObtenNumeroUnico();
void SiscomObtenNumeroUnicoChar(char *);
void SiscomFormaComandosSql(int ,
			    int ,
			    int ,
			    const char *,
			    const char *,
			    const char *,
			    void (*)(int,const char *,const char *,const char *,LCamposSiscomPro2 *,char *),
			    char *,
			    LCamposSiscomPro2 **);
void SiscomObtenDirIpMaquina(const char *,char *);
void SiscomMensajesLog(FILE *,const char *,...);
void SiscomMensajesLog2(const char *,...);
void SiscomMensajesLog2A(const char *,const char *,int,const char *,...);

/*!
 * \fn int SiscomZeller(int anno, int mes, int dia)
 * \brief El algoritmo para obtener el dia de la semana y la presente 
 * rutina se obtuvo de la direccion electronica.
 * http://www.latecladeescape.com/w0/content/view/79/49/
 * En la fecha 2007/05/08 
 * \param anno A;o de la fecha de la que se desea obtener el dia de la semana
 * \param mes Mes de la fecha de la que se desea obtener el dia de la semana
 * \param dia Dia de la fecha de la que se desea obtener el dia de la semana
 */

int SiscomZeller(int,int,int);
int SiscomZeller2(const char *);
const char *SiscomZellerDia(int,int,int);
const char *SiscomZellerFecha(const char *);
int SiscomObtenNumeroSemana(const char *);
/*!
 * \fn long SiscomGregorianoAJuliano(int dia, int mes, int anno)
 * \brief Funcion que se obtuvo de la direccion electronica 
 *        http://www.latecladeescape.com/w0/content/view/98/49/
 *        Esta funcion regresa un numero que representa la fecha
 *        que se pasa como entrada.
 *
 * \param dia Dia de la fecha que se desea obtener en entero
 * \param mes Mes de la fecha que se desea obtener en entero
 * \param anno A;o de la fecha que se desea obtener en entero
 */
long SiscomGregorianoAJuliano(int,int,int);
long SiscomGregorianoAJuliano2(const char *);
/*!
 * \fn void SiscomDescomponFecha(const char *pchrPtrFecha,
 *		       int *pintPtrDia,
 *		       int *pintPtrMes,
 *		       int *pintPtrAno)
 * \brief Funcion que toma como entrada, una cadena con formato de fecha
 *        y regresa, en los parametros de salida, el dia, mes y a;o.
 * \param pchrPtrFecha Cadena que contiene la fecha en formato 
 *        A;o, Mes, Dia
 * \param pintPtrDia Parametro de salida en el cual se copiara el dia
 *        de la fecha de entrada
 * \param pintPtrMes Parametro de salida en el cual se copiara el mes
 *        de la fecha de entrada
 * \param pintPtrAno Parametro de salida en el cual se copiara el a;o
 *        de la fecha de entrada
 */
void SiscomDescomponFecha(const char *,int *,int *,int *);
/*!
 * \fn void SiscomRestaFechas(const char *pchrPtrFecha1,
 * 			      const char *pchrPtrFecha2)
 * 	\brief	Funcion que tomo el argumento \a pchrPtrFecha1
 * 		lo resta del argumento \a pchrPtrFecha2
 * 		y regresa el numero de dias que hay de 
 * 		diferencia entre las dos fechas.
 * 	\param pchrPtrFecha1 Fecha uno
 * 	\param pchrPtrFecha2 Fecha dos
 */
int SiscomRestaFechas(const char *,const char *);

/*! 
 * \fn void SiscomObtenDatosSemana(const char *pchrPtrFecha,
 *			    	    char *pchrPtrFechaInicio,
 *			    	    char *pchrPtrFechaFin)
 *	\brief Funcion que obtiene la fecha en la que inicia una
 *	       semana y la fecha en la que termina la semana, esto
 *	       a partir de una fecha.
 *	\param	pchrPtrFecha Fecha, de la que se desea obtener la semana
 *	\param pchrPtrFechaInicio Parametro de salida Fecha Inicio Semana
 *	\param pchrPtrFechaFin Parametro de salida Fecha Fin Semana
 *
 *	       
 *		
 */

void SiscomObtenDatosSemana(const char *, char *, char *);

/*!
 * \fn  void SiscomJulianoAGregoriano(long jdia,
 *			      char *pchrPtrFecha)
 * \brief Funcion que tranforma un numero entero que representa un dia
 *        a la fecha en el calendario gregoriano
 * \param jdia numero entero que representa el dia
 * \param pchrPtrFecha parametro de salida, en el que 
 *        se copiara la fecha en forma a;o, mes, dia 
 *
 */
void SiscomJulianoAGregoriano(long ,char *);

int SiscomEstaLaFechaEnLaSemana(const char *,const char *,const char *);
void SiscomObtenFechaSemanasDespues(const char *,int ,char *,char *);

void SiscomSiguienteDia(char *pchrPtrFecha,
			char *pchrPtrFechaSigDia);

void SiscomHoraFloatAChar(float pfltHora,
			  char *pchrPtrHora);


void SiscomDescomponHora(const char *pchrPtrHora,
			 int *pintPtrHoras,
			 int *pintPtrMinutos,
			 int *pintPtrSegundos);

void SiscomIncrementaHora(char *pchrPtrHora,
			  char *pchrPtrHoraIncrementada,
			  int pintMinutos);

float SiscomHoraAFloat(const char *pchrPtrHora);


int SiscomVerificaHoraRango(const char *pchrPtrHora,
			    const char *pchrPtrHoraInicio,
			    const char *pchrPtrHoraFin);

void SiscomFechasSemana(int pintAno,
			int pintSemana,
			char *pchrPtrFechaIni,
			char *pchrPtrFechaFin);
void SiscomSemanaInicioA(int pintAno,
			 char *pchrPtrFecha);

long SiscomSemanaInicioAALong(int pintAno);
void SiscomObtenSemanasAnual(int pintAno,StcSiscomSemanasAnual *pStcSemanasAnual);




void SiscomNormalizaNombre(unsigned char *,LCamposSiscomPro2 *,LCamposSiscomPro2 **);

void SiscomObten2CadenasPorSeparador(const char *pchrPtrCadena,
				     char pchrSeparador,
				     char *pchrPtrCadena1,
				     char *pchrPtrCadena2);

/* Funcion que normaliza la razon social de una lista
 * del protocolo, los campos que debe contenrer son:
 * IdEmpresa
 * RazonSocial,
 * 
 * De Salida Regresa un lista del protocolo con los
 * mismos campos, pero con la razon social normalizada
 *
 * Todos los registros de la lista seran normalizados.
 *
 */
void SiscomNormalizaEmpresa(unsigned char *,
			    LCamposSiscomPro2 *,
			    LCamposSiscomPro2 **);


void SiscomConsultaBaseDeDatosSinDatosConexion(const char *,
					       const char *,
					       int ,
					       LCamposSiscomPro2 **,
					       int *);

void SiscomLeeInformacionRespuesta(int,int *,LCamposSiscomPro2 **);
/*!
 * Funcion que permite tomar los registros pLCSiscomPro2Dat y agrupar <br>
 * por pchrPtrNmbCampo, los registros de entrada deben estar ordenados <br>
 * por el campo 
 * 
 * \param[in] pLCSiscomPro2Dat Registros
 * \param[in] pintNRegistroFiltro No De Registros a considerar en el filtro
 * \param[in] pchrPtrNmbCampo Campo por el cual se realiza el filtro
 * \param[out] pintPtrNRegistros No De Registros resultantes
 * \param[out] pLCSiscomPro2DatPrim Registros resultantes
 */
void SiscomAgrupoRegistrosPorCampo(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				   int pintNRegistros,
				   const char *pchrPtrNmbCampo,
				   int pintNRegistroFiltro,
				   int *pintPtrNRegistros,
				   LCamposSiscomPro2 **pLCSiscomPro2DatPrim);
/*!
 * Regresa strcmp(pLCSiscomPro2Dat,pLCSiscomPro2Dat1), del campo pchrPtrNmbCampo.
 * \param[in] pchrPtrNmbCampo Campo que ha comparar
 * \param[in] pLCSiscomPro2Dat Registro 0
 * \param[in[ pLCSiscomPro2Dat1 Registro 1
 */
int SiscomComparaCampoPro2(const char *pchrPtrNmbCampo,
			LCamposSiscomPro2 *pLCSiscomPro2Dat,
			LCamposSiscomPro2 *pLCSiscomPro2Dat1);
/*!
 * Crea una lista pLCSiscomPro2Ord, Ordenada del campo pchrPtrNmbCampo <br>
 * ordenada de menor a mayor.
 * \param[in] pchrPtrNmbCampo Campo por el que se ordenara.
 * \param[in] pLCSiscomPro2Dat Datos a ordenar
 * \param[in] pintNRegistros Numero de registros a ordenar
 * \param[in] pLCSiscomPro2Ord Lista ordenada
 */
void SiscomOrdenaPorCampo(const char *pchrPtrNmbCampo,
			  LCamposSiscomPro2 *pLCSiscomPro2Dat,
			  int pintNRegistros,
			  LCamposSiscomPro2 **pLCSiscomPro2Ord);

void SiscomEliminaEspaciosFinal(char *pchrPtrCadena);
void SiscomEliminaEspaciosInicio(char *pchrPtrCadena);
void SiscomEnteroACadena(int pintDato,char *pchrPtrSalida);

void SiscomFloatACadena(float pfltDato,
			const char *pchrPtrFormato,
			char *pchrPtrSalida);

void SiscomAjustaImporteAChar(float pfltImpTotal,
		        char *pchrPtrImporteTotal);

void SiscomConsultaBaseDatosSinDatosConexion(const char *pchrPtrConsulta,
					     const char *pchrPtrDirIpSvr,
					     int pintPtoComSvr,
					     LCamposSiscomPro2 **pLCSiscomPro2Reg,
					     int *pintPtrNRegRespuesta);
void SiscomFechaLocal(char *pchrPtrFecha);
#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 95)
#define SiscomLog(...) SiscomMensajesLog2A(__FILE__,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define SiscomLog(...) SiscomMensajesLog2A(__FILE__,__FUNCTION__,__LINE__,##args)
#endif

#endif
