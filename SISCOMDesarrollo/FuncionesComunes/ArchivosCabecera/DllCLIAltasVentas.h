#ifndef __DLLCLIALTASVENTAS_H__
#define __DLLCLIALTASVENTAS_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>

int DllCLIConectateSvrSISCOMAltaVentas(PARDEPURACION int, char *, char *, char *, int);
int DllCLIAnexaDatosDeVenta(PARDEPURACION  char *,char *, char *, char *, char *, char *, char *, char *);
int DllCLIEnviaDatosDeVentaSvr(PARDEPURACION int);

#endif
