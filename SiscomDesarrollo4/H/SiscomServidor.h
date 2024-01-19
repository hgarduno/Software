#ifndef __SERVIDORSISCOM_H__
#define __SERVIDORSISCOM_H__
#include <SiscomProtocoloComunicaciones.h>
typedef void *(*SiscomGestionEstatica)(
		 int pintSocket,
		 void *pvidPtrAncla,
		 SiscomRegistroProL *pSiscomRegProLPtrPrim,
		 SiscomRegistroProL *pSiscomRegProLPtrAct);
typedef struct SiscomOpGestionEstatica
{
  char chrArrOperacion[56];
  SiscomGestionEstatica gSiscomGestionEstatica;
}SiscomOpGestionEstatica;

int SiscomServidorComunicaciones(int pintPtoCom);
int SiscomIniciaSocketComunicaciones(int pintPtoCom);
void AtiendeCliente(int pintSocket,char *pchrPtrDirIpCliente);
int SiscomEsperaConexionServidor(int pintSocket,char *pchrPtrDirIpCliente);
int ModoOperacionGestionEstatica();
void CargaFuncionesGestionEstatica();

void EjecutaFuncionGestionEstatica(int pintSocket,
				   const char *pchrPtrDirIpCliente);

void AbreArchivoLog();

void AlmacenaPidServidor();
/* Lunes 22 de diciembre del 2014
 * Se agrega la carga de memoria
 */
void CargandoMemoria();
void CargaInformacionMemoria();
void SiscomSIGSEGV(int pintSignal);
void ManejadorSenales();
int CargaArchivoIni(char **pchrPtrArgv);
/* Lunes 14 de Mayo del 2012 
 * Se definen las siguientes variables 
 * para el manejo de los mensajes que se mostraran 
 * en el log, estas variables se consideran de sistema y globales
 *
 */
extern int gintSocketProtocoloLog;
/* Lunes 22 de diciembre del 2014 
 * se agrega el area de memoria donde se almacenara 
 * informacion que el demonio cargara al inicio
 */
extern SiscomRegistroProL *gSiscomRegProLPtrMemoria;

#endif
