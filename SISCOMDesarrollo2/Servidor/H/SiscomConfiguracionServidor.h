#ifndef __SISCOMCONFIGURACIONSERVIDOR_H__
#define __SISCOMCONFIGURACIONSERVIDOR_H__

typedef struct SiscomConServidor
{
	int intPtoCom;
	char *chrPtrLibServidor;
	char *chrPtrFuncionLibServidor;
	char *chrPtrBaseDatos;
	char *chrPtrPtoBD;
	char *chrPtrDirTrabajo;
	char *chrPtrDemonio;
	int intIdProceso;
	char *chrPtrDirIpAccesoDatos;
	int intPtoAccesoDatos;
	char *chrPtrLibMemoriaComun;
	char *chrPtrFuncionMemoriaComun;
	char *chrPtrClienteFrecuente;

	/*
	 * Variables para almacenar los 
	 * Datos del modulo para realizar la impresion
	 */
	char *chrPtrModuloImpresion;
	char *chrPtrFuncionImpresion;

	char *chrPtrHabilitaImpresion;

	/*  Domingo 13 de Marzo 2016 
	 *
	 *  Se agregan los datos del servidor de acceso a datos
	 *  para el demonio de la version 4 
	 */
	char *chrPtrDirIpAccesoDatos4;
	int intPuertoAccesoDatos4;
}StcSiscomConfiguracion;


extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;

#endif
