#ifndef __DLLCLIALTASCOMPRAS_H__
#define __DLLCLIALTASCOMPRAS_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
int DllCLIConectateSvrSISCOMAltaCompras(PARDEPURACION int ,char *,char *,char *,int );
int DllCLIAnexaDatosDeCompra(PARDEPURACION char *,char *,char *,char *,char *,char *,char *,char *,char *);
int DllCLIEnviaDatosDeCompraSvr(PARDEPURACION int);
#endif 
