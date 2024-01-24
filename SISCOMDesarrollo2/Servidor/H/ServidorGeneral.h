#ifndef __SERVIDORGENERAL_H__
#define __SERVIDORGENERAL_H__
#include <SiscomDesarrollo2.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <signal.h>
/* Domingo 13 de Marzo 2016
 *  Se agrega un archivo cabecera para 
 *  poner solo la estructura del Ini, ya que
 *  con la integracion con la version 4, 
 *  marca un error de una funcion que se llama
 *  igual en las dos versiones 
 *  ....
 */
#include <SiscomConfiguracionServidor.h>
int IniciaServidorComunicaciones(int);
void ProcesaInformacion(int);
void AsignaDatosArchivoAConfiguracion(SiscomDatosConfiguracion *,
				      StcSiscomConfiguracion *);
void AbreArchivoLog();
void AlmacenaPid(int);
void InstalaManejadorDeSenales();
void IniciaMemoriaComunServidor();
void CargaFuncionesServidor();
extern int errno;

typedef struct ConsultasSvrSiscom2
{
	int (*Consulta)(char **);
	void (*FormaConsulta)(char **,SiscomOperacionesServidor *);
}StcConsultaSvrSiscom2;

typedef struct OperacionesServidorProt2
{
	int(*Consulta)(SiscomOperacionesServidor *);
	void (*EjecutaConsulta)(int,SiscomOperacionesServidor *);

}StcOperacionesServidorProt2;
extern LCamposSiscomPro2 **gLCSiscomPro2Memoria; 
extern int gintTamArregloMemComun;
extern SSiscomOperaciones *gSSiscomOpSistema;
/* Domingo 7 De Julio del 2013 
 * se agrega la variable global que almacenara
 * la direccion ip del cliente que se conecto
 */
extern char gchrArrDirIpCliente[28];
#endif
