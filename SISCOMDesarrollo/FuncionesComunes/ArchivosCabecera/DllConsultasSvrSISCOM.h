#ifndef __DLLCONSULTASSVRSISCOM_H__
#define __DLLCONSULTASSVRSISCOM_H__
#include <EstructurasSISCOM.h>
#include <FuncionesComunes.h>
#include <RNADFuncionesComunes.h>
int DllCLIConectateSVR(PARDEPURACION int ,char *,char *,char *,int );
int DllCLIRealizaConsulta(PARDEPURACION char *);
int DllCLIObtenDatosDelProducto(PARDEPURACION char *,char *,char *,char *,char *);
int DllCLIEsElUltimoRegistro(PARDEPURACION int);
int DllCLIObtenRegistroCompras(PARDEPURACION char *,char *,char *,char *,char *,char *,char *,char *,char *);
int DllCLIObtenRegistrosDeCotizacion(PARDEPURACION char *,char *,char *,char *,char *,char *,char *);		
int DllCLIRecalculaCotizacion(PARDEPURACION char *,char *,char *);
int DllCLIObtenRegistroDeClientes(PARDEPURACION char *,char *,char *);
int DllCLIObtenRegistroEstGananciaNDisp(PARDEPURACION char *,char *,char *);
#endif 
