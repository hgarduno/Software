#ifndef __FUNCIONESCOMUNES_H__
#define __FUNCIONESCOMUNES_H__


/*!
	\file FuncionesComunes.h
	\brief Funciones comunes para el entorno de desarrollo

*/
#include <EstructurasSISCOM.h>
#include <OpcionesDepuracion.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROTSISCOMCNSMOVIMIENTO 0
#define PROTSISCOMCNSUSUARIO    1
#define PROTSISCOMCNSPASSWORD   2
#define PROTSISCOMDIRIPSVR	3
#define PROTSISCOMPTOSVR	4

#define PROTSISCOMCNSDLLCNSSVR  5
#define PROTSISCOMCNSFNCDLLCNS  6
#define PROTSISCOMCNSMODCONSULTA 7
#define PROTSISCOMCNSFNCMODCONSULTA 8
#define PROTSISCOMCNSTXTIDCONSULTA  9


#define PROTSISCOMNUMCAMPOS	10




typedef struct LtaStcRegComSISCOM
{
	char **chrPtrRegistro;
	int iNumCampos;
	struct LtaStcRegComSISCOM *LSRCSISCOMPtrSig;
	struct LtaStcRegComSISCOM *LSRCSISCOMPtrAnt;
}StcLtaRegComSISCOM;


typedef struct StcCreaConsultas
{
const char *chrPtrNmbConsulta;
   void (*EjecutaCreaConsulta)(char **,
                               StcLtaRegComSISCOM *,
                               StcLtaRegComSISCOM **,
                               int *,
                               char *);

}StcCreaConsultasSISCOM;

typedef struct StcCreaConsultas2
{
const char *chrPtrNmbConsulta;
   void (*EjecutaCreaConsulta)(int,
			       const char *,
				char **,
                               StcLtaRegComSISCOM *,
                               StcLtaRegComSISCOM **,
                               int *,
                               char *);
	void (*EjecutaFormateo)(int,
			       const char *,
				char **,
                               StcLtaRegComSISCOM *,
                               StcLtaRegComSISCOM **,
                               int *);


}StcCreaConsultasSISCOM2;





typedef struct DRegistroAValidar
{
	int intArrConInfo[50];
	int intArrSinInfo[50];
}StcDRegistroAValidar;
typedef struct OperacionesAlSistemaSISCOM
{

        int (*EsOperacion)(char **,char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM **,int *);
        void (*EjecutaOperacionAlSistema)(int,
                                         const char *,
                                         const char *,
                                         StcLtaRegComSISCOM *,
					 int ,
                                         StcLtaRegComSISCOM **,
                                         int *);
        void (*FormaRespuestaOperacion)(int,
                                            const char *,
                                            int,
                                            StcLtaRegComSISCOM *,
                                            StcLtaRegComSISCOM **,
                                            int *);


}StcOperacionesAlSistemaSISCOM;
typedef struct OperacionesAlSistema2SISCOM
{

        int (*EsOperacion)(int,
			   const char *,
			   char **,
			   char *,
			   StcLtaRegComSISCOM *,
			   StcLtaRegComSISCOM **,
			   int *);
        void (*EjecutaOperacionAlSistema)(int,
                                         const char *,
                                         const char *,
                                         StcLtaRegComSISCOM *,
					 int ,
                                         StcLtaRegComSISCOM **,
                                         int *);
        void (*FormaRespuestaOperacion)(int,
                                            const char *,
                                            int,
                                            StcLtaRegComSISCOM *,
                                            StcLtaRegComSISCOM **,
                                            int *);


}StcOperacionesAlSistema2SISCOM;

typedef struct BuscaYEjecutaOperacionSISCOM
{
 const char *chrPtrOperacion; 
        StcLtaRegComSISCOM *(*EjecutaOperacion)(int ,const char *,StcLtaRegComSISCOM *,int *);


}StcBuscaYEjecutaOperacionSISCOM;


int SISCOMObtenDiaDeLaSemana();

void SISCOMSeleccionaYEjecutaOperacionAlSistema(int,
                                       const char *,
                                       StcOperacionesAlSistemaSISCOM *,
                                       int,
                                       StcLtaRegComSISCOM *,
                                       StcLtaRegComSISCOM **,
                                       int *);
void SISCOMSeleccionaYEjecutaOperacionAlSistema2(int,
                                       const char *,
                                       StcOperacionesAlSistema2SISCOM *,
                                       int,
                                       StcLtaRegComSISCOM *,
                                       StcLtaRegComSISCOM **,
                                       int *);

void SISCOMCopiaACharCharDeComunicaciones(StcLtaRegComSISCOM *,int ,char ***);
void SISCOMCopiaACharCharDeComunicaciones2(int ,StcLtaRegComSISCOM **,char ***);
void SISCOMAnexaRegistroFormateandoParaEnvio(StcLtaRegComSISCOM **,
			       StcLtaRegComSISCOM **,
			       int *,
			       char *,
			       const char *,...);

int SISCOMEsRegistroVacio(char **);
void SISCOMImprimeContenidoRegistro(char **,const char *);
int SISCOMValidaRegistro(char **,StcDRegistroAValidar );

int SISCOMEjecutaConsultaSvrSiscomYEnviaAlClienteConRespuestaConstruida(
		                   int ,
				   int ,
				   const char *,
				   const char *,
				   const char *,
				   const char *,
				   const char *,
				   StcLtaRegComSISCOM *(*FormaConsultas)(int,const char *,StcLtaRegComSISCOM *,int *),
				   StcLtaRegComSISCOM *(ConstruyeRespuesta)(int,const char *,StcLtaRegComSISCOM *,StcLtaRegComSISCOM *,int *));


void SISCOMObtenRangoDeFechas(const char *,char *,char *);
void SISCOMObtenFechaHoraActualAAAADDMM(char *);
void SISCOMObtenHoraActual(int *, int *, int *);
void SISCOMObtenHoraActualChar(char *);
void SISCOMObtenFechaHoyCharAAAADDMM(char *);



char *SISCOMNumeroACadena(float );
char *SISCOMNumeroACadenaLong(long );
void SISCOMLiberaCharChar2(const char **);
void SISCOMPonFechaEntradaEnFormato(const  char *,const char *,const char *,char *);
void SISCOMCopiaOtraCadena(int ,const char *,char ***);
int SISCOMAnalizaCadenas(const char *,char,char *,char ***);
int SISCOMEnviaYRecibeCadenasAD(int ,
				const char *,
				const char *,
				const char *,
				const char *,
				const char *,
				int *,
				StcLtaRegComSISCOM **,
				const char *,
				...);

int SISCOMEjecutaConsultaSvrSiscomYEnviaAlClienteSinEnvioAD(int ,
							    int ,
							    const char *,
							    StcLtaRegComSISCOM *(*EjecutaOperacion)(int ,
												    const char *,
												    StcLtaRegComSISCOM *,
												    int *));
							    

int SISCOMEjecutaConsultaSvrSiscomYEnviaAlCliente(int ,
				   int ,
				   const char *,
				   const char *,
				   const char *,
				   const char *,
				   const char *,
				   StcLtaRegComSISCOM *(*FormaConsultas)(StcLtaRegComSISCOM *,int *));
int SISCOMEjecutaConsultaSvrSiscomYEnviaAlCliente2(int ,
				   int ,
				   const char *,
				   const char *,
				   const char *,
				   const char *,
				   const char *,
				   StcLtaRegComSISCOM *(*FormaConsultas)(int,const char *,StcLtaRegComSISCOM *,int *));


long SISCOMObtenNumeroUnico();
void SISCOMEnviaInformacionAlSvrAD(int,
				   const char *,
				   const char *,
				   const char *,
				   const char *,
				   const char *,
				   int,
				   StcLtaRegComSISCOM *,
				   StcLtaRegComSISCOM **,
				   int *);
void SISCOMImprimeContenidoCom(FILE *,char ,char ,StcLtaRegComSISCOM *);
void SISCOMImprimeContenidoCom2(FILE *,char *,char ,char ,StcLtaRegComSISCOM *);

void SISCOMImprimeContenidoCom3(const char *pchrPtrArchivo,
			      const char *pchrPtrNmbFuncion,
			      int pintNLinea,
			      char pchrSepCampo,
			      char pchrSepLinea,
			      StcLtaRegComSISCOM *pSLRCSisDat);

void SISCOMFormaDatosProtocoloInfoUsuario(char *,char *,char ***);
void SISCOMFormaDatosProtocoloInfoServidor(int ,char *,char *,char *,char ***);
void SISCOMFormaDatosProtocoloInfoModuloCNS(char *,char *,char *,char ***);
int SISCOMEjecutaConsultaSvrReglasDelNegocio(char **,char *,int *);
int SISCOMObtenDatoDinamicoProtocolo(int ,char **,int *);
int SISCOMObtenTamanoBufferCadEnvio(char **,int *);
int SISCOMFormaCadenaEnvioDinamica(char **,int ,char **);
int SISCOMEnviaRespuestaAlCliente(int,StcLtaRegComSISCOM *,int);


int SISCOMAnexaRegistroEnvio(char **,StcLtaRegComSISCOM **,StcLtaRegComSISCOM **);
int SISCOMEnviaInfAlServidor(char **,int ,StcLtaRegComSISCOM *,int *);
void SISCOMAnexaRegistroLEnvio(StcLtaRegComSISCOM **,StcLtaRegComSISCOM **,int , const char *pchrPtrFormato,...);
void SISCOMCreaListaRegCom(char **,StcLtaRegComSISCOM **,StcLtaRegComSISCOM **);
void SISCOMObtenRespuestaSVR(int ,int *,int *, StcLtaRegComSISCOM **);



int SISCOMConectateServidor(PARDEPURACION int ,char *,int *,STRUCTError *);
int SISCOMObtenNombreDelBinario(PARDEPURACION char *,char *);
int SISCOMLeeDatos(PARDEPURACION int,int,char *,int);
int SISCOMCargaDllYBuscaFuncion(PARDEPURACION char *,char *,void **);
int SISCOMFormaDatosProtocoloCHAR(PARDEPURACION char *,int,int ,int *,char *);
int SISCOMFormaDatosProtocoloINT(PARDEPURACION int,int,int *,char *);
int SISCOMFormaDatosProtocoloFLOAT(PARDEPURACION float,int,int *,char *);
int SISCOMFormaDatosProtocoloLONG(PARDEPURACION long ,int,int *,char *);
int SISCOMObtenDatoProtocoloCHAR(PARDEPURACION int,char *,int *);
int SISCOMObtenInformacionDelProtocolo(PARDEPURACION int ,int *,int *,char ****,STRUCTError *);
int SISCOMCreaSegmentoSHM(PARDEPURACION unsigned long ,unsigned long,unsigned long *,void **,STRUCTError *);
int SISCOMAsignaMemoriaARGS(PARDEPURACION int,int ,char ***);
int SISCOMImprimeFuncionYArgumentos(char *,char *,...);
int SISCOMLiberaCharPtr(PARDEPURACION int,int,char ***);
int SISCOMAsignaMemoriaDatos(PARDEPURACION STRUCTDatos *,int);
int SISCOMFormaCadenaDeEnvioDeDatos(PARDEPURACION STRUCTDatos *);
int SISCOMObtenFecha(PARDEPURACION char *);
int SISCOMValidaSoloNumeros(PARDEPURACION char *,char *);
int SISCOMConcatenaSiEsNecesario(PARDEPURACION char *,char *);
int SISCOMObtenSHMSvrReplicacion(void **);
void SISCOMCambiaMayusculas(char *);
void SISCOMBuscaCaracter(char *,char ,int *,int *);
void SISCOMEliminaSubCadena(char *,char *,char *);
void SISCOMCadenaSinCadena(char *,char *,char *);
void SISCOMCambiaExtension(char *,char *,char *,char *);
int SISCOMObtenFechaHoyINT(int *,int *,int *);

/* Jueves 4 Julio 2019 
 * Agrego algunas funciones para poder depuerar y 
 * arreglar el programa de Seguridad3
 */

void SiscomMuestraCadenas(const char *pchrPtrArchivo,
			  const char *pchrPtrFuncion,
			  int pintNoLinea,
			  char **pchrPtrCadenas);

#if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 95)
#define SISCOMMensajesDepuracion(...) 						\
         printf("(%s %s %d) ",__FILE__,__FUNCTION__,__LINE__); 	\
         printf(__VA_ARGS__);						\
	 printf("\n");
#else
#define SISCOMMensajesDepuracion(...) 						\
         printf("(%s) (%s) (%d) ",__FILE__,__FUNCTION__,__LINE__); 	\
         printf(##args);						\
	 printf("\n");
#endif



int SiscomEscribeSocket(const char *pchrPtrArchivo,
			const char *pchrPtrFuncion,
			int pintNLinea,
			int pintSocket,
			const char *pchrPtrCadena,
			int pintTamano);

int SiscomLeeSocket(const char *pchrPtrArchivo,
			const char *pchrPtrFuncion,
			int pintNLinea,
			int pintSocket,
			const char *pchrPtrCadena,
			int pintTamano);
int RNBuscaMovimientos(PARDEPURACION STRUCTProcesosYDll *pSTRUCTProcesosYDllLis,int pintDato,STRUCTProcesosYDll *pSTRUCTProcesosYDllReg,STRUCTError *pSTRUCTErrorPtrReg);

int SISCOMQuitaEspacios(PARDEPURACION char *pchrPtrCadena);
#define Write(pintSocket,pchrPtrConsulta,pintTamano)						\
	SiscomEscribeSocket(__FILE__,__FUNCTION__,__LINE__,pintSocket,pchrPtrConsulta,pintTamano);


#define Read(pintSocket,pchrPtrConsulta,pintTamano)						\
	SiscomLeeSocket(__FILE__,__FUNCTION__,__LINE__,pintSocket,pchrPtrConsulta,pintTamano);

#define SiscomImprimeContenidoCom(pchrSepCampo,pchrSepLinea,pSLRCSisDat)			\
	SISCOMImprimeContenidoCom3(__FILE__,__FUNCTION__,__LINE__,pchrSepCampo,pchrSepLinea,pSLRCSisDat);

#define LOGCadenas(pchrPtrCadenas) 		\
	SiscomMuestraCadenas(__FILE__,__FUNCTION__,__LINE__,pchrPtrCadenas)
#endif 
